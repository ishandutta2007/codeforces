#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
ll a[1005000],res=1e18,sum,b[1005000];

ll get(ll x){
	int i,j,k,l,r=0;
	ll pre=0,res=0;
	for(i=1;i<=n;i++){
		pre+=a[i];pre%=x;
		res+=min(pre,x-pre);
	}
	return res;
}

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(sum==1){puts("-1");return 0;}
	for(ll i=2;i<=sum;i++){
		if(i>=1000000){break;}
		if(sum%i){continue;}
		while(!(sum%i)){sum/=i;}
		res=min(res,get(i));
	}
	if(sum==1){goto aaa;
	}
	res=min(res,get(sum));
aaa:	printf("%lld",res);
}