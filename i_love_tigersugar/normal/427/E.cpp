#include<bits/stdc++.h>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
int a[MAX];
int n,m;
inline void minimize(ll &x,const ll &y) {
    if (x>y) x=y;
}
void process(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    int l=1-m;
    int r=n;
    ll res=INF;
    ll sl=0;
    ll sr=a[r];
    while (r-m>1) {
        r-=m;
        sr+=a[r];
    }
    FOR(i,1,n) {
        while (l+m<i) {
            l+=m;
            sl+=a[l];
        }
        while (r<=i && r+m<=n) {
            sr-=a[r];
            r+=m;
        }
        minimize(res,1LL*((l-1)/m+1)*a[i]-sl+sr-1LL*((n-r)/m+1)*a[i]);
    }
    cout<<res*2;
}
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("tmp.txt","r",stdin);
#endif
    process();
    return 0;
}