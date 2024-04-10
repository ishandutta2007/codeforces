#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[200500],b[200500],l,r,md,sb1,sb2,res,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i]);
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(i=2;i<=n;i++){
			a[i]=a[i-1]+a[i];
			b[i]=b[i-1]+b[i];
		}
		l=0;r=1e9;
		res=1e9;
		while(l<=r){
			md=(l+r)/2;
			tmp=(md+n)-(md+n)/4;
			if(tmp<=md){
				sb1=100*tmp;
			}
			else{
				sb1=100*md+a[n]-a[n-(tmp-md)];
			}
			
			if(tmp<=n){
				sb2=b[n]-b[n-tmp];
			}
			else{
				sb2=b[n];
			}
			
			if(sb1>=sb2){
				res=min(res,md);r=md-1;
			}
			else{
				l=md+1;
			}
		}
		printf("%lld\n",res);
	}
}