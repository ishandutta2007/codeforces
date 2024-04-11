#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
pair<ll,pair<ll,ll> >a[100005];

int main()
{
    ll i,j,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++) {
        scanf("%lld%lld",&a[i].first,&a[i].second.first);
        a[i].second.second=i+1;
    }
    sort(a,a+n);
    for(i=2;i<n;i++) {
    	ll dx1 = a[1].first - a[0].first;
    	ll dy1 = a[1].second.first - a[0].second.first;
    	ll dx2 = a[i].first - a[0].first;
    	ll dy2 = a[i].second.first - a[0].second.first;
    	if(dx1 * dy2 != dy1 * dx2){
            printf("%lld %lld %lld",a[0].second.second,a[1].second.second,a[i].second.second);
            return 0;
        }
    }
}