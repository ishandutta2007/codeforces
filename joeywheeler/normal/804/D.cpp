#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

typedef long long ll;
using namespace std;

int n, m, q;
vector<int> u[100005];
bool s[100005];
int td[100005];
int dst[100005];
vector<int> cm;

void go(int i, int p, int d) {
    s[i] = true;
    cm.push_back(i);
    dst[i] = d;
    for (int j : u[i]) if (j != p) {
        go(j, i, d+1);
    }
}

int ci[100005];
vector<int> cl[100005];
vector<ll> cl2[100005];
int nc;

int main() {
    scanf("%d %d %d", &n, &m, &q);
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    FO(i,1,n+1) if (!s[i]) {
        cm.clear();
        go(i,0,0);
        int fn = i;
        for (int x : cm) if (dst[fn] < dst[x]) fn = x;
        cm.clear();
        go(fn,0,0);
        for (int x : cm) td[x] = dst[x];
        fn = i;
        for (int x : cm) if (dst[fn] < dst[x]) fn = x;
        cm.clear();
        go(fn,0,0);
        for (int x : cm) td[x] = max(td[x],dst[x]);

        vector<int> l;
        for (int x : cm) {
            l.push_back(td[x]);
            ci[x] = nc;
        }
        sort(l.begin(), l.end());
        int md = l.back();
        cl[nc].resize(md+2);
        cl2[nc].resize(md+2);
        for (int x : l) {
            cl[nc][x]++;
            cl2[nc][x] += x;
        }
        for (int j = sz(cl[nc])-2; j >= 0; j--) {
            cl[nc][j] += cl[nc][j+1];
            cl2[nc][j] += cl2[nc][j+1];
        }
        nc++;
    }
    map<pair<int,int>, double> cc;
    FO(_,0,q) {
        int x, y; scanf("%d %d", &x, &y);
        x = ci[x]; y = ci[y];

        if (sz(cl[x]) > sz(cl[y])) swap(x,y);
        else if (sz(cl[x]) == sz(cl[y]) && x > y) swap(x,y);

        if (x == y) printf("-1\n");
        else if (cc.count({x,y})) printf("%.10lf\n", cc[{x,y}]);
        else {
            int md0 = max(sz(cl[x])-2, sz(cl[y])-2);
            ll nmls = 0;
            ll smd = 0;
            FO(i,0,sz(cl[x])-1) {
                ll __ = cl[x][i]-cl[x][i+1];
                if (__) {
                    int j = md0-i;
                    j = min(j, sz(cl[y])-1);
                    j = max(j, 0);
                    nmls += __ * cl[y][j];
                    smd += __ * (i+1) * 1ll * cl[y][j];
                    smd += __ * cl2[y][j];
                }
            }
            ll ttp = cl[y].front() * 1ll * cl[x].front();
            smd += (ttp-nmls) * md0;
            double ans = smd / 1. / ttp;
            cc[{x,y}] = ans;
            printf("%.10lf\n", ans);
        }
    }
}