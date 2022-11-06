#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n) - 1; i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1 << 8;
string e[N], t[N], f[N];

bool cmp(string& lhs, string& rhs) {
    if (rhs.empty()) return true;
    if (lhs.length() != rhs.length())
        return lhs.length() < rhs.length();
    return lhs < rhs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int x = 0b00001111, y = 0b00110011, z = 0b01010101;
    f[x] = "x", f[y] = "y", f[z] = "z";
    int sz = 0;
    while (1) {
        //cerr << ++sz << ' ';
        bool done = true;
        forn(i, 0, N) forn(j, 0, N) if (!e[i].empty() && !t[j].empty()) {
            string s = e[i] + "|" + t[j];
            if (cmp(s, e[i | j])) {
                done = false;
                e[i | j] = s;
            }
        }
        forn(i, 0, N) if (!t[i].empty()) {
            string s = t[i];
            if (cmp(s, e[i])) {
                done = false;
                e[i] = s;
            }
        }
        forn(i, 0, N) forn(j, 0, N) if (!t[i].empty() && !f[j].empty()) {
            string s = t[i] + "&" + f[j];
            if (cmp(s, t[i & j])) {
                done = false;
                t[i & j] = s;
            }
        }
        forn(i, 0, N) if (!f[i].empty()) {
            string s = f[i];
            if (cmp(s, t[i])) {
                done = false;
                t[i] = s;
            }
        }
        forn(i, 0, N) if (!f[i].empty()) {
            string s = "!" + f[i];
            if (cmp(s, f[(N - 1) ^ i])) {
                done = false;
                f[(N - 1) ^ i] = s;
            }
        }
        forn(i, 0, N) if (!e[i].empty()) {
            string s = "(" + e[i] + ")";
            if (cmp(s, f[i])) {
                done = false;
                f[i] = s;
            }
        }
        if (done) break;
    }
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int num = 0;
        for (char c : s) {
            num *= 2;
            if (c != '0') ++num;
        }
        cout << e[num] << '\n';
    }
}