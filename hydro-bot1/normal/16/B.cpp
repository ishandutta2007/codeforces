// Hydro submission #61ab6ad6c1d0db2abec5c904@1638623958491
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,sum=0,ans=0;
struct cyy{
	ll a1,a2;
}a[25];
bool cmp(cyy a,cyy b){
    return a.a2>b.a2;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)scanf("%lld%lld",&a[i].a1,&a[i].a2);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(n-sum>a[i].a1)sum+=a[i].a1,ans+=a[i].a1*a[i].a2;
		else{
            ans+=(n-sum)*a[i].a2;break;
		}
	}
	printf("%lld",ans);
	return 0;
}