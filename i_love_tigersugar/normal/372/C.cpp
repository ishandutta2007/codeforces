#include<bits/stdc++.h>
#define MAXN   150150
#define MAXM   333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
int a[MAXM],b[MAXM],t[MAXM];
ll f[2][MAXN];
ll best[MAXN],maxl[MAXN],maxr[MAXN];
int n,m,d;
int abs(int x) {
    if (x<0) return (-x); else return (x);
}
void init(void) {
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&d);
    FOR(i,1,m) {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
        scanf("%d",&t[i]);
    }
}
void optimize(void) {
    FOR(i,1,n) f[1][i]=b[1]-abs(a[1]-i);
    FOR(i,2,m) {
        maxl[1]=f[(i-1)%2][1];
        FOR(j,2,n) maxl[j]=max(maxl[j-1],f[(i-1)%2][j]);
        maxr[n]=f[(i-1)%2][n];
        FORD(j,n-1,1) maxr[j]=max(maxr[j+1],f[(i-1)%2][j]);
        if (2LL*(t[i]-t[i-1])*d+1>1LL*n) {
            ll x=1LL*(t[i]-t[i-1])*d;
            FOR(j,1,n) {
                ll l=j-x;
                ll r=j+x;
                assert(l<2 || r>n-1);
                if (l<2) f[i%2][j]=maxl[min(1LL*n,r)];
                else f[i%2][j]=maxr[max(1LL,l)];
                f[i%2][j]+=b[i]-abs(a[i]-j);
            }
            continue;
        }
        if (t[i]==t[i-1]) {
            FOR(j,1,n) f[i%2][j]=f[(i-1)%2][j]+b[i]-abs(a[i]-j);
            continue;
        }
        deque<int> dq;
        int x=2*(t[i]-t[i-1])*d+1;
        while (!dq.empty()) dq.pop_back();
        FOR(j,1,n) {
            while (!dq.empty() && f[(i-1)%2][dq.back()]<=f[(i-1)%2][j]) dq.pop_back();
            dq.push_back(j);
            if (j>=x) {
                while (!dq.empty() && dq.front()<=j-x) dq.pop_front();
                best[j-x+1]=f[(i-1)%2][dq.front()];
            }
        }
        FOR(j,1,n) {
            int l=j-(x-1)/2;
            int r=j+(x-1)/2;
            assert(l>=1 || r<=n);
            if (l<1) f[i%2][j]=maxl[r];
            if (r>n) f[i%2][j]=maxr[l];
            if (1<=l && r<=n) f[i%2][j]=best[l];
            f[i%2][j]+=b[i]-abs(a[i]-j);
        }
    }
    /*FOR(i,2,m) FOR(j,1,n) {
        f[i%2][j]=-INF;
        FOR(k,max(1LL,j-1LL*d*(t[i]-t[i-1])),min(1LL*n,j+1LL*d*(t[i]-t[i-1])))
            f[i%2][j]=max(f[i%2][j],f[(i-1)%2][k]+b[i]-abs(a[i]-j));
    }*/
    ll res=-INF;
    FOR(i,1,n) res=max(res,f[m%2][i]);
    cout << res;
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    init();
    optimize();
    return 0;
}