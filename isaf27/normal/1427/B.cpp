/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
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
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 13) + 239;
const int B = 510;
const int X = 60;

int n, k;
string s;

void solve() {
    cin >> n >> k >> s;
    int len = 0;
    char cur = s[0];
    int begin = -1;
    int end = -1;
    vector<int> lens;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cur == s[i]) {
            len++;
            continue;
        }
        if (cur == 'L') {
            if (len == i) {
                begin = len;
            } else {
                lens.emplace_back(len);
            }
        } else {
            ans += 2 * len - 1;
        }
        cur = s[i];
        len = 1;
    }
    if (cur == 'L') {
        if (len == n && k > 0) {
            cout << 2 * min(k, n) - 1 << "\n";
            return;
        } else {
            end = len;
        }
    } else {
        ans += 2 * len - 1;
    }
    if (k == 0) {
        cout << ans << "\n";
        return;
    }
    sort(lens.begin(), lens.end());
    for (int i : lens) {
        if (k > 0) {
            int cnt = min(k, i);
            if (cnt == i) {
                ans += 2 * i + 1;
                k -= i;
                continue;
            }
            ans += 2 * k;
            k = 0;
            break;
        }
    }
    if (k > 0 && end != -1) {
        int cur = min(k, end);
        ans += 2 * cur;
        k -= cur;
    }
    if (k > 0 && begin != -1) {
        int cur = min(k, begin);
        ans += 2 * cur;
        k -= cur;
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}