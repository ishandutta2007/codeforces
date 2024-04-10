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

__int128 read() {
    string s;
    cin >> s;
    __int128 a = 0;
    for (char x : s) {
        a = a * 10LL + (x - '0');
    }
    return a;
}

string to_string(__int128 x) {
    string s = "";
    while (x > 0) {
        s += (char)('0' + (int)(x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

#ifdef ONPC
__int128 __gcd(__int128 x, __int128 y) {
    if (x == 0) {
        return y;
    }
    return __gcd(y % x, x);
}
#endif

__int128 lcm(__int128 x, __int128 y) {
    if (x % y == 0) {
        return x;
    }
    return x * (y / __gcd(x, y));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<__int128> a, b;
    vector<int> id_a, id_b;
    for (int i = 0; i < n; i++) {
        a.emplace_back(read());
        id_a.emplace_back(i);
    }
    for (int i = 0; i < m; i++) {
        b.emplace_back(read());
        id_b.emplace_back(i);
    }
    shuffle(a.begin(), a.end(), rnd);
    shuffle(b.begin(), b.end(), rnd);
    vector<vector<__int128>> v(n, vector<__int128>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = __gcd(a[i], b[j]);
        }
    }
    int it_a = 0;
    int it_b = 0;
    while (a.size() > 0 && b.size() > 0) {
        bool found = false;
        for (int i = it_a; i < a.size() && !found; i++) {
            __int128 x = 1;
            int it = 0;
            for (__int128 y : b) {
                __int128 g = v[id_a[i]][id_b[it++]];
                if (x % g != 0) {
                    x = lcm(x, g);
                }
                if (x == a[i]) {
                    break;
                }
            }
            if (x != a[i]) {
                a.erase(a.begin() + i);
                id_a.erase(id_a.begin() + i);
                found = true;
                it_a = i;
                it_b = 0;
            }
        }
        for (int i = it_b; i < b.size() && !found; i++) {
            __int128 x = 1;
            int it = 0;
            for (__int128 y : a) {
                __int128 g = v[id_a[it++]][id_b[i]];
                if (x % g != 0) {
                    x = lcm(x, g);
                }
                if (x == b[i]) {
                    break;
                }
            }
            if (x != b[i]) {
                b.erase(b.begin() + i);
                id_b.erase(id_b.begin() + i);
                found = true;
                it_b = i;
                it_a = 0;
            }
        }
        if (!found) {
            cout << "YES\n";
            cout << a.size() << " " << b.size() << "\n";
            for (__int128 x : a) {
                cout << to_string(x) << " ";
            }
            cout << "\n";
            for (__int128 y : b) {
                cout << to_string(y) << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //cout << fixed << setprecision(1);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}