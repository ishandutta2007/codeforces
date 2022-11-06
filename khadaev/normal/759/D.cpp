
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

const int N = 5001;
ll ans[N][N];
const int SZ = 26;
int nxt[N][SZ];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    //n = 5000;
    string s;
    cin >> s;
    //forn(i, 0, n) s += ('a' + i % 26);
    vector<int> t;
    forn(i, 0, n) {
        if (i == 0 || s[i] != s[i - 1]) t.eb(s[i] - 'a');
    }
    int k = t.size();
    vector<int> fst(SZ, -1), last(SZ, -1);
    forn(i, 0, k) forn(j, 0, SZ) nxt[i][j] = -1;
    forn(i, 0, k) {
        if (last[t[i]] == -1) {
            fst[t[i]] = i;
            forn(j, 0, i) nxt[j][t[i]] = i;
        } else {
            forn(j, last[t[i]], i) nxt[j][t[i]] = i;
        }
        last[t[i]] = i;
    }
    forn(i, 0, SZ) if (fst[i] != -1) ans[0][fst[i]] = 1;
    forn(i, 0, n - 1) {
        forn(j, 0, k) {
            ans[i][j] %= MOD;
            forn(let, 0, SZ) {
                if (let == t[j]) continue;
                if (nxt[j][let] == -1) continue;
                //cerr << "OK\n";
                int q = nxt[j][let];
                ans[i + 1][q] += ans[i][j];
                //if (ans[i + 1][q] >= MOD) ans[i + 1][q] -= MOD; 
            }
            ans[i + 1][j] += ans[i][j];
            //if (ans[i + 1][j] >= MOD) ans[i + 1][j] -= MOD;
        }
    }
    //forn(i, 0, n) forn(j, 0, k) cerr << i << ' ' << j << ' ' << ans[i][j] << '\n';
    ll Ans = 0;
    forn(j, 0, k) {
        Ans += ans[n - 1][j] % MOD;
    }
    cout << Ans % MOD << '\n';
}