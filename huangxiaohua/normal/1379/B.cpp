#include<bits/stdc++.h>
using namespace std;
 
long long int t,n,i,j,l,r,m,k,a,b,c,x;
 
int main(){
	scanf("%lld\n",&t);
	while(t--){x=0;
		scanf("%lld%lld%lld",&l,&r,&m);
		k=m+l-r;
		for(i=l;i<=r;i++){
			j=k/i;//printf("%d %d\n",i,j);
			if(j*i<m+l-r){j++;}
			if(j==0){j++;
			}
			if(j*i<=m+r-l&&j*i<=m&&j!=0){printf("%lld %lld %lld\n",i,l+m-j*i,l);break;}
			if(j*i<=m+r-l&&j*i>=m){printf("%lld %lld %lld\n",i,l,l+j*i-m);break;}
		}
	}
}