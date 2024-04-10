#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const ld eps = 1e-8;
const ll INF = (ll)(2e18) + 239;
const int BIG = (int)(1e9) + (int)(239); // (int)(2e9) + (int)(1e6)
const int MOD = 998'244'353;
const ll MOD2 = (ll)MOD * (ll)MOD;

namespace math {
    inline int sum(int a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void add(int& a, int b) {
        a += b - MOD;
        a += (a >> 31) & MOD;
    }

    inline int sub(int a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
        return a;
    }

    inline void make_sub(int& a, int b) {
        a -= b;
        a += (a >> 31) & MOD;
    }

    inline int mul(int a, int b) {
        return (ll)a * (ll)b % (ll)MOD;
    }

    inline int power(int a, int k) {
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

    inline int inv(int a) {
        return power(a, MOD - 2);
    }

    inline int div(int a, int b) {
        return mul(a, inv(b));
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
const int X = 200;

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
#ifdef ONPC
    s = "";
    for (int i = 0; i < n; i++) {
        s += (char)('0' + (rnd() % 2));
    }
#endif
    int l = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << 0 << "\n";
        return 0;
    }

    s = s.substr(l, (int)s.size() - l);
    n = (int)s.size();

    string ans = s;
    for (int p = 1; p < min(50, n); p++) {
        char xa = '0', xc = '0';
        for (int i = 0; i < n; i++) {
            char cur;
            if (i < p) {
                cur = s[i];
            } else {
                cur = ((s[i] == '0' && s[i - p] == '0') ? '0' : '1');
            }
            if (cur != ans[i]) {
                xa = ans[i];
                xc = cur;
                break;
            }
        }
        if (xc > xa) {
            cerr << p << "\n";
            for (int i = 0; i < n; i++) {
                if (i < p) {
                    ans[i] = s[i];
                } else {
                    ans[i] = ((s[i] == '0' && s[i - p] == '0') ? '0' : '1');
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}