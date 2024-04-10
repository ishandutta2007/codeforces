#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,A,B,C,D;
int main(){
	long long ans=0;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	for(int i=A;i<=B;i++){
		int mn=max(i+B,C+1),mx=min(i+C,D);
//		cout<<mn<<" "<<mx<<"\n"; 
		if(mn<=mx) ans+=(mx-mn+1ll)*(mx-C+mn-C)/2;
		mn=max(i+B,D+1),mx=i+C;
//		cout<<mn<<" "<<mx<<"\n";
		if(mx>=mn) ans+=(mx-mn+1ll)*(D-C+1);
	}
	printf("%lld\n",ans);
}