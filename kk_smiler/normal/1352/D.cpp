#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a[5010];
long long sum[5010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i]; 
		int l=0,r=n,tmp=0;
		long long lans=0,llas=0,rans=0,rlas=0;
		while(l<r){
			tmp++;
			if(tmp%2==1){
				llas=0; 
				while(llas<=rlas&&l<r) ++l,lans+=a[l],llas+=a[l];
			}
			else{
				rlas=0;
				while(rlas<=llas&&r>l) rans+=a[r],rlas+=a[r],r--;
			}
		}
		printf("%d %lld %lld\n",tmp,lans,rans);
	}
}