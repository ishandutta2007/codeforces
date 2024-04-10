#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

namespace MF {
    const long long N = 505, M = 50000;
    long long f[N], e[2*M], c[2*M], fl[2*M], nxt[2*M], ce;
    long long n, s, t;
    long long Q[N], lvl[N];
    long long le[N];

    void init(long long _n) {
        n = _n+2; s = _n; t = _n+1; ce = 0;
        FO(i,0,n) f[i]=-1;
    }

    void add(long long a, long long b, long long cap) {
        nxt[ce]=f[a]; f[a]=ce; e[ce]=b; fl[ce]=0; c[ce]=cap; ce++;
        nxt[ce]=f[b]; f[b]=ce; e[ce]=a; fl[ce]=0; c[ce]=0; ce++;
    }

    bool bfs() {
        FO(i,0,n) lvl[i]=-1;
        long long qi = 1;
        Q[0] = s; lvl[s] = 0;
        FO(i,0,qi) {
            long long x=Q[i];
            le[x]=f[x];
            for (long long j=f[x];j>=0;j=nxt[j]) if (c[j]-fl[j]>0) {
                long long y=e[j];
                if (lvl[y]==-1) {
                    lvl[y]=lvl[x]+1;
                    Q[qi++]=y;
                }
            }
        }
        return lvl[t]!=-1;
    }

    long long aug(long long cu, long long cf) {
        if (cu == t) return cf;
        for (long long &i=le[cu];i>=0;i=nxt[i]) if (c[i]-fl[i]>0) {
            long long x=e[i];
            if (lvl[x]!=lvl[cu]+1) continue;
            long long rf = aug(x,min(cf,c[i]-fl[i]));
            if (rf>0) {
                fl[i]+=rf;
                fl[i^1]-=rf;
                return rf;
            }
        }
        lvl[cu]=-1;
        return 0;
    }

    long long mf() {
        long long tot = 0;
        while (bfs())
            for (long long x=aug(s,1e9);x;x=aug(s,1e9)) tot+=x;
        return tot;
    }

    vector<pair<long long,long long> > mc() {
        bfs();
        vector<pair<long long,long long> > res;
        FO(i,0,n) if (lvl[i] != -1) {
            for (long long j=f[i];j>=0;j=nxt[j]) if (lvl[e[j]] == -1) {
                res.push_back(pair<long long,long long>(i,e[j]));
            }
        }
        return res;
    }
}

#define EPS 1e-12
typedef long double ld;

long long n, m, x;
tuple<long long,long long,long long> ed[505];

int main() {
    scanf("%lld %lld %lld", &n, &m, &x);
    FO(i,0,m) {
        long long a,b,c; scanf("%lld%lld%lld", &a, &b, &c);
        a--; b--;
        ed[i] = make_tuple(a,b,c);
    }
    ld s = 0, e = 1e9, b = 0;
    while (e-s >= EPS) {
        ld md = (s+e)/2;

        MF::init(n);
        FO(i,0,m) {
            long long a, b, c;
            tie(a,b,c) = ed[i];
            ld nm = c / md;
            long long cap = nm;
            MF::add(a,b,cap);
        }
        MF::add(MF::s, 0, 1e16);
        MF::add(n-1, MF::t, 1e16);
        if (MF::mf() >= x) {
            b = md;
            s = md;
        } else e = md;
    }
    double res = b * x;
    printf("%.10lf\n", res);
}