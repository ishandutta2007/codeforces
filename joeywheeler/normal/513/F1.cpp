#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define L (22*22+5)

using namespace std;

namespace MF {
    const int N = 4*L+2, M = 2*L*L+3*L;
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

char g[25][25];
int d[25][25], D;
int dst[L][L];
int h, w;
int my[L], mx[L], mt[L], nm, fy[L], fx[L], ft[L], nf;

void rf() {
    scanf("%d %d %d", fy+nf, fx+nf, ft+nf);
    fy[nf]--; fx[nf]--;
    nf++;
}

void rm() {
    scanf("%d %d %d", my+nm, mx+nm, mt+nm);
    my[nm]--; mx[nm]--;
    nm++;
}

bool mk(int i, int j, int t, long long m) {
    if (dst[i][j] > 5e7) return false;
    return dst[i][j] * 1ll * t <= m;
}

int main() {
    int m, f;
    scanf("%d %d %d %d", &h, &w, &m, &f);
    if (abs(m-f) != 1) {
        printf("-1\n");
        return 0;
    }
    FO(y,0,h) scanf(" %s ", g[y]);
    if (m>f) rf();
    else rm();
    FO(i,0,m) rm();
    FO(i,0,f) rf();
    assert(nm == nf);
    FO(y,0,h) FO(x,0,w) if (g[y][x] == '.') d[y][x] = D++;
    FO(i,0,D) FO(j,0,D) dst[i][j] = 1e8;
    FO(y,0,h) FO(x,0,w) if (g[y][x] == '.') FO(i,0,4) {
        int ny = y + ((int[]){-1,0,1,0})[i];
        int nx = x + ((int[]){0,-1,0,1})[i];
        if (0 <= ny && ny < h && 0 <= nx && nx < w && g[ny][nx] == '.') dst[d[y][x]][d[ny][nx]] = 1;
    }
    FO(i,0,D) dst[i][i] = 0;
    FO(i,0,D) FO(j,0,D) FO(k,0,D) dst[j][k] = min(dst[j][k], dst[j][i]+dst[i][k]);
    long long s = 0, e = 1e12, b=-1;
    while (s <= e) {
        long long m = (s+e)/2;
        MF::init(nm+D+D+nf);
        FO(i,0,nm) MF::add(MF::s, i, 1);
        FO(i,0,nm) FO(j,0,D) if (mk(d[my[i]][mx[i]], j, mt[i], m)) MF::add(i, nm+j, 1);
        FO(i,0,D) MF::add(nm+i, nm+D+i, 1);
        FO(i,0,nf) FO(j,0,D) if (mk(d[fy[i]][fx[i]], j, ft[i], m)) MF::add(nm+D+j, nm+D+D+i, 1);
        FO(i,0,nf) MF::add(nm+D+D+i, MF::t, 1);
        if (MF::mf() == nm) {
            e = m-1;
            b = m;
        } else s = m+1;
    }
    printf("%lld\n", b);
}