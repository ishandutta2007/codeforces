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

vector<string> solve(vector<int> a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) assert(a[i] >= a[i + 1]);

    if (n == 0) return vector<string>();
    if (a[0] == 1) {
        for (int x : a) assert(x == 1);
        vector<string> res;
        res.push_back(string(n, '1'));
        return res;
    }
    if (a.back() == n) {
        vector<string> res(n + 1);
        for (int i = 0; i <= n; i++) {
            res[i] = string(n, '1');
            if (i > 0) res[i][i - 1] = '0';
        }
        return res;
    }

    int x = a.back();
    assert(x < n);

    a.pop_back();
    string cur(n - 1, '0');
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == n) {
            a[i]--;
            cur[i] = '1';
        }
    }


    auto res = solve(a);
    int left = x - 1;

    for (int i = 0; i < (int)res.size(); i++) {
        char c = '0';
        if (left > 0 && res[i] != cur) {
            left--;
            c = '1';
        }
        res[i] += c;
    }

    cur += '1';
    res.push_back(cur);
    return res;
}

vector<string> fast(vector<int> a) {
    int n = a.size();

    vector<pair<int, int>> b(n);
    for (int i= 0; i < n; i++) b[i] = {a[i], i};
    sort(b.rbegin(), b.rend());

    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = b[i].first;

    auto s = solve(c);
    vector<string> res;
    for (auto o : s) {
        string t(n, '.');
        for (int j = 0; j < n; j++) {
            t[b[j].second] = o[j];
        }
        res.push_back(t);
    }
    sort(res.begin(), res.end());
//    dbv(res);
    for (int i = 0; i < (int)res.size() - 1; i++) assert(res[i] != res[i + 1]);
//    dbv(a);
//    dbv(res);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < (int)res.size(); j++) {
            cnt += res[j][i] == '1';
        }
//        db2(cnt, a[i]);
        assert(cnt == a[i]);
    }

    return res;
}

void stress() {
    for (int it = 59;; it++) {
        mt19937 rnd(it);
        db(it);
//        int n = rnd() % 10 + 1;
        int n = 1e3;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rnd() % n + 1;

        dbv(a);
        fast(a);
    }
}

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
//  freopen("e.out", "w", stdout);
#endif
//  stress();

  int n;
  while (scanf("%d", &n) == 1) {
      vector<int> a(n);
      for (int i = 0; i < n; i++) scanf("%d", &a[i]);

      auto res = fast(a);
      printf("%d\n", (int)res.size());
      for (auto s : res) printf("%s\n", s.c_str());
  }

  return 0;
}