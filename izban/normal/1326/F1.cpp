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

void print(vector<ll> a) {
    for (int i = 0; i < (int)a.size(); i++) printf("%lld%c", a[i], " \n"[i + 1== (int)a.size()]);
}

vector<ll> solve(vector<vector<int>> a) {
    int n = a.size();

    vector<ll> fct(n + 1);
    fct[0] = 1;
    for (int i = 1; i <= n; i++) fct[i] = fct[i - 1] * i;

    vector<int> vv;
    vector<vector<int>> vct;
    function<void(int, int)>  rec = [&](int left, int cur) {
        if (left < 0 || cur == 0) return;
        if (left == 0) {
            vct.push_back(vv);
            return;
        }
        vv.push_back(cur);
        rec(left - cur, cur);
        vv.pop_back();
        rec(left, cur - 1);
    };
    rec(n, n);

    /*ll sum = 0;
    for (auto v : vct) {
        ll coef = 1;
        coef *= fct[v.size()];
        map<int, int> mp;
        for (int x : v) mp[x]++;
        for (auto it : mp) coef /= fct[it.second];
        sum += coef;
    }
    db(sum);*/

    vector<ll> ans(1 << (n - 1));

    auto get_need = [&](vector<int> v) {
        vector<int> need(n);
        int cur = 0;
        for (int x : v) {
            for (int j = 0; j < x - 1; j++) {
                need[cur] = 1;
                cur++;
            }
            cur++;
        }
        return need;
    };

    for (auto v : vct) {
        auto need = get_need(v);

        vector<vector<ll>> dp(1 << n, vector<ll>(n));
        for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
        for (int mask = 1; mask < (1 << n); mask++) {
            int nom = __builtin_popcount(mask) - 1;
            for (int last = 0; last < n; last++) {
                if (!(mask & (1 << last))) continue;
                for (int nw = 0; nw < n; nw++) {
                    if (mask & (1 << nw)) continue;
                    if (!a[last][nw] && need[nom]) continue;
                    dp[mask | (1 << nw)][nw] += dp[mask][last];
                }
            }
        }
        ll ways = 0;
        for (int i =0; i < n; i++) ways += dp[(1 << n) -1 ][i];

        /*map<int, int> mp;
        for (int x : v) mp[x]++;
        ll coef =1;
        for (auto it : mp) coef *= fct[it.second];
        ways *= coef;*/

        sort(v.begin(), v.end());
        do {
            auto nneed = get_need(v);
            int mask = 0;
            for (int i = 0; i < (n - 1); i++) mask |= nneed[i] << i;
            ans[mask] += ways;
        } while (next_permutation(v.begin(), v.end()));
    }

    for (int k = 1; k < (1 << (n - 1)); k <<= 1) {
        for (int i = 0; i < (1 << (n - 1)); i += 2 * k) {
            for (int j = 0; j < k; j++) {
                ans[i + j] -= ans[i + k + j];
            }
        }
    }

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            a[i].resize(n);
            for (int j= 0; j < n; j++) a[i][j] = s[j] == '1';
        }

        if (n == 18) break;
        print(solve(a));
    }

    return 0;
}