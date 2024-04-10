#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n; ll l;

struct pt {
    int nk[26];
    int av;

    pt() {
        FO(i,0,4) nk[i] = -1;
        av = 0;
    }
};

pt prt[500];
int npt;

int ai[205];
char bf[205];
map<string,int> ms;
int ndv[205];
ll t[205][205];
ll cr[205][205];
ll tmp[205][205];

map<string,int> sval;
void ml(ll a[205][205], ll b[205][205], ll c[205][205]) {
    FO(i,0,npt) FO(j,0,npt) {
        c[i][j] = -4e18;
        FO(k,0,npt) c[i][j] = max(c[i][j], a[i][k]+b[k][j]);
        if (c[i][j] < 0) c[i][j] = -4e18;
    }
}

int main() {
    scanf("%d %lld", &n, &l);
    FO(i,0,n) scanf("%d", ai+i);
    npt = 1;
    ms[""] = 0;
    FO(i,0,n) {
        scanf(" %s", bf);
        string cs = "";
        for (char *s = bf; *s; s++) {
            cs += *s;
            if (ms.count(cs) == 0) {
                ms[cs] = npt++;
            }
        }
        sval[cs] += ai[i];
    }
    for (auto p : ms) {
        string ns = p.first;
        while (sz(ns)) {
            ndv[p.second] += sval[ns];
            ns = ns.substr(1,sz(ns)-1);
        }
    }
    FO(i,0,npt) FO(j,0,npt) {
        t[i][j] = -4e18;
        cr[i][j] = -4e18;
    }
    FO(i,0,npt) cr[i][i] = 0;
    for (auto p : ms) {
        for (char nk = 'a'; nk <= 'z'; nk++) {
            // from p add nk
            string ns = p.first + nk;
            while (ms.count(ns) == 0) ns = ns.substr(1,sz(ns)-1);
            t[p.second][ms[ns]] = ndv[ms[ns]];

            //printf("%s -> %s\n", p.first.c_str(), ns.c_str());
        }
    }

    while (l) {
        if (l & 1) {
            ml(cr, t, tmp);
            FO(i,0,npt) FO(j,0,npt) cr[i][j] = tmp[i][j];
        }
        ml(t, t, tmp);
        FO(i,0,npt) FO(j,0,npt) t[i][j] = tmp[i][j];
        l /= 2;
    }
    ll res = -4e18;
    FO(i,0,npt) res = max(res, cr[0][i]);
    printf("%lld\n", res);
}