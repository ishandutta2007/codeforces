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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 1e6 + 239;

int n, a[M];
int pl, mn[M], in[M];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(in, -1, sizeof(in));
    set<pair<int, int>> dp;
    dp.insert(make_pair(1, 0));
    for (int i = 0; i <= n; i++) {
        in[i] = -BIG;
    }
    for (int i = 1; i < n; i++) {
        /*cerr << "________dp__________\n";
        cerr << "i = " << i + 1 << "\n";
        for (const auto& t : dp) {
            cerr << t.first << " " << t.second << "!\n";
        }
        cerr << "pl = " << pl << "\n";
        cerr << "___________________\n";*/
        pair<int, int> to_add;
        if (in[a[i]] == -BIG) {
            to_add = make_pair(dp.begin()->first + pl + 1, a[i - 1]);
        } else {
            int cur = in[a[i]] + pl;
            auto it = dp.begin();
            if (it->second == a[i]) {
                ++it;
            }
            if (it != dp.end()) {
                cur = min(cur, it->first + pl + 1);
            }
            to_add = make_pair(cur, a[i - 1]);
        }
        if (in[to_add.second] == -BIG || to_add.first < in[to_add.second] + pl + (int)(a[i - 1] != a[i])) {
            if (in[to_add.second] != -BIG) {
                dp.erase(make_pair(in[to_add.second], to_add.second));
            }
            to_add.first -= pl + (int)(a[i - 1] != a[i]);
            in[to_add.second] = to_add.first;
            dp.insert(to_add);
        }
        pl += (int)(a[i - 1] != a[i]);
    }
    cout << dp.begin()->first + pl << "\n";
    return 0;
}