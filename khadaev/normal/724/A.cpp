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

int num (string s) {
    if (s[0] == 'm') return 0;
    if (s[0] == 't') {
        if (s[1] == 'u') return 1;
        return 3;
    }
    if (s[0] == 'w') return 2;
    if (s[0] == 'f') return 4;
    if (s[1] == 'a') return 5;
    return 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> len = {28, 30, 31};
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = num(s1), n2 = num(s2);
    for (int i : len) if ((n1 + i) % 7 == n2 % 7) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;

}