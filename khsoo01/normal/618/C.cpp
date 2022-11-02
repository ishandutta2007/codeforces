#include<bits/stdc++.h>
#define f first
#define s second
typedef long long ll;
using namespace std;
ll n;
pair<pair<ll,ll>,ll>a[100005];

int main()
{
    ll i,j,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%lld%lld",&a[i].f.f,&a[i].f.s);
        a[i].s=i+1;
    }
    sort(a,a+n);
    for(i=2;i<n;i++) {
        if((a[0].f.f-a[1].f.f)*(a[1].f.s-a[i].f.s)!=(a[1].f.f-a[i].f.f)*(a[0].f.s-a[1].f.s)) {
            printf("%lld %lld %lld",a[0].s,a[1].s,a[i].s);
            return 0;
        }
    }
}