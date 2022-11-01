#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

namespace MF {
    const int N = 600, M = 300*300;
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

    int aug(int cu, int f) {
        if (cu == t) return f;
        for (int &i=le[cu];i>=0;i=nxt[i]) if (c[i]-fl[i]>0) {
            int x=e[i];
            if (lvl[x]!=lvl[cu]+1) continue;
            int rf = aug(x,min(f,c[i]-fl[i]));
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
};

bool p[30000];

void cp() {
    FO(i,2,30000) if (!p[i]) {
        for (int j = 2*i; j < 30000; j += i) p[j] = true;
    }
    FO(i,2,30000) p[i] = !p[i];
}

#define IMP "Impossible\n"

int n, a[205], ind[205];
vector<int> adj[205];
bool s[205];

vector<int> t[205]; int nt;

void dfs(int i) {
    s[i] = true;
    t[nt].push_back(i+1);
    for (int j : adj[i]) if (!s[j]) {
        dfs(j);
        return;
    }
}

int main() {
    cp();
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    int odd=0,even=0;
    FO(i,0,n) if (a[i]&1) odd++;
    else even++;
    if (odd != even) {
        printf(IMP);
        return 0;
    }
    MF::init(n);
    FO(i,0,n) {
        if (a[i]&1) MF::add(MF::s, i, 2);
        else MF::add(i, MF::t, 2);
    }
    FO(i,0,n) if (a[i]&1) {
        FO(j,0,n) if (p[a[i]+a[j]]) {
            MF::add(i, j, 1);
        }
    }
    if (MF::mf() != n) {
        printf(IMP);
    } else {
        FO(i,0,n) if (a[i]&1) {
            for (int j=MF::f[i];j>=0;j=MF::nxt[j]) if (MF::c[j]-MF::fl[j]==0) {
                int o = MF::e[j];
                if (0 <= o && o < n) {
                    adj[i].push_back(o);
                    adj[o].push_back(i);
                }
            }
        }
        FO(i,0,n) if (!s[i]) {
            dfs(i);
            nt++;
        }
        printf("%d\n", nt);
        FO(i,0,nt) {
            printf("%d", sz(t[i]));
            for (int x : t[i]) printf(" %d", x);
            printf("\n");
        }
    }
}