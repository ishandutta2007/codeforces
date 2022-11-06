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

const int S = 62;
const int V = S * S;

int charToInt(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    else if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    else return c - '0' + 2 * 26;
}

vector<int> e[V];
int it[V];

void addString(string s) {
    vector<int> a(3);
    forn(i, 0, 3) a[i] = charToInt(s[i]);
    e[a[0] * S + a[1]].eb(a[1] * S + a[2]);
}

void fail() {
    cout << "NO\n";
    exit(0);
}

void outSym(int x) {
    if (x < 26) cout << char('a' + x);
    else if (x < 2 * 26) cout << char('A' + x - 26);
    else cout << char('0' + x - 2 * 26);
}

void outAll(int x) {
    outSym(x / S);
    outSym(x % S);
}

void outLast(int x) {
    outSym(x % S);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) addString(a[i]);
    int st = -1, fin = -1;
    vector<int> indeg(V), outdeg(V);
    forn(i, 0, V) {
        outdeg[i] = (int)e[i].size();
        for (int j : e[i])
            ++indeg[j];
    }
    forn(i, 0, V) {
        int d = indeg[i] - outdeg[i];
        if (abs(d) > 1) fail();
        if (d == 1) {
            if (fin == -1) fin = i;
            else fail();
        }
        if (d == -1) {
            if (st == -1) st = i;
            else fail();
        }
    }
    if (st == -1) {
        forn(i, 0, V)
            if (indeg[i]) {
                st = fin = i;
                break;
            }
    }
    vector<int> ans, tmp;
    tmp.eb(st);
    while (!tmp.empty()) {
        int v = tmp.back();
        if (it[v] == (int)e[v].size()) {
            ans.eb(v);
            tmp.pop_back();
        } else {
            int u = e[v][it[v]];
            tmp.eb(u);
            ++it[v];
        }
    }
    if ((int)ans.size() != n + 1) fail();
    cout << "YES\n";
    outAll(ans[n]);
    ford(i, 0, n) outLast(ans[i]);
}