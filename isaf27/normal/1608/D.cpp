#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
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
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9) + 239;
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
const int B = 2000;
const int X = 35;

int my_sum(int a, int b) {
    a += b - MOD;
    a += (a >> 31) & MOD;
    return a;
}

int my_sub(int a, int b) {
    a -= b;
    a += (a >> 31) & MOD;
    return a;
}

int my_mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int power(int a, int k) {
    if (k == 0) {
        return 1;
    }
    int t = power(a, k / 2);
    t = my_mul(t, t);
    if (k & 1) {
        t = my_mul(t, a);
    }
    return t;
}

int fact(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = my_mul(ans, i);
    }
    return ans;
}

int getC(int n, int k) {
    return my_mul(fact(n), my_mul(power(fact(k), MOD - 2), power(fact(n - k), MOD - 2)));
}

string s[M];
int n;

bool can(const string& a, const string& b) {
    for (int i = 0; i < 2; i++) {
        if (a[i] != '?' && a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    bool ch = true;
    for (int i = 0; i < n && ch; i++) {
        ch &= can(s[i], "BW");
    }
    ans += ch;
    ch = true;
    for (int i = 0; i < n && ch; i++) {
        ch &= can(s[i], "WB");
    }
    ans += ch;
    int ml = 1;
    for (int i = 0; i < n; i++) {
        ml = my_mul(ml, can(s[i], "WB") + can(s[i], "BW"));
    }
    ans = my_sub(ans, ml);
    int x_deg = 0;
    int xp1_deg = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int t = 0; t < 2; t++) {
            if (s[i][t] == '?') {
                cnt++;
            }
        }
        if (cnt == 0) {
            if (s[i] == "WW") {
                x_deg += 2;
            } else if (s[i] != "BB") {
                x_deg += 1;
            }
            continue;
        }
        if (cnt == 1) {
            if (s[i][0] == 'W' || s[i][1] == 'W') {
                xp1_deg += 1;
                x_deg += 1;
            } else {
                xp1_deg += 1;
            }
        } else {
            xp1_deg += 2;
        }
    }
    int req = n - x_deg;
    if (req >= 0 && req <= xp1_deg) {
        ans = my_sum(ans, getC(xp1_deg, req));
    }
    cout << ans << "\n";
    return 0;
}