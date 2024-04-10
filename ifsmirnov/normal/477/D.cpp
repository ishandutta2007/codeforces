#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstring>
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
const int maxn = 5010;
const int mod = 1000000007;

int add(int x, int y) {
    return (x+y)%mod;
}

string add(string a, string b) {
//     cout << "add " << a << " " << b << " = ";
    reverse(all(a));
    reverse(all(b));
    string c(max(a.length(), b.length()) + 1, '0');
    int cr = 0;
    forn(i, c.length()) {
        if (i < (int)a.length()) cr += a[i]-'0';
        if (i < (int)b.length()) cr += b[i]-'0';
        c[i] = cr%2+'0';
        cr /= 2;
    }
    assert(cr == 0);
    int z = 0;
    ford(i, c.length()) {
        if (c[i] == '0') ++z;
        else break;
    }
    c.resize(c.length() - z);
    reverse(all(c));
//     cout << c << endl;
    return c;
}

string bin(int x) {
    string s;
//     cout << "bin " << x << " = ";
    while (x) {
        s += '0'+x%2;
        x /= 2;
    }
    reverse(all(s));
//     cout << s << endl;
    return s;
}

string mymin(const string& s, const string& t) {
    if (s.empty()) return t;
    if (s.length() == t.length()) return s<t?s:t;
    return s.length()<t.length()?s:t;
}

int eval(const string& s) {
    int x = 0;
    forn(i, s.length()) {
        x = x*2 + s[i]-'0';
        x %= mod;
    }
//     cout << "eval " << s << " = " << x << endl;
    return x;
}

void compz(char *s, int n, int *z) {
    int l = 0, r = 0;
    fore(i, 1, n-1) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
}

int n;
char s[maxn];
int z[maxn][maxn];
int mn[maxn][maxn], d[maxn][maxn];

void scan() {
    scanf("%s", s);
    n = strlen(s);
//     n = 5000;
//     forn(i, n) s[i] = '1';
    forn(i, n) {
        compz(s+i, n-i, z[i]+i);
    }
}

int next_num_pos(int l, int r) {
    // [l, r)
    int len = r-l;
    int r1 = r + len;
    if (r1 > n) {
        return -1;
    }
    if (s[r] == '0') {
        return -1;
    }
    int zf = z[l][r];
    if (zf >= len || s[r+zf] > s[l+zf]) {
        return r1;
    } else if (r1 == n) {
        return -1;
    } else {
        return r1 + 1;
    }
}

void solve() {
    forn(i, n+1) forn(j, n+1) mn[i][j] = inf;
    mn[0][1] = 1;
    d[0][1] = 1;
    forn(i, n) fore(j, i+1, n) {
        if (mn[i][j] == inf) {
            continue;
        }
//         cout << i << " " << j << ": " << d[i][j] << endl;
        int np = next_num_pos(i, j);
//         cout << "np = " << np << endl;
        if (np != -1) {
            mn[j][np] = min(mn[j][np], mn[i][j] + 1);
            d[j][np] = add(d[j][np], d[i][j]);
        }

        if (j != n) {
            mn[i][j+1] = min(mn[i][j+1], mn[i][j]);
            d[i][j+1] = add(d[i][j+1], d[i][j]);
        }
    }

    int sumd = 0;
    forn(i, n) {
        sumd = add(sumd, d[i][n]);
    }

    string best = "";
    int lft = 30;
    ford(i, n) if (mn[i][n] != inf) {
        if (!--lft) break;
        best = mymin(best, add(string(s+i, s+n), bin(mn[i][n])));
    }

    cout << sumd << endl;
    cout << eval(best) << endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}