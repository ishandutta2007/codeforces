#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,it;
ll res,sum,m,mx,a[105],mn,sum2,l,r;
int main(){
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];mx=max(mx,a[i]);
	}
	for(l=1;l<=mx;l=r+1){
		r=1e18;sum2=0;
		for(i=1;i<=n;i++){
			sum2+=(a[i]+l-1)/l;
			if((a[i]+l-1)/l==1){continue;}
			if((a[i]+l-1)/l==2){r=min(r,a[i]-1);continue;}
			r=min(r,(a[i]-1)/(((a[i]+l-1)/l)-1));
		}
		if(sum2*l-sum>m){continue;}
		res=max(res,min((sum+m)/sum2,r));
	}
	printf("%lld",res);
}