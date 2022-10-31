#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll i,n,res,a[100500],j,k,tmp;

int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		res+=a[i]-1;
	}
	for(j=2;;j++){
		tmp=0;k=1;
		for(i=1;i<=n;i++){
			//printf("%lld %lld %lld\n",tmp,j,k);
			tmp+=abs(a[i]-k);
			k*=j;
			if(i!=n&&k>=100000000000ull){goto aaa;}
		}
		
		res=min(res,tmp);
	}
	aaa:printf("%lld\n",res);
	//printf("%lld\n",k);
}