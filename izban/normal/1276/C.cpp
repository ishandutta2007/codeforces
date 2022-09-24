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
#include <numeric>
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

void solve(vector<int> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    auto v = a;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto &x : a) x = lower_bound(v.begin(), v.end(), x) - v.begin();
    int m = v.size();

    vector<int> cnt(m);
    for (int x : a) cnt[x]++;

    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return cnt[i] < cnt[j];
    });

    int csum = 0;
    int ccol = 0;

    int ans = 0;
    int h = 0, w = 0;
    for (int mn = 1; mn * mn <= n; mn++) {
        while (ccol < m && cnt[p[ccol]] <= mn) {
            csum += cnt[p[ccol++]];
        }
        int act_sum = csum + (m - ccol) * mn;

        int mx = act_sum / mn;
        if (ans < mn * mx && mx >= mn) {
            ans = mn * mx;
            h = mn;
            w = mx;
        }
    }

    vector<vector<int>> b(h, vector<int>(w, -1));

    vector<pair<int, int>> c;
    for (int i = 0; i < h * w; i++) {
        int per = h / __gcd(h, w) * w;
        int x = i % h;
        int y = (i + i / per) % w;
        c.push_back({x, y});
    }
    assert(c.size() == h * w);

    reverse(p.begin(), p.end());
    for (int i = 0; i < m; i++) cnt[i] = min(cnt[i], h);
    ccol = 0;
    for (auto o : c) {
        while (ccol < m && cnt[p[ccol]] == 0) ccol++;
        assert(ccol < m);
        cnt[p[ccol]]--;
        b[o.first][o.second] = v[p[ccol]];
    }

//    db2(h, w);
//    for (auto bb : b) {
//        dbv(bb);
//    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            assert(b[i][j] != -1);
        }
    }
    for (int i = 0; i < h; i++) {
        vector<int> vv;
        vv = b[i];
        sort(vv.begin(), vv.end());
        for (int t = 1; t < (int)vv.size(); t++) assert(vv[t] != vv[t - 1]);
    }
    for (int j = 0; j < w; j++) {
        vector<int> vv;
        for (int i = 0; i < h; i++) vv.push_back(b[i][j]);
        sort(vv.begin(), vv.end());
        for (int t = 1; t < (int)vv.size(); t++) assert(vv[t] != vv[t - 1]);
    }

    printf("%d\n%d %d\n", ans, h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d%c", b[i][j], " \n"[j + 1 == w]);
        }
    }
}

void stress() {
    for (int it = 0;; it++) {
        mt19937 rnd(it);
        db(it);

        int n = rnd() % 20 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rnd() % n;

        dbv(a);
        solve(a);
    }
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  stress();

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        solve(a);
    }

  return 0;
}