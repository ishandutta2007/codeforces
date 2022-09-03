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
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
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
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 110;

int n;
string s;

void solve() {
    cin >> s;
    n = (int)s.size();
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (s[j] - 'a' == i) {
                    swap(s[j], s[0]);
                    sort(s.begin() + 1, s.end());
                    cout << s << "\n";
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == n) {
            cout << s << "\n";
            return;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            if (cnt[i] <= 2 + ((n - 2) / 2)) {
                string t = "";
                t += (char)(i + 'a');
                t += (char)(i + 'a');
                cnt[i] -= 2;
                for (int j = 2; j < n; j++) {
                    for (int x = 0; x < 26; x++) {
                        if (cnt[x] > 0 && (x != i || t[j - 1] - 'a' != i)) {
                            t += (char)(x + 'a');
                            cnt[x]--;
                            break;
                        }
                    }
                }
                cout << t << "\n";
                return;
            }
            break;
        }
    }
    vector<int> vals;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            vals.emplace_back(i);
        }
    }
    int x = vals[0];
    int y = vals[1];
    if (cnt[x] + cnt[y] == n) {
        cout << (char)(x + 'a');
        for (int i = 0; i < cnt[y]; i++) {
            cout << (char)(y + 'a');
        }
        for (int i = 0; i < cnt[x] - 1; i++) {
            cout << (char)(x + 'a');
        }
        cout << "\n";
        return;
    }
    cout << (char)(x + 'a');
    cout << (char)(y + 'a');
    cnt[x]--;
    cnt[y]--;
    cnt[vals[2]]--;
    for (int i = 0; i < cnt[x]; i++) {
        cout << (char)(x + 'a');
    }
    cnt[x] = 0;
    cout << (char)(vals[2] + 'a');
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << (char)('a' + i);
        }
    }
    cout << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}