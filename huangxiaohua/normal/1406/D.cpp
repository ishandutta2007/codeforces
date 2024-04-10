#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t;
ll a[200500],sum,d[200500];
void ans(ll sb){
	if(sb>=0){printf("%lld\n",(sb+1)/2);}
	else{printf("%lld\n",sb/2);}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[i-1]=a[i]-a[i-1];
		if(i-1){sum+=max(0ll,d[i-1]);}
	}
	scanf("%d",&t);
	ans(sum+d[0]);
	while(t--){
		scanf("%d%d%d",&j,&k,&m);j--;
		if(j){sum-=max(0ll,d[j]);}if(k<n){sum-=max(0ll,d[k]);}
		d[j]+=m;d[k]-=m;
		if(j){sum+=max(0ll,d[j]);}if(k<n){sum+=max(0ll,d[k]);}
		ans(sum+d[0]);
	}
}