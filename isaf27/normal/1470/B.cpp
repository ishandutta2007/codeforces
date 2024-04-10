//#pragma GCC optimize("O3")
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
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 1e6 + 239;

ll hs1[X], hs2[X];
int mn[X];

pair<ll, ll> read() {
    int x;
    cin >> x;
    ll h1 = 0;
    ll h2 = 0;
    while (mn[x] != -1) {
        int p = mn[x];
        while (x % p == 0) {
            h1 ^= hs1[p];
            h2 ^= hs2[p];
            x /= p;
        }
    }
    return make_pair(h1, h2);
}

int n;
pair<ll, ll> a[M];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    map<pair<ll, ll>, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    int ans0 = 0;
    for (const auto& t : cnt) {
        ans0 = max(ans0, t.second);
    }
    int ans1 = 0;
    int sum1 = 0;
    for (const auto& t : cnt) {
        if (t.first == make_pair(0LL, 0LL)) {
            sum1 += t.second;
            continue;
        }
        if (t.second & 1) {
            ans1 = max(ans1, t.second);
        } else {
            sum1 += t.second;
        }
    }
    ans1 = max(ans1, sum1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll w;
        cin >> w;
        if (w == 0) {
            cout << ans0 << "\n";
        } else {
            cout << ans1 << "\n";
        }
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < X; i++) {
        hs1[i] = rnd();
        hs2[i] = rnd();
        mn[i] = -1;
    }
    for (int i = 2; i < X; i++) {
        if (mn[i] == -1) {
            mn[i] = i;
            for (int j = i + i; j < X; j += i) {
                if (mn[j] == -1) {
                    mn[j] = i;
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}