#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll a[200005];
ll c[200005];
int n;

ll calc(int i, int j) {
    if (i <= j) {
        return a[i] * (j-i) - (c[j+1]-c[i+1]);
    } else {
        return a[i] * (j-i) + (c[i]-c[j]);
    }
}

ll t = 0;
ll bst = 0;

pair<int,int> q[200005];

void ms(int qs, int qe, int rs, int re) {
    if (qs < qe) {
        int i = (qs+qe)/2;
        int bj = -1; ll bv = -1e18;
        FO(j,rs,re) {
            ll v = calc(q[i].second, j);
            if (v > bv) {
                bv = v;
                bj = j;
            }
        }
        bst = max(bst, bv);
        ms(qs,i, rs,bj+1);
        ms(i+1,qe, bj,re);
    }
}

void solve(int s, int e) {
    if (s+1 == e) return;
    int md = (s+e)/2;
    FO(i,s,md) q[i] = make_pair(a[i],i);
    sort(q+s,q+md);
    ms(s,md, md,e);

    FO(i,md,e) q[i] = make_pair(a[i],i);
    sort(q+md,q+e);
    ms(md,e, s,md);
    solve(s,md);
    solve(md,e);
}


int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%lld", a+i);
        c[i+1] = c[i]+a[i];
        t += a[i] * (i+1);
    }
    solve(0,n);
    printf("%lld\n", t+bst);
}