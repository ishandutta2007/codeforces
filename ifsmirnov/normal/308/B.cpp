#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
#define le(x, y) ((x)<=(y)+eps)
#define gt(x, y) ((x)>(y)+eps)
#define ge(x, y) ((x)>=(y)-eps)
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9+100500;
const int maxn = 1000500;

int n, r, c;
string s[maxn];
int len[maxn];
int nxt[maxn][21];

void scan()
{
    cin >> n >> r >> c;
    forn(i, n) {
        cin >> s[i];
        len[i] = s[i].length();
    }
}

void findNxt()
{
    int l = 0, r = 0, s = 0;
    for (; l < n; l++) {
        //cout << l << " " << r << ": " << s << endl;
        int add = len[r] + (r != l);
        while (r < n && s + add <= c) {
            s += add;
            ++r;
            add = len[r] + (r != l);
        }
        //cout << l << " " << r << ": " << s << endl;
        //cout << endl;
        nxt[l][0] = r;
        if (l == r) {
            ++r;
        }
        else if (l == r-1) {
            s = 0;
        }
        else {
            s -= len[l] + 1;
        }
    }
    nxt[n][0] = n;
    forn(k, 21) if (k)
        forn(i, n+1) nxt[i][k] = nxt[nxt[i][k-1]][k-1];
}

int getr(int l, int x)
{
    forn(k, 21) if (x&(1<<k))
        l = nxt[l][k];
    return l;
}

void solve()
{
    //forn(i, n) cout << i << " " << getr(i, r) << endl;
    //return;
    pii best = mp(0, 0);
    forn(i, n) {
        int j = getr(i, r);
        best = max(best, mp(j-i, i));
    }
    //cerr << "best = " << best.fi << " " << best.se << endl;

    int i = best.se;
    forn(III, r) {
        int t = nxt[i][0];
        while (i != t) {
            printf("%s%c", s[i].c_str(), " \n"[i == t-1]);
            ++i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    scan();
    findNxt();
    solve();


#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}