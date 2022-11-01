#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
const int mod = 1000000007;
const int maxn = 200500;

int add(int x, int y) { return (x+y)%mod; }
int mul(int x, int y) { return (i64)x*y%mod; }

int p[maxn], in[maxn], nxt[maxn];
void compp(const string& s, int m) {
    for (int i = 1; i < (int)s.length(); ++i) {
        p[i] = p[i-1];
        while (p[i] && s[i] != s[p[i]]) {
            p[i] = p[p[i]-1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
        if (p[i] == m) {
            in[i - m - 1 - (m - 1)] = 1;
        }
    }
}
int d[maxn], sd[maxn];

int n, m;
string s, t;

void solve() {
    cin >> s >> t;
    n = s.length();
    m = t.length();
    compp(t + "#" + s, m);
    int lp = n + 1;
    ford(i, n) {
        if (in[i]) {
            lp = i;
        }
        nxt[i] = lp;
    }

    int res = 0;
    d[0] = 1;
    int t = 0;
    forn(i, n+1) {
        t = add(t, sd[i]);
        d[i] = add(d[i], t);
        if (i == n) break;
        d[i+1] = add(d[i+1], d[i]);
        int nr = nxt[i] + m;
        sd[nr] = add(sd[nr], d[i]);
    }
    res = d[n];
    cout << add(res, mod-1) << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}