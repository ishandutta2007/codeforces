#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define eq(x,y) (x==-1 || x==y)

using namespace std;

namespace MF {
    const int N = 605+605, M = 605*605;
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


pair<int,int> rd() {
    string a, b;
    cin >> b >> a;
    int c, p;
    if (a == "?") c = -1;
    else c = atoi(a.c_str());
    if (b == "?") p = -1;
    else p = atoi(b.c_str());
    return {c,p};
}

int n;
pair<int,int> f[305];
int ind[305][305];
int ei[305][305];
int nk[305];
int asgn[305]; // real node to target
int unasgn[305]; // target to real node

int lc;

void go() {
    vector<pair<int,int> > v;
    vector<int> c0[305];

    set<int> cs;
    FO(i,0,n) if (f[i].first != -1) cs.insert(f[i].first);


    for (int c : cs) {
        int nm0 = 0;
        int mxp = 0;
        FO(i,0,n) if (f[i].first == c) {
            nm0 += f[i].second == 0;
            mxp = max(mxp, f[i].second);
        }
        int nc = 0;
        nc = (nm0 + c-1) / c;
        if (nc == 0) nc = 1;

        FO(i,0,nc) FO(j,0,c) {
            ind[c][0] = sz(v);
            if (j == 0) nk[sz(v)] = sz(v)+c-1;
            else nk[sz(v)] = sz(v)-1;
            c0[c].emplace_back(sz(v));
            v.emplace_back(c, 0);
            if (sz(v) > n) return;
        }
        FO(i,1,mxp+1) {
            ind[c][i] = sz(v);
            nk[sz(v)] = sz(v)-1;
            v.emplace_back(c,i);
            if (sz(v) > n) return;
        }
    }

    MF::init(n + sz(v));
    FO(i,0,n) {
        MF::add(MF::s, i, 1);
    }
    FO(i,0,sz(v)) {
        MF::add(n+i, MF::t, 1);
    }
    FO(i,0,n) FO(j,0,sz(v)) {
        if (eq(f[i].first,v[j].first) && eq(f[i].second,v[j].second)) {
            ei[i][j] = MF::ce;
            MF::add(i, n+j, 1);
        } else ei[i][j] = -1;
    }
    int r = MF::mf();
    if (r != sz(v)) return;

    //printf("PLAN:\n");
    //FO(i,0,sz(v)) printf("%d: c=%d,p=%d\n", i, v[i].first, v[i].second);

    memset(asgn, -1, sizeof asgn);
    memset(unasgn, -1, sizeof unasgn);

    FO(i,0,n) {
        FO(j,0,sz(v)) if (ei[i][j] != -1 && MF::fl[ei[i][j]] == 1) {
            asgn[i] = j;
            unasgn[j] = i;
        }
    }

    int cj[305] = {};
    FO(i,0,n) {
        if (f[i].first != -1 && f[i].second == 0 && asgn[i] == -1) {
            int c = f[i].first;
            while (f[unasgn[c0[c][cj[c]]]].first == c &&
                    f[unasgn[c0[c][cj[c]]]].second == 0) cj[c]++;

            asgn[unasgn[c0[c][cj[c]]]] = -1;

            asgn[i] = c0[c][cj[c]];
            unasgn[c0[c][cj[c]]] = i;
        }
    }

    //printf("ASSIGNMENT\n");
    FO(i,0,n) {
        if (asgn[i] != -1) {
            //printf("%d - %d\n", i, asgn[i]);
            assert(unasgn[asgn[i]] == i);
        }
    }

    FO(i,0,n) {
        if (asgn[i] != -1) {
            printf("%d ", unasgn[nk[asgn[i]]]+1);
        } else if (f[i].first != -1 && f[i].second != -1) {
            printf("%d ", unasgn[ind[f[i].first][f[i].second-1]]+1);
        } else if (f[i].first == -1 && f[i].second != -1) {
            if (f[i].second == 0) printf("%d ", i+1);
            else printf("%d ", unasgn[ind[lc][f[i].second-1]]+1);
        } else if (f[i].second == -1 && f[i].first != -1) {
            printf("%d ", unasgn[ind[f[i].first][0]]+1);
        } else {
            printf("%d ", i+1);
        }
    }
    printf("\n");
    exit(0);
}

int main() {
    scanf("%d", &n);
    int mxun = -1;
    FO(i,0,n) {
        f[i] = rd();
        //printf("%d: c=%d, p=%d\n", i, f[i].first, f[i].second);
        if (f[i].first == -1 && f[i].second != -1 && (mxun == -1 || f[i].second > f[mxun].second)) mxun = i;
    }
    if (mxun == -1) go();
    else {
        for (f[mxun].first = 1; f[mxun].first <= n; f[mxun].first++) {
            lc = f[mxun].first;
            go();
        }
    }
    printf("-1\n");
}