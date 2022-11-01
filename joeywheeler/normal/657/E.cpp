#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct bcc {
    vector<vector<int>> u;
    vector<int> bc, lo, ind;
    int T, m, n;

    void init(int n_) {
        n = n_; m = 0; T = 0;
        u.clear(); u.resize(n);
        bc.assign(n,-1);
        lo.assign(n,-1);
        ind.assign(n,-1);
    }

    void adde(int i, int j) {
        u[i].push_back(j);
        u[j].push_back(i);
    }

    vector<int> stk;
    void go(int i, int p) {
        ind[i] = lo[i] = ++T;
        stk.push_back(i);

        for (int j : u[i]) if (j != p) {
            if (ind[j] == -1) {
                go(j, i);
                lo[i] = min(lo[i],lo[j]);
            } else {
                lo[i] = min(lo[i],ind[j]);
            }
        } else p = -1;

        if (ind[i] == lo[i]) {
            int t;
            do {
                t = stk.back(); stk.pop_back();
                bc[t] = m;
            } while (t != i);
            m++;
        }
    }

    void dobcc() {
        FO(i,0,n) if (ind[i] == -1) go(i,-1);
    }
};

int n, m, q;
bcc f;
vector<int> u[300005];
int p[19][300005];
int d[300005];
int dfo[300005], T;

void go(int i, int par) {
    p[0][i] = par;
    d[i] = d[par]+1;
    dfo[i] = T++;
    for (int j : u[i]) if (j != par) {
        go(j, i);
    }
}

int lca(int i, int j) {
    if (d[i] < d[j]) swap(i,j);
    for (int k = 18; k >= 0; k--)
        if ((d[i]-d[j])&(1<<k)) i = p[k][i];
    if (i == j) return i;
    for (int k = 18; k >= 0; k--)
        if (p[k][i] != p[k][j]) {
            i = p[k][i];
            j = p[k][j];
        }
    if (p[0][i] != p[0][j]) return -1;
    else return p[0][i];
}

bool cmp(int i, int j) {
    return dfo[i] < dfo[j];
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    f.init(n);
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        f.adde(x,y);
    }
    f.dobcc();
    //FO(i,0,n) printf("bc[%d]=%d\n", i, f.bc[i]);
    FO(i,0,n) for (int j : f.u[i]) {
        int ii = f.bc[i], jj = f.bc[j];
        if (ii != jj) u[ii].push_back(jj);
    }
    memset(p[0],-1,sizeof p[0]);
    FO(i,0,f.m) if (p[0][i] == -1) {
        go(i,i);
    }
    FO(i,1,19) FO(j,0,f.m) p[i][j] = p[i-1][p[i-1][j]];
    int N = n;
    n = f.m;
    int r = 0;
    FO(z,1,q+1) {
        int nn, mm;
        scanf("%d %d", &nn, &mm);
        vector<int> v;
        FO(i,0,nn) {
            int x; scanf("%d", &x);
            x = (r+x)%N;
            if (x==0) x = N;
            x--;
            //printf("%d\n", x);
            v.push_back(f.bc[x]);
        }
        vector<int> e;
        FO(i,0,mm) {
            int x, y; scanf("%d%d", &x, &y);
            x = (r+x)%N;
            if (x==0) x = N;
            y = (r+y)%N;
            if (y==0) y = N;
            x--; y--;
            e.push_back(f.bc[x]); e.push_back(f.bc[y]);
        }
        vector<int> vs = v;
        vs.insert(vs.end(),e.begin(),e.end());

        sort(vs.begin(),vs.end());
        vs.resize(unique(vs.begin(),vs.end())-vs.begin());
        sort(vs.begin(),vs.end(),cmp);
        int tsz = sz(vs);
        FO(i,0,tsz-1) {
            int x = lca(vs[i],vs[i+1]);
            if (x != -1) vs.push_back(x);
        }
        sort(vs.begin(),vs.end());
        vs.resize(unique(vs.begin(),vs.end())-vs.begin());
        vector<int> vo = vs;
        sort(vs.begin(),vs.end(),cmp);

        bcc g; g.init(sz(vo));
#define gn(x) lower_bound(vo.begin(),vo.end(),x)-vo.begin()
        FO(i,1,sz(vs)) {
            int x = vs[i];
            int y = lca(vs[i],vs[i-1]);
            if (y != -1) g.adde(gn(x),gn(y));
        }
        FO(i,0,sz(e)/2) {
            g.adde(gn(e[2*i]),gn(e[2*i+1]));
        }
        g.dobcc();
        set<int> ind;
        FO(i,0,sz(v)) {
            ind.insert(g.bc[gn(v[i])]);
            if (sz(ind)>1) break;
        }
        if (sz(ind) > 1) {
            printf("NO\n");
        } else {
            printf("YES\n");
            r += z;
            r %= N;
        }
    }
}