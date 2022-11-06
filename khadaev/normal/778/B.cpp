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

int m;
vector<char> run(string op, vector<char> &a1, vector<char> &a2) {
    vector<char> ans(m);
    if (op == "AND") {
        forn(i, 0, m) ans[i] = a1[i] & a2[i];
    }
    if (op == "OR") {
        forn(i, 0, m) ans[i] = a1[i] | a2[i];
    }
    if (op == "XOR") {
        forn(i, 0, m) ans[i] = a1[i] ^ a2[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n >> m;
    map<string, vector<char>> xs, ys;
    xs["?"] = vector<char> (m, 0);
    ys["?"] = vector<char> (m, 1);
    string bar;
    getline(cin, bar);
    while (n--) {
        string s;
        getline(cin, s);
        string name;
        int i = 0;
        while (s[i] != ' ') {
            name += s[i];
            ++i;
        }
        i += 4;
        string name1;
        while (i < s.length() && s[i] != ' ') {
            name1 += s[i];
            ++i;
        }
        if (i == s.length()) {
            vector<char> a(m);
            forn(j, 0, m) a[j] = name1[j] - '0';
            xs[name] = a;
            ys[name] = a;
        } else {
            ++i;
            string op;
            while (i < s.length() && s[i] != ' ') {
                op += s[i];
                ++i;
            }
            ++i;
            string name2;
            while (i < s.length() && s[i] != ' ') {
                name2 += s[i];
                ++i;
            }

            xs[name] = run(op, xs[name1], xs[name2]);
            ys[name] = run(op, ys[name1], ys[name2]);
        }
    }
    vector<int> xsum(m), ysum(m);
    for (auto p : xs) {
        if (p.first == "?") continue;
        forn(i, 0, m) xsum[i] += p.sn[i];
    }
    for (auto p : ys) {
        if (p.first == "?") continue;
        forn(i, 0, m) ysum[i] += p.sn[i];
    }
    forn(i, 0, m) {
        if (xsum[i] <= ysum[i]) putchar('0');
        else putchar('1');
    }
    putchar('\n');
    forn(i, 0, m) {
        if (xsum[i] >= ysum[i]) putchar('0');
        else putchar('1');
    }
    putchar('\n');
}