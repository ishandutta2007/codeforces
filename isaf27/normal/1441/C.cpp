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
const int BIG = (int)(1e9 + 239);
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
const int X = 3010;

vector<ll> v[X];
int n, k;
ll ans;

void func(int l, int r, vector<ll> w) {
    if (r - l == 1) {
        for (int i = 0; i < v[l].size(); i++)
            if (w[k - i] != -INF)
                ans = max(ans, w[k - i] + v[l][i]);
        return;
    }
    int mid = (l + r) / 2;
    vector<ll> w_go = w;
    for (int i = l; i < mid; i++)
        for (int j = k - (int)v[i].size() + 1; j >= 0; j--)
            if (w_go[j] != -INF)
                w_go[j + (int)v[i].size() - 1] = max(w_go[j + (int)v[i].size() - 1], w_go[j] + v[i].back());
    func(mid, r, w_go);
    w_go = w;
    for (int i = mid; i < r; i++)
        for (int j = k - (int)v[i].size() + 1; j >= 0; j--)
            if (w_go[j] != -INF)
                w_go[j + (int)v[i].size() - 1] = max(w_go[j + (int)v[i].size() - 1], w_go[j] + v[i].back());
    func(l, mid, w_go);
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v[i].resize(t + 1);
        v[i][0] = 0;
        for (int j = 0; j < t; j++) {
            ll x;
            cin >> x;
            v[i][j + 1] = v[i][j] + x;
        }
        if (t >= k) {
            v[i].resize(k + 1);
        }
    }
    vector<ll> w(k + 1, -INF);
    w[0] = 0;
    ans = 0;
    func(0, n, w);
    cout << ans << "\n";
    return 0;
}