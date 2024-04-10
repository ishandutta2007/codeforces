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
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 32;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 3e6 + 239;

int f[L];
vector<tuple<int, int, int>> interesting;
int sum;
int len;
int last_dp;

void add(char x) {
    vector<tuple<int, int, int>> new_interesting;
    new_interesting.emplace_back(len, last_dp, x - '0');
    len++;
    last_dp = math::sub(sum, last_dp);
    int last_fib = x - '0';
    for (auto [i, dp_val, fb] : interesting) {
        if (i + f[fb + 1] > len) {
            new_interesting.emplace_back(i, dp_val, fb);
            continue;
        }
        if (i + f[fb + 1] < len) {
            continue;
        }
        if (last_fib != fb - 1) {
            continue;
        }
        last_fib = fb + 1;
        new_interesting.emplace_back(i, dp_val, fb + 1);
        last_dp = math::sub(last_dp, dp_val);
    }
    sum = math::sum(sum, last_dp);
    swap(interesting, new_interesting);
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < L; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    len = 0;
    sum = 1;
    last_dp = 1;

/*#ifdef ONPC
    add('0');
    add('1');
    string a = "0";
    string b = "1";
    for (int i = 0; i < 30; i++) {
        string c = b + a;
        a = b;
        b = c;
        for (char x : b) {
            add(x);
        }
        if (c.size() < 100) {
            cerr << c << "\n";
        }
        cerr << c.size() << " " << interesting.size() << "\n";
    }
#endif*/

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char x : s) {
            add(x);
        }
        cout << last_dp << "\n";
    }

    return 0;
}