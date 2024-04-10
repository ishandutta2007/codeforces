#include<bits/stdc++.h>
using namespace std;
#define M 998244353
 
int i,n,k,lj,rj,cur,l[300500],r[300500];
long long res,a[300500],jc[300500];
 
long long inv(long long a){
	long long p=M-2,res=1;
	while(p){
		if(p&1){res=res*a%M;}
		p>>=1;a=a*a%M;
	}
	return res;
}
 
int main(){
	
	jc[1]=jc[0]=1;
	for(long long ii=2;ii<=300000;ii++){
		jc[ii]=jc[ii-1]*ii%M;
	}
	scanf("%d%d",&n,&k);
	if(k==1){printf("%d\n",n);return 0;}
	
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	
	sort(l+1,l+1+n);
	sort(r+1,r+1+n);
	lj=rj=1;
	l[n+1]=r[n+1]=2000000000;
	
	while(!((lj+rj)==(n*2+2))){
		
		while(l[lj]<=r[rj]){
			//printf("%lld\n",cur);
			if(cur>=(k-1)){
				res+=jc[cur]*inv(jc[k-1])%M*inv(jc[cur-k+1])%M;
				res%=M;
			}
			cur++;lj++;
			if(lj==(n+1)){break;}
		}
		while(l[lj]>r[rj]){
			rj++;cur--;
			if(rj==(n+1)){break;}
		}
	}
	printf("%lld\n",res%M);
}