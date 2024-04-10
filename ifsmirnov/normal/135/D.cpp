#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 1010;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vp;
typedef double ld;
const int inf = 1e9+100500;
const ld eps = 1e-9;
typedef long long i64;
#define ok(x, y) ((x)<n&&(y)<m&&(x)>=0&&(y)>=0)
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};


int n, m;
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];


int best = 0;


vp area;
vp marg;
int col = 1;


void bfs (int x, int y, vp& res)
{
        res.clear();
        queue<pii> q;
        b[x][y] = 1;
        q.push(mp(x, y));
        while (!q.empty())
        {
                int cx = q.front().fi, cy = q.front().se;
                q.pop();
                res.pb(mp(cx, cy));
                fore(dx, -1, 1) fore(dy, -1, 1)
                {
                        int tx = cx+dx, ty = cy+dy;
                        if (ok(tx, ty) && !b[tx][ty] && a[tx][ty] == 0)
                                b[tx][ty] = 1, q.push(mp(tx, ty));
                }
        }
        sort(all(res));
}
void getMarg()
{
        marg.clear();
        forn(i, area.size())
        {
                int x = area[i].fi, y = area[i].se;
                fore(dx, -1, 1) fore(dy, -1, 1)
                {
                        int tx = x+dx, ty = y+dy;
                        if (ok(tx, ty) && a[tx][ty] == 1 && c[tx][ty] != col)
                        {
                                marg.pb(mp(tx, ty));
                                c[tx][ty] = col;
                        }
                }
        }
}
int bfs1 (int x, int y)
{
        queue<pii> q;
        b[x][y] = col;
        q.push(mp(x, y));
        int cnt = 0;
        while (!q.empty())
        {
                ++cnt;
                int cx = q.front().fi, cy = q.front().se;
                q.pop();
                forn(i, 4)
                {
                        int tx = cx+dx[i], ty = cy+dy[i];
                        if (ok(tx, ty) && b[tx][ty] != col && c[tx][ty] == col)
                                b[tx][ty] = col, q.push(mp(tx, ty));
                }
        }
        return cnt;
}
void checkSmall()
{
        forn(i, n) forn(j, m)
        {
                if (a[i][j])
                {
                        if (i != n-1 && a[i+1][j])
                        {
                                if (j != m-1 && a[i][j+1] && a[i+1][j+1]) best = max(best, 4);
                        }
                }
        }
}
void solve()
{
        forn(i, n) forn(j, m) if (a[i][j] == 0 && !b[i][j])
        {
                col++;
                bfs(i, j, area);
				bool f = false;
				forn(k, area.size())
				{
					fore(dx, -1, 1) fore(dy, -1, 1)
						if (!ok(area[k].first+dx, area[k].second+dy))
							f = true;
				}
				if (f) continue;
                getMarg();
                if (marg.empty()) continue;
                vi nums;
                //forn(k, marg.size()) nums.pb(get(marg[i]));
                //cout << "col = " << col << endl;
                //forn(i1, n) forn(j1,m) cout << c[i1][j1] << " \n"[j1==m-1];
               
                bool fail = false;
               
                forn(k, marg.size())
                {
                        int x = marg[k].fi, y = marg[k].se;
                        int cnt = 0;
                        forn(t, 4)
                        {
                                int tx = x+dx[t], ty = y+dy[t];
                                if (ok(tx, ty) && c[tx][ty] == col)
                                        cnt++;
                        }
                        if (cnt != 2)
                        {
                                fail = 1;
                                break;
                        }
                }
                if (fail || bfs1(marg[0].fi, marg[0].se) != (int)marg.size())
                        continue;
                //cout << "good cycle, maybe non-connected, v = " << marg.size() << endl;
                best = max(best, (int)marg.size());
        }
       
        cout << best << endl;
}
void scan()
{
        char t[maxn];
       
        scanf("%d%d", &n, &m);
        forn(i, n)
        {
                scanf("%s", t);
                forn(j, m) a[i][j] = (t[j] == '1');
        }
}


int main()
{
        //freopen("input.txt", "r", stdin);
       
        scan();
        checkSmall();
        solve();
       
}