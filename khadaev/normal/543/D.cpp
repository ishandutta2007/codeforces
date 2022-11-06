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

const int N = 2e5 + 10;
vector<int> ch[N];
int p[N];
ll ansDown[N];
vector<ll> lft[N], rgt[N];
ll ansUp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    p[0] = -1;
    forn(i, 1, n) {
        cin >> p[i];
        --p[i];
        ch[p[i]].eb(i);
    }
    ford(i, 0, n) {
        int sz = ch[i].size();
        lft[i].resize(sz + 1);
        rgt[i].resize(sz + 1);
        lft[i][0] = 1;
        forn(j, 0, sz)
            lft[i][j + 1] = lft[i][j] * (1 + ansDown[ch[i][j]]) % MOD;
        rgt[i][sz] = 1;
        ford(j, 0, sz)
            rgt[i][j] = rgt[i][j + 1] * (1 + ansDown[ch[i][j]]) % MOD;
        ansDown[i] = rgt[i][0];
    }
    ansUp[0] = 0;
    forn(i, 0, n) {
        int sz = ch[i].size();
        forn(j, 0, sz) {
            int u = ch[i][j];
            ansUp[u] = lft[i][j] * rgt[i][j + 1] % MOD * (ansUp[i] + 1) % MOD;
        }
    }
    forn(i, 0, n)
        cout << (1 + ansUp[i]) * ansDown[i] % MOD << ' ';
}