#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

namespace MCMF {
    const int N = 100, M = 500;
    const int INF = 1e9;
    int f[N], e[2*M], c[2*M], w[2*M], fl[2*M], nxt[2*M], ce;
    int n, s, t;
    int Q[N], d[N], iq[N], p[N];

    void init(int _n) {
        n = _n+2; s = _n; t = _n+1; ce = 0;
        FO(i,0,n) f[i]=-1;
    }

    void add(int a, int b, int cap, int weight) {
        nxt[ce]=f[a]; f[a]=ce; e[ce]=b; fl[ce]=0; c[ce]=cap; w[ce] = weight; ce++;
        nxt[ce]=f[b]; f[b]=ce; e[ce]=a; fl[ce]=0; c[ce]=0; w[ce] = -weight; ce++;
    }

    pair<int,int> aug() {
        FO(i,0,n) d[i] = INF, iq[i] = 0;
        Q[0] = s; d[s] = 0; iq[s] = 1;
        for (int qs = 0, qe = 1; qs != qe;) {
            int x = Q[qs++];
            if (qs == N) qs = 0;
            iq[x] = 0;
            for (int j=f[x];~j;j=nxt[j]) if (c[j]-fl[j]>0) {
                int y = e[j];
                if (d[x]+w[j] < d[y]) {
                    d[y] = d[x]+w[j];
                    p[y] = j;
                    if (!iq[y]) {
                        if (d[y] < d[Q[qs]]) {
                            if (--qs == -1) qs = N-1;
                            Q[qs] = y;
                        } else {
                            Q[qe++] = y;
                            if (qe == N) qe = 0;
                        }
                        iq[y]=1;
                    }
                }
            }
        }
        if (d[t] == INF) return {0,0};
        else {
            int flow = INF;
            for (int i = t; i != s; i = e[p[i]^1]) {
                flow = min(flow, c[p[i]]-fl[p[i]]);
            }
            for (int i = t; i != s; i = e[p[i]^1]) {
                fl[p[i]] += flow; fl[p[i]^1] -= flow;
            }
            return {d[t], flow};
        }
    }

    // <cost,flow>
    pair<int,int> mcmf() {
        pair<int,int> res(0,0), ext;
        while ((ext = aug()).second) {
            res.first += ext.first; res.second += ext.second;
        }
        return res;
    }
};

int w1[25][25];
int w2[25][25];
int n;

int calc(int msk) {
    assert(__builtin_popcount(msk) == n/2);
    MCMF::init(2*n);
    FO(i,0,n) FO(j,0,n) {
        int happy;
        if (msk&(1<<j)) happy = w1[i][j];
        else happy = w2[i][j];
        MCMF::add(i, j+n, 1, -happy);
    }
    FO(i,0,n) {
        MCMF::add(MCMF::s, i, 1, 0);
        MCMF::add(n+i, MCMF::t, 1, 0);
    }
    return -MCMF::mcmf().first;
}

vector<int> v;

int improve(int resm, double T) {
    int res = calc(resm);
    int start = clock();
    while (clock()-start < T*CLOCKS_PER_SEC && clock() < 1.9*CLOCKS_PER_SEC) {
        FO(i,0,n) if (resm&(1<<i)) FO(j,0,n) if ((resm&(1<<i)) && !(resm&(1<<j))) {
            if (clock()-start > T*CLOCKS_PER_SEC && clock() < 1.9*CLOCKS_PER_SEC) goto end;
            int nm = resm^(1<<i)^(1<<j);
            int v = calc(nm);
            if (v >= res) {
                res = v;
                resm = nm;
            }
        }
    }
    end: return res;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) FO(j,0,n) {
        scanf("%d", &w1[i][j]);
    }
    FO(i,0,n) FO(j,0,n) {
        scanf("%d", &w2[i][j]);
    }
    FO(i,0,1<<n) if (__builtin_popcount(i) == n/2) {
        v.push_back(i);
    }

    int res = 0;
    while (clock() < 1.9*CLOCKS_PER_SEC) {
        int sm = v[rand()%sz(v)];
        res = max(res, improve(sm,0.5));
    }
    printf("%d\n", res);
}