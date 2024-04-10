//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int two = 2;
const ld eps = 1e-10;
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 1e4 + 239;

int n, k, a[M], b[M], p[M];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
    }
    set<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        q.insert(make_pair(i, a[i]));
    set<int> bq(b, b + k);
    int ans = 1;
    for (int i = 0; i < k; i++) {
        bq.erase(b[i]);
        auto it = q.find(make_pair(p[b[i]], b[i]));
        int cnt = 0;
        if (it != q.begin() && bq.count(prev(it)->second) == 0)
            cnt++;
        if (next(it) != q.end() && bq.count(next(it)->second) == 0)
            cnt++;
        if (cnt == 0) {
            cout << "0\n";
            return;
        }
        q.erase(it);
        if (cnt == 2) {
            ans = (ans + ans) % MOD;
        }
    }
    cout << ans << "\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}