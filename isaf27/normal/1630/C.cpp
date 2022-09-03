//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acosl(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + 239;
const int MOD = 998244353; // 1e9 + 7
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    int mul(int a, int b) {
        return 1LL * a * b % MOD;
    }

    int power(int a, int k) {
        int ans = 1;
        int pw = a;
        while (k) {
            if (k & 1) {
                ans = mul(ans, pw);
            }
            pw = mul(pw, pw);
            k >>= 1;
        }
        return ans;
    }
}

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;

int n, a[M], first[M], last[M];

void solve() {

}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(1);

    /*int t;
    cin >> t;
    while (t--) {
        solve();
    }*/

    cin >> n;
    memset(first, -1, sizeof(first));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (first[a[i]] == -1) {
            first[a[i]] = i;
        }
        last[a[i]] = i;
    }
    vector<pair<int, int>> seg;
    for (int i = 0; i < n; i++) {
        if (first[i] != -1 && first[i] < last[i]) {
            seg.emplace_back(first[i], last[i]);
        }
    }
    sort(seg.begin(), seg.end());

    if (seg.empty()) {
        cout << "0\n";
        return 0;
    }

    int ans = n;
    int mx = 0;
    for (const auto& t : seg) {
        mx = max(mx, t.second);
    }
    ans -= (n - 1 - mx);

    //for (const auto& t : seg) {
    //    cerr << t.first + 1 << " " << t.second + 1 << "\n";
    //}

    int rg = 0;
    int i = 0;
    while (i < (int)seg.size()) {
        //cerr << i << "\n";
        //cerr << (seg[i].first - rg) << "+\n";
        ans -= (seg[i].first - rg);
        ans--;
        int j = i + 1;
        while (i < (int)seg.size()) {
        //    cerr << i << " ";
            ans--;
            int best = i;
            while (j < (int)seg.size() && seg[j].first < seg[i].second) {
                if (seg[best].second < seg[j].second) {
                    best = j;
                }
                j++;
            }
            if (best == i) {
                break;
            }
            i = best;
        }
        //cerr << "\n";
        rg = seg[i].second + 1;
        i = j;
    }

    cout << ans << "\n";
    return 0;
}