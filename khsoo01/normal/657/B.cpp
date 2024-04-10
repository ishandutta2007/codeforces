#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,l,a[200105],b[200105],midx,ans;

void sim(ll S,ll E)
{
    ll i;
    for(i=S;i<E;i++) {
        if(b[i]%2!=0) {
            midx = min(midx,i);
            b[i+1] += (b[i]-1ll)/2ll;
            b[i] = 1;
        }
        else {
            b[i+1] += b[i]/2ll;
            b[i] = 0;
        }
    }
}

int main()
{
    ll i,j,cur = 0;
    scanf("%lld%lld",&n,&l);
    n++;
    for(i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        b[i] = a[i];
    }
    midx = n-1;
    sim(0,n-1);
    if(b[n-1]<0) {
        for(i=0;i<n;i++) {
            a[i] *= -1ll;
            b[i] = a[i];
        }
        midx = n-1;
        sim(0,n-1);
    }
    sim(n-1,n+100);
    for(i=n+100;i>=midx;i--) {
        cur *= 2ll;
        cur += b[i];
        if(cur>2ll*l) {printf("%lld",ans); return 0;}
    }
    if(midx==n-1) {
        if(llabs(a[midx]-cur)<=l && a[midx]!=cur) ans++;
        cur *= 2ll;
        if(cur>2ll*l) {printf("%lld",ans); return 0;}
        midx--;
    }
    for(i=midx;i>=0;i--) {
        if(llabs(a[i]-cur)<=l) ans++;
        cur *= 2ll;
        if(cur>2ll*l) {printf("%lld",ans); return 0;}
    }
    printf("%lld",ans);
}