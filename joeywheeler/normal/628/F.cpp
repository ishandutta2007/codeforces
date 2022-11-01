#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

namespace MF {
    const int N = 100000, M = 100000;
    int f[N], e[2*M], c[2*M], fl[2*M], nxt[2*M], ce;
    int n, s, t;
    int Q[N], lvl[N];
    int le[N];

    void init(int _n) {
        n = _n+2; s = _n; t = _n+1; ce = 0;
        FO(i,0,n) f[i]=-1;
    }

    void add(int a, int b, int cap) {
        nxt[ce]=f[a]; f[a]=ce; e[ce]=b; fl[ce]=0; c[ce]=cap; ce++;
        nxt[ce]=f[b]; f[b]=ce; e[ce]=a; fl[ce]=0; c[ce]=0; ce++;
    }

    bool bfs() {
        FO(i,0,n) lvl[i]=-1;
        int qi = 1;
        Q[0] = s; lvl[s] = 0;
        FO(i,0,qi) {
            int x=Q[i];
            le[x]=f[x];
            for (int j=f[x];j>=0;j=nxt[j]) if (c[j]-fl[j]>0) {
                int y=e[j];
                if (lvl[y]==-1) {
                    lvl[y]=lvl[x]+1;
                    Q[qi++]=y;
                }
            }
        }
        return lvl[t]!=-1;
    }

    int aug(int cu, int cf) {
        if (cu == t) return cf;
        for (int &i=le[cu];i>=0;i=nxt[i]) if (c[i]-fl[i]>0) {
            int x=e[i];
            if (lvl[x]!=lvl[cu]+1) continue;
            int rf = aug(x,min(cf,c[i]-fl[i]));
            if (rf>0) {
                fl[i]+=rf;
                fl[i^1]-=rf;
                return rf;
            }
        }
        lvl[cu]=-1;
        return 0;
    }

    int mf() {
        int tot = 0;
        while (bfs())
            for (int x=aug(s,1e9);x;x=aug(s,1e9)) tot+=x;
        return tot;
    }

    vector<pair<int,int> > mc() {
        bfs();
        vector<pair<int,int> > res;
        FO(i,0,n) if (lvl[i] != -1) {
            for (int j=f[i];j>=0;j=nxt[j]) if (lvl[e[j]] == -1) {
                res.push_back(pair<int,int>(i,e[j]));
            }
        }
        return res;
    }
}

int n, b, q;
pair<int,int> g[10005];

int main() {
    scanf("%d%d%d", &n, &b, &q);
    FO(i,0,q) scanf("%d%d", &g[i].first, &g[i].second);
    g[q] = make_pair(b,n);
    q++;
    MF::init(q+5);
    sort(g,g+q);
    int pu = 0, pv = 0;
    FO(i,0,q) {
        int u, v;
        tie(u,v) = g[i];
        if (v-pv < 0) {
            printf("unfair\n");
            return 0;
        }
        //printf("[%d:%d] gets %d\n", pu+1, u, v-pv);
        MF::add(MF::s,i,v-pv);
        int cnt[5] = {0};
        FO(j,pu+1,u+1) cnt[j%5]++;
        FO(j,0,5) MF::add(i,q+j,cnt[j]);

        pu = u; pv = v;
    }
    FO(j,0,5) MF::add(q+j,MF::t,n/5);
    if (MF::mf() == n) printf("fair\n");
    else printf("unfair\n");
}