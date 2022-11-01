#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

#define MOD 1000000007ll

using namespace std;

typedef long long ll;

int n;
int p[1000005];

int lpf[1000005];
int shp[1000005];
int tsh[1000005];
int cnt[1000005];
int pt[1000005];

bool seen[1000005];

int l[1000005];
int r[1000005];
int T;

pair<int,int> lt[1000005], rt[1000005];

void addset(int *v, int *u, int nu) {
    int k = 0;
    FO(i,0,nu) lt[k++] = make_pair(l[v[i]], v[i]);
    k = 0;
    FO(i,0,nu) rt[k++] = make_pair(r[u[i]], u[i]);

    sort(lt,lt+k);
    sort(rt,rt+k);

    int lv = -1;
    FO(i,0,k) if (lt[i].first != rt[i].first) {
        printf("0\n");
        exit(0);
    } else {
        if (i == 0 || lt[i].first != lt[i-1].first) {
            lv = ++T;
        }
        l[lt[i].second] = lv;
        r[rt[i].second] = lv;
    }
}

int u[55], w[55];
int nu, nw;

void gs(int i, int k) {
    nu = nw = 0;
    if (i == 1) {
        u[nu++] = 1;
    }
    if (k == 1) {
        w[nw++] = 1;
    }

    int j = i;
    int l = k;
    while (j != 1 || l != 1) {
        if (j != 1) {
            int lp = lpf[j];
            if (nu && n / u[nu-1] != n / lp) {
                addset(u,w,nu);
                nu = nw = 0;
            }
            u[nu++] = lp;
            while (j % lp == 0) j /= lp;
        }

        if (l != 1) {
            int lp = lpf[l];
            if (nw && n / w[nw-1] != n / lp) {
                addset(u,w,nu);
                nu = nw = 0;
            }
            w[nw++] = lp;
            while (l % lp == 0) l /= lp;
        }
    }

    addset(u,w,nu);
}

int main() {
    scanf("%d", &n);
    FO(i,1,n+1) {
        scanf("%d", p+i);
        seen[p[i]] = true;
    }

    vector<int> v;
    pt[1] = 1;
    FO(i,2,n+1) if (lpf[i] == 0) {
        if (sz(v) && n / i != n / v.back()) {
            addset(&v[0], &v[0], sz(v)); v.clear();
        }
        v.push_back(i);

        if (pt[n/i] == 0) pt[n/i] = i;

        for (int j = i; j <= n; j += i) if (lpf[j] == 0) {
            lpf[j] = i;
        }
    }
    v.push_back(1); addset(&v[0], &v[0], sz(v)); v.clear();

    FO(i,1,n+1) {
        shp[i] = 1;
        tsh[i] = 1;

        int j = i;
        while (j != 1) {
            int lp = lpf[j];
            shp[i] *= lp;
            tsh[i] *= pt[n/lp];
            while (j % lp == 0) j /= lp;
        }
    }

    tsh[1] = pt[1];

    FO(i,1,n+1) if (p[i] && tsh[i] != tsh[p[i]]) {
        printf("0\n");
        return 0;
    }


    FO(i,1,n+1) if (p[i]) {
        gs(i,p[i]);
    }


    ll res = 1;

    sort(l+1,l+n+1);

    for (int i = 1; i <= n; ) {
        int j;
        for (j = i; j <= n && l[j] == l[i]; j++);
        if (l[i]) FO(t,0,j-i) res = res * (t+1) % MOD;
        i = j;
    }

    FO(i,1,n+1) if (!seen[i]) cnt[shp[i]]++;

    FO(i,0,n+1) {
        FO(j,0,cnt[i]) res = res * (j+1) % MOD;
    }

    printf("%lld\n", res);
}