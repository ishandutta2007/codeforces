#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define MAGIC 500

using namespace std;

int n, C;
int l[300005], r[300005], c[300005];
int m;
int k[300005];
vector<int> it;
int T;
int il[300005], ir[300005];
vector<int> is[600005], er[600005];
vector<int> w[600005]; bool gd[600005]; int ei0[600005], ei1[600005];
vector<pair<int,int> > el;
int ev[600005];
int es[300005], ee[300005];
int bst[600005];

int tvs[300005];
pair<int,int> sci[300005];
int mxu[300005];
int scl[300005];
int rt[600005];

int qmx(int l, int r) {
    int ans = -1;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l&1) ans = max(ans, rt[l++]);
        if (r&1) ans = max(ans, rt[--r]);
    }
    return ans;
}

void adv(int i, int x) {
    rt[i += n] += x;
    for (i /= 2; i > 0; i /= 2) {
        rt[i] = max(rt[2*i], rt[2*i+1]);
    }
}

void addtvs(int i, int v) {
    tvs[i] += v;
    adv(scl[i], v);
}

int clcv(int i) {
    if (ee[i]-es[i] > MAGIC || c[i] > C) return 0;

    //printf("i=%d\n", i);
    //printf("es[%d],ee[%d]=%d,%d\n", i, i, es[i], ee[i]);

    int res = tvs[i];

    // use an edge?
    fo(j,es[i],ee[i]) {
        if (c[el[j].first]+c[el[j].second] <= C) {
            assert(el[j].first == i);
            res = max(res, ev[j] + tvs[el[j].first] + tvs[el[j].second]);
        }
    }
    //printf("res=%d\n", res);

    // don't use an edge?
    int mx = -1;
    if (scl[i] < mxu[i]) {
        mx = max(qmx(0, scl[i]), qmx(scl[i]+1, mxu[i]));
    } else {
        mx = qmx(0, mxu[i]);
    }
    if (mx != -1) res = max(res, mx + tvs[i]);
    //printf("res=%d\n", res);

    return res;
}

int main() {
    scanf("%d %d", &n, &C);
    fo(i,0,n) scanf("%d %d %d", l+i, r+i, c+i);
    scanf("%d", &m);
    fo(i,0,m) scanf("%d", k+i);

    fo(i,0,n) sci[i] = make_pair(c[i], i);
    sort(sci, sci+n);
    fo(i,0,n) {
        scl[sci[i].second] = i;
        mxu[i] = lower_bound(sci, sci+n, make_pair(C-c[i]+1,-1))-sci;
    }

    fo(i,0,n) it.push_back(l[i]);
    fo(i,0,n) it.push_back(r[i]);
    it.push_back(2e9+5);
    it.push_back(0);
    sort(it.begin(),it.end());
    it.resize(unique(it.begin(),it.end())-it.begin());
    T = sz(it);

    fo(i,0,n) {
        il[i] = lower_bound(it.begin(),it.end(),l[i])-it.begin();
        ir[i] = lower_bound(it.begin(),it.end(),r[i])-it.begin();
        is[il[i]].push_back(i);
        er[ir[i]].push_back(i);
    }

    set<int> wh;
    fo(i,0,T-1) {
        for (int x : is[i]) wh.insert(x);
        for (int x : er[i]) wh.erase(x);
        if (sz(wh) <= 2) {
            for (int x : wh) w[i].push_back(x);
            gd[i] = true;
            if (sz(w[i]) == 2) {
                el.emplace_back(w[i][0], w[i][1]);
                el.emplace_back(w[i][1], w[i][0]);
            }
            //printf("[%d,%d)\n", it[i], it[i+1]);
            //for (int x : wh) printf("%d ", x);
            //printf("\n");
            //printf("---\n");
        }
    }

    sort(el.begin(), el.end());
    el.resize(unique(el.begin(),el.end())-el.begin());

    memset(es, -1, sizeof es);
    memset(ee, -1, sizeof ee);

    fo(i,0,sz(el)) {
        if (es[el[i].first] == -1) es[el[i].first] = i;
        ee[el[i].first] = i+1;
    }

    fo(i,0,T) if (sz(w[i]) == 2) {
        ei0[i] = lower_bound(el.begin(), el.end(), make_pair(w[i][0],w[i][1])) - el.begin();
        ei1[i] = lower_bound(el.begin(), el.end(), make_pair(w[i][1],w[i][0])) - el.begin();
    }

    fo(i,0,n) if (ee[i] - es[i] > MAGIC && c[i] <= C) {
        // calc where one endpoint is i
        memset(tvs, 0, sizeof tvs);
        fo(j,0,n) if (c[i]+c[j] > C) tvs[j] = -2e9-10;
        int oh = 0;
        int cbst = 0;
        fo(j,0,T-1) {
            if (gd[j]) {
                int ln = it[j+1]-it[j];
                if (sz(w[j]) == 0 || (sz(w[j]) == 1 && w[j][0] == i)) {
                    oh += ln;
                } else if (sz(w[j]) == 1) {
                    cbst = max(cbst, tvs[w[j][0]] += ln);
                } else if (sz(w[j]) == 2 && (w[j][0] == i || w[j][1] == i)) {
                    cbst = max(cbst, tvs[w[j][0]^w[j][1]^i] += ln);
                }
            }
            bst[j+1] = max(bst[j+1], cbst+oh);
        }
    }

    memset(tvs, 0, sizeof tvs);
    int oh = 0;
    int cbst = 0;
    fo(j,0,T-1) {
        if (gd[j]) {
            int ln = it[j+1]-it[j];
            if (sz(w[j]) == 0) {
                oh += ln;
            } else if (sz(w[j]) == 1) {
                addtvs(w[j][0], ln);
            } else {
                //printf("j=%d, ei0=%d, ei1=%d\n", j, ei0[j], ei1[j]);
                ev[ei0[j]] += ln;
                ev[ei1[j]] += ln;
            }
            for (int x : w[j]) cbst = max(cbst, clcv(x));
        }
        bst[j+1] = max(bst[j+1], cbst+oh);
    }
    //printf("bst:");
    //fo(i,0,T) {
        //printf(" %d", bst[i]);
    //}
    //printf("\n");

    //fo(j,0,T) printf("%d ", it[j]);
    //printf("\n");

    fo(i,0,m) {
        int j = lower_bound(bst,bst+T,k[i])-bst;
        int ex = bst[j]-k[i];
        int ep = it[j];
        printf("%d\n", ep-ex);
    }
}