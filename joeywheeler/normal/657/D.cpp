#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;
pair<int,int> pt[150005];
ll p[150005];
ll t[150005];
int n;
ll T;
int o[150005];

bool cmp(int i, int j) {
    return p[i]*t[j] > p[j]*t[i];
}

bool eq(int i, int j) {
    return !cmp(i,j) && !cmp(j,i);
}

long double mnv[150005], mxv[150005];

bool can(long double c) {
    ll x = 0;
    for (int i = 0; i < n; ) {
        int j;
        ll nx = x;
        for (j = i; j < n && eq(o[i],o[j]); j++) {
            nx += t[o[j]];
        }
        FO(k,i,j) {
            mxv[o[k]] = p[o[k]] * (T - c * (x+t[o[k]]));
            mnv[o[k]] = p[o[k]] * (T - c * nx);
            //printf("%Lf-%Lf\n", mnv[o[k]]/T, mxv[o[k]]/T);
        }
        //printf("[%d,%d)\n", i, j);
        x = nx;
        i = j;
    }
    long double mxst = -1;
    for (int i = 0; i < n;) {
        int j;
        for (j = i; j < n && p[j] == p[i]; j++) {
            if (mnv[j] < mxst) return false;
        }
        FO(k,i,j) {
            mxst = max(mxst, mxv[k]);
        }
        i = j;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", &pt[i].first);
    FO(i,0,n) scanf("%d", &pt[i].second);
    sort(pt,pt+n);
    FO(i,0,n) {
        p[i] = pt[i].first;
        t[i] = pt[i].second;
        T += t[i];
    }
    FO(i,0,n) o[i] = i;
    sort(o,o+n,cmp);
    //FO(i,0,n) {
        //printf("%lld %lld\n", p[o[i]], t[o[i]]);
    //}

    long double st = 0, en = 1;
    FO(Z,0,64) {
        long double md = (st+en)/2;
        if (can(md)) {
            st = md;
        } else {
            en = md;
        }
    }
    double res = (st+en)/2;
    printf("%.11lf\n", res);
}