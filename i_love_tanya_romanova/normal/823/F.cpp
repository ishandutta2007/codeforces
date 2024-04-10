#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define F first
#define S second
#define pb push_back
#define sz(a) ((int)(a).size())

using namespace std;

typedef vector<int> vi;


const int N = 1e5 + 10;

vi v[N];

vi cc;
vi vv;


int res[N];
int used[N];


void out(int n)
{
    printf("YES\n");
    forn(i, n) printf("%d%c", res[i], " \n"[i + 1 == n]);
}

int cycle;
int par[N];

void dfs1(int x, int xx = -1)
{
    used[x] = 1;
    par[x] = xx;
    for (int y : v[x])
    {
        if (used[y] && y != xx)
        {
            cycle = 1;
            while (x != y)
            {
                cc.pb(x);
                x = par[x];
            }
            cc.pb(y);
            return;
        }
        if (!used[y]) dfs1(y, x);
        if (cycle) return;
    }
}
int dep[N];

void dfs2(int x, int xx = -1, int d = -1)
{
    used[x] = 1;
    par[x] = xx;
    dep[x] = d;
    if (sz(v[x]) >= 3) vv.pb(x);
    for (int y : v[x]) if (y != xx)
    {
        dfs2(y, x, d + 1);
    }
}

void go(int x, int xx)
{
    vv.pb(x);
    for (int y : v[x])
    {
        if (y != xx) go(y, x);
    }
}

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        forn(i, n) v[i].clear();
        forn(i, m)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            v[x].pb(y);
            v[y].pb(x);
        }
        forn(i, n) used[i] = 0;
        forn(i, n) res[i] = 0;
        cycle = 0;
        cc.clear();
        int found = 0;

        forn(i, n) if (!used[i])
        {
            dfs1(i);
            if (cycle) break;
        }
        
        if (cycle)
        {
            for (int x : cc) res[x] = 1;
            
            out(n);
            found = 1;
            continue;
        }
        forn(x, n) if (sz(v[x]) >= 4)
        {
            res[x] = 2;
            forn(y, 4) res[v[x][y]] = 1;
            out(n);
            found = 1;
            break;
        }
        if (found) continue;

        forn(i, n) used[i] = 0;

        forn(i, n) if (!used[i])
        {
            vv.clear();
            dfs2(i);
            if (sz(vv) >= 2)
            {
                int x = vv[0];
                int y = vv[1];
                int xx = x, yy = y;
                while (xx != yy)
                {
                    if (dep[xx] > dep[yy])
                    {
                        res[xx] = 2;
                        xx = par[xx];
                    }
                    else if (dep[xx] < dep[yy])
                    {
                        res[yy] = 2;
                        yy = par[yy];
                    }
                    else
                    {
                        res[xx] = 2;
                        res[yy] = 2;
                        xx = par[xx];
                        yy = par[yy];
                    }
                }
                res[xx] = 2;

                int cnt = 0;
                for (int z : v[x])
                {
                    if (res[z] == 0)
                    {
                        res[z] = 1;
                        cnt++;
                        if (cnt == 2) break;
                    }
                }

                cnt = 0;
                for (int z : v[y])
                {
                    if (res[z] == 0)
                    {
                        res[z] = 1;
                        cnt++;
                        if (cnt == 2) break;
                    }
                }

                out(n);
                found = 1;
                break;
            }
        }

        if (found) continue;

        /*forn(x, n) if (sz(v[x]) == 3)
        {
            int ok = 1;
            for (int y : v[x])
            {
                if (sz(v[y]) == 1) ok = 0;
            }
            if (ok)
            {
                res[x] = 3;
                for (int y : v[x])
                {
                    res[y] = 2;
                    int z = v[y][0] ^ v[y][1] ^ x;
                    res[z] = 1;
                }
                out(n);
                found = 1;
                break;
            }
        } */

        if (found) continue;

        forn(x, n) if (sz(v[x]) == 3)
        {
            vector<vi> vvv;
            forn(i, 3)
            {
                vv.clear();
                go(v[x][i], x);
                vvv.pb(vv);
            }
            if (sz(vvv[0]) > sz(vvv[1])) swap(vvv[0], vvv[1]);
            if (sz(vvv[0]) > sz(vvv[2])) swap(vvv[0], vvv[2]);
            if (sz(vvv[1]) > sz(vvv[2])) swap(vvv[1], vvv[2]);

            if (sz(vvv[0]) >= 2 && sz(vvv[1]) >= 2 && sz(vvv[2]) >= 2)
            {
                res[x] = 3;
                forn(i, 2) res[vvv[0][i]] = res[vvv[1][i]] = res[vvv[2][i]] = 2 - i;

                out(n);
                found = 1;
                break;
            }
            if (sz(vvv[1]) >= 3 && sz(vvv[2]) >= 3)
            {
                res[x] = 4;
                res[vvv[0][0]] = 2;
                forn(i, 3) res[vvv[1][i]] = res[vvv[2][i]] = 3 - i;

                out(n);
                found = 1;
                break;
            }
            if (sz(vvv[1]) >= 2 && sz(vvv[2]) >= 5)
            {
                res[x] = 6;
                res[vvv[0][0]] = 3;
                res[vvv[1][0]] = 4;
                res[vvv[1][1]] = 2;
                forn(i, 5) res[vvv[2][i]] = 5 - i;

                out(n);
                found = 1;
                break;
            }
        }

        if (found) continue;



        printf("NO\n");
    }



    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}