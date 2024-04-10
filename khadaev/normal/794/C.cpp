#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int n = s.length();
    vector<char> a(n), b(n);
    forn(i, 0, n) a[i] = s[i];
    forn(i, 0, n) b[i] = t[i];
    sort(all(a));
    sort(all(b));
    reverse(all(b));
    vector<char> ans(n);
    int sta = 0, stb = 0, fina = (n + 1) / 2 - 1, finb = n / 2 - 1;
    int st = 0, fin = n - 1;
    while (st <= fin) {
        /*cerr << st << ' ' << fin << '\n';
        cerr << sta << ' ' << fina << '\n';
        cerr << stb << ' ' << finb << '\n';*/
        if (a[sta] < b[stb]) {
            ans[st] = a[sta];
            ++st;
            ++sta;
        } else {
            ans[fin] = a[fina];
            --fin;
            --fina;
        }
       /* cerr << st << ' ' << fin << '\n';
        cerr << sta << ' ' << fina << '\n';
        cerr << stb << ' ' << finb << '\n';*/
        if (st > fin) break;
        if (sta == fina + 1 || b[stb] > a[sta]) {
            ans[st] = b[stb];
            ++st;
            ++stb;
        } else {
            ans[fin] = b[finb];
            --fin;
            --finb;
        }
    }
    forn(i, 0, n) putchar(ans[i]);
}