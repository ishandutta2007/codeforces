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

void print(vector<int> a) {
    if (a == vector<int>(1, -1)) {
        printf("-1\n");
    } else {
        printf("%d\n", (int)a.size());
        for (int i = 0; i < (int)a.size(); i++) {
            if (i) printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
}

vector<int> solve(string a, string b) {
    auto oa = a;
    auto ob = b;
    int n = a.length();

    auto analyze = [&](string s) {
        vector<int> cnt(3);
        for (int i = 0; i < n; i += 2) {
            int c = 0;
            c += s[i] == '1';
            c += s[i + 1] == '1';
            cnt[c]++;
        }
        return cnt;
    };
    if (analyze(a) != analyze(b)) return vector<int>(1, -1);

    vector<int> ans;
    vector<int> rans;

    while (a != b) {
        int n = a.length();
        int j;

        j = -1;
        for (int i = 0; i < n; i += 2) {
            if (a[i] == b[n - 2] && a[i + 1] == b[n - 1]) {
                j = i;
                break;
            }
        }
        if (j != -1) {
            ans.push_back(j + 2);
            reverse(a.begin(), a.begin() + (j + 2));
            ans.push_back(n);
            reverse(a.begin(), a.begin() + n);
            assert(a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]);
            a.resize(n - 2);
            b.resize(n - 2);
            continue;
        }
        if (a[0] != a[1]) {
            ans.push_back(n);
            reverse(a.begin(), a.begin() + n);
            assert(a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]);
            a.resize(n - 2);
            b.resize(n - 2);
            continue;
        }


        j = -1;
        for (int i = 0; i < n; i += 2) {
            if (b[i] == a[n - 2] && b[i + 1] == a[n - 1]) {
                j = i;
                break;
            }
        }
        if (j != -1) {
            rans.push_back(j + 2);
            reverse(b.begin(), b.begin() + (j + 2));
            rans.push_back(n);
            reverse(b.begin(), b.begin() + n);
            assert(a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]);
            a.resize(n - 2);
            b.resize(n - 2);
            continue;
        }
        if (b[0] != b[1]) {
            rans.push_back(n);
            reverse(b.begin(), b.begin() + n);
            assert(a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]);
            a.resize(n - 2);
            b.resize(n - 2);
            continue;
        }

        assert(a[0] == a[1]);
        assert(b[0] == b[1]);
        if (a[0] == b[0]) {
            ans.push_back(n);
            reverse(a.begin(), a.begin() + n);
            rans.push_back(n);
            reverse(b.begin(), b.begin() + n);
            assert(a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]);
            a.resize(n - 2);
            b.resize(n - 2);
            continue;
        }

        ans.push_back(n);
        reverse(a.begin(), a.begin() + n);
    }
    while (!rans.empty()) {
        ans.push_back(rans.back());
        rans.pop_back();
    }

    a = oa;
    b = ob;
    string aa = a;
    assert((int)ans.size() <= n + 1);
    for (auto x : ans) {
        assert(x % 2 == 0);
        reverse(aa.begin(), aa.begin() + x);
    }
    assert(aa == b);

    return ans;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
      string a, b;
      cin >> a >> b;

      print(solve(a, b));
  }

  return 0;
}