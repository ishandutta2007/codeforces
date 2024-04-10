#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n;
int s, L;
int v[100005];
int rr[100005];

int rt[4*100005];

void SET(int i, int rs, int re, int qi, int v) {
    if (rs+1 == re) rt[i] = v;
    else {
        int md = (rs+re)/2;
        if (qi<md) SET(2*i+1,rs,md,qi,v);
        else SET(2*i+2,md,re,qi,v);
        rt[i]=min(rt[2*i+1],rt[2*i+2]);
    }
}

int query(int i, int rs, int re, int qs, int qe) {
    if (rs == qs && re == qe) return rt[i];
    else {
        int md = (rs+re)/2;
        int res = 1e9;
        if (qs < md) res = min(res, query(2*i+1, rs, md, qs, min(qe,md)));
        if (qe > md) res = min(res, query(2*i+2, md, re, max(qs,md), qe));
        return res;
    }
}

int main() {
    scanf("%d%d%d", &n, &s, &L);
    FO(i,0,n) scanf("%d", &v[i]);
    multiset<int> values;
    int l = 0, r = 1;
    values.insert(v[0]);
    while (l<n) {
        if (*values.rbegin()-*values.begin() > s) {
            rr[l] = r-1;
            values.erase(values.find(v[l]));
            l++;
        } else if (r != n && *values.rbegin()-*values.begin() <= s) {
            values.insert(v[r]);
            r++;
        } else {
            rr[l] = r;
            values.erase(values.find(v[l]));
            l++;
        }
    }
    FO(i,0,n+1) SET(0,0,n+1,i,1e9);
    SET(0,0,n+1,n,0);
    for (int i = n-1; i >= 0; i--) {
        int qs = i+L;
        int qe = min(rr[i]+1,n+1);
        if (qs < qe) {
            SET(0,0,n+1,i,1+query(0,0,n+1,qs,qe));
        }
    }
    int val = query(0,0,n+1,0,1);
    if (val > n+10) printf("-1\n");
    else printf("%d\n", val);
}