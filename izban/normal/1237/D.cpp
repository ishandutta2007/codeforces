#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;


template <typename T, class F = function<T(const T&, const T&)>>
class sparse_table {
public:
    int n;
    vector<vector<T>> mat;
    F func;
    sparse_table(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

vector<int> solve(vector<int> a) {
    int n = a.size();
    if (*min_element(a.begin(), a.end()) * 2 >= *max_element(a.begin(), a.end())) {
        return vector<int>(n, -1);
    }
    for (int i = 0; i < 2 * n; i++) a.push_back(a[i]);

    vector<int> bad(a.size());

    set<pair<int, int>> st;
    st.insert({0, a.size()});
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int can = (a[i] + 1) / 2;
        auto it = st.lower_bound({can - 1, (int)1e9});
        assert(it != st.begin());
        bad[i] = (--it)->second;

        pair<int, int> cur = make_pair(a[i], i);
        while (1) {
            assert(!st.empty());
            auto o = *st.rbegin();
            if (o.first >= cur.first) {
                st.erase(o);
            } else break;
        }
        st.insert(cur);
    }

    auto f = [&](int x, int y) {
        return min(x, y);
    };
    sparse_table<int> s(bad, f);

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int L = 0, R = 2 * n + 1;
        while (R - L > 1) {
            int M = (L + R) >> 1;
            if (s.get(i, i + M - 1) > i + M - 1) {
                L = M;
            } else {
                R = M;
            }
        }
        ans[i] = L;
    }
    return ans;
}

void test() {
    int n = 1e5;
    vector<int> a(n);
    mt19937 rnd;
    for (int i = 0; i < n; i++) a[i] = rnd() % (int)1e9;
    auto ans =solve(a);
    for (int  i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
    exit(0);
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//    test();


  int n;
  while (scanf("%d", &n) == 1) {
      vector<int> a(n);
      for (int i = 0; i < n; i++) scanf("%d", &a[i]);

      auto ans = solve(a);
      for (int  i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i + 1 == n]);
  }

  return 0;
}