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

template<typename T, typename S>
istream& operator>> (istream& in, pair<S, T>& p) {
    in >> p.fs >> p.sn;
    return in;
}
template<typename T, typename S>
ostream& operator<< (ostream& out, pair<S, T>& p) {
    out << p.fs << ' ' << p.sn << ' ';
    return out;
}

template<typename T>
istream& operator>> (istream& in, vector<T>& v) {
    for (T& x : v) in >> x;
    return in;
}
template<typename T>
ostream& operator<< (ostream& out, vector<T>& v) {
    for (T& x : v) out << x << ' ';
    return out;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

void solve(int n, int x1, int x2, bool swapped, vector<pair<int, int>>& c) {
    vector<int> nxt(n + 1);
    nxt.back() = n;
    ford(i, 0, n) {
        if ((x2 + (n - i) - 1) / (n - i) <= c[i].fs)
            nxt[i] = i;
        else
            nxt[i] = nxt[i + 1];
    }
    forn(i, 0, n) {
        int cnt = (x1 + c[i].fs - 1) / c[i].fs;
        if (i + cnt >= n) continue;
        if (nxt[i + cnt] == n) continue;
        cout << "Yes\n";
        vector<int> ans1, ans2;
        forn(j, i, i + cnt)
            ans1.eb(c[j].sn);
        forn(j, nxt[i + cnt], n)
            ans2.eb(c[j].sn);
        if (swapped)
            swap(ans1, ans2);
        cout << ans1.size() << ' ' << ans2.size() << '\n';
        cout << ans1 << '\n' << ans2 << '\n';
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<pair<int, int>> c(n);
    forn(i, 0, n) {
        c[i].sn = i + 1;
        cin >> c[i].fs;
    }
    sort(all(c));
    /*
    for (int i = 1; i < n; ++i) {
        int c1 = (x1 + i - 1) / i;
        int c2 = (x2 + (n - i) - 1) / (n - i);
        if (c1 <= c2) {
            if (c[0].fs >= c1 && c[i].fs >= c2) {
                cout << "Yes\n";
                cout << i << ' ' << n - i << '\n';
                forn(j, 0, i) cout << c[j].sn << ' ';
                cout << '\n';
                forn(j, i, n) cout << c[j].sn << ' ';
                cout << '\n';
                return 0;
            }
        } else {
            if (c[0].fs >= c2 && c[n - i].fs >= c1) {
                cout << "Yes\n";
                cout << i << ' ' << n - i << '\n';
                forn(j, n - i, n) cout << c[j].sn << ' ';
                cout << '\n';
                forn(j, 0, n - i) cout << c[j].sn << ' ';
                cout << '\n';
                return 0;
            }
        }
    }
    */
    solve(n, x1, x2, false, c);
    solve(n, x2, x1, true, c);
    cout << "No\n";
}