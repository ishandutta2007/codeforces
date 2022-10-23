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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 60;

bool ask(const vector<int>& s) {
    cout << "? " << s.size() << " ";
    for (int i : s) {
        cout << i + 1 << " ";
    }
    cout << endl;
    string ss;
    cin >> ss;
    return (ss == "YES");
}

void check(int x) {
    cout << "! " << x + 1 << endl;
    string ss;
    cin >> ss;
    if (ss == ":)") {
        exit(0);
    }
}

int32_t main() {
#ifdef ONPC
    //freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n);
    iota(s.begin(), s.end(), 0);

    while (s.size() > 3) {
        shuffle(s.begin(), s.end(), rnd);
        vector<int> s1(s.begin(), s.begin() + (s.size() / 2));
        vector<int> s2(s.begin() + (s.size() / 2), s.end());
        vector<int> lie, truth;
        if (ask(s1)) {
            lie = s2;
            s = s1;
        } else {
            lie = s1;
            s = s2;
        }
        s1 = vector<int>(lie.begin(), lie.begin() + (lie.size() / 2));
        s2 = vector<int>(lie.begin() + (lie.size() / 2), lie.end());
        if (ask(s1)) {
            auto cs = s1;
            s1 = vector<int>(s.begin(), s.begin() + (s.size() / 2));
            s2 = vector<int>(s.begin() + (s.size() / 2), s.end());
            s = cs;
            if (ask(s1)) {
                for (int x : s1) {
                    s.emplace_back(x);
                }
            } else {
                for (int x : s2) {
                    s.emplace_back(x);
                }
            }
        } else {
            for (int x : s2) {
                s.emplace_back(x);
            }
        }
    }

    if (s.size() == 1) {
        check(s[0]);
    }
    if (s.size() == 2) {
        check(s[0]);
        check(s[1]);
    }

    while (!ask({s[0]}));
    check(s[0]);
    if (ask({s[1]})) {
        check(s[1]);
    } else {
        check(s[2]);
    }

    return 0;
}