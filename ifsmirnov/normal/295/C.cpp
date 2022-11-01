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
const int maxn = 55;

int mod = 1000000007;
inline int add(int x, int y) { return (x+y)%mod; }
inline int mul(int x, int y) { return (i64)x*y%mod; }

int c[maxn][maxn];
void fillc()
{
    c[0][0] = 1;
    fore(n, 1, 51) {
        fore(k, 0, n) {
            c[n][k] = c[n-1][k];
            if (k) c[n][k] = add(c[n-1][k-1], c[n][k]);
        }
    }
}

int n, k;
int w[maxn];
int na, nb;

vector<vi> cur, nxt;
vector<vi> bcur, bnxt;

void scan()
{
    cin >> n >> k;
    k /= 50;
    forn(i, n) {
        cin >> w[i];
        w[i] /= 50;
        if (w[i] == 1) ++na;
        else ++nb;
    }
}


void out(const vector<vi> &a) {
    forn(i, a.size()) {
        forn(j, a[i].size()) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int ans = 0;

void step()
{
    ++ans;
    swap(cur, nxt);
    swap(bcur, bnxt);
    nxt.assign(na+1, vi(nb+1, 0));
    bnxt.assign(na+1, vi(nb+1, 0));

    forn(a, na+1) forn(b, nb+1) if (bcur[a][b]) {
        forn(da, a+1) forn(db, b+1) if (da || db) {
            if (da + db*2 > k) {
                break;
            }
            //cout << "d: " <<  da << " " << db << endl;
            int ta = na - a + da;
            int tb = nb - b + db;
            nxt[ta][tb] = add(nxt[ta][tb], mul(cur[a][b], mul(c[a][da], c[b][db])));
            //cout << cur[a][b] << " " << c[a][na] << " " << c[b][nb] << endl;
            bnxt[ta][tb] = 1;
            //cerr << a << " " << b << endl;
            //cerr << "t: " << ta << " " << tb << endl;
        }
    }

    //out(bnxt);

}
i64 mhash()
{
    i64 h = 123;
    forn(i, bnxt.size())
        forn(j, bnxt[i].size())
            h = h * 10099 + bnxt[i][j];
    return h;
}

void solve()
{
    nxt.assign(na+1, vi(nb+1, 0));
    bnxt.assign(na+1, vi(nb+1, 0));
    nxt[na][nb] = bnxt[na][nb] = 1;
    //out(bnxt);

    step();
    //return;
    i64 lasth = 0;
    while (!bnxt[na][nb]) {
        step();
        step();
        i64 h = mhash();
        if (h == lasth) {
            cout << "-1\n0\n";
            return;
        }
        lasth = h;
    }

    cout << ans << endl << nxt[na][nb] << endl;
}

int main()
{
    fillc();

    //freopen("input.txt", "r", stdin);
    
    scan();
    solve();

#ifdef HOME
    cerr << "time = " << clock()/1000 << " ms" << endl;
#endif
    return 0;
}