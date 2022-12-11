#include <bits/stdc++.h>
#define ope operator
#define re register
#define il inline
using namespace std;
int T,n,m,k,q,p;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&k,&p);
		int flag=0;
		for(int i=2,ed=sqrt(k);i<=ed;i++){
			if(k%i==0){
				flag=i;
				break;
			}
		}
		if(!flag) flag=k;
		if(flag==2) printf("%lld\n",k+p*2ll);
		else printf("%lld\n",k+flag+(p-1)*2ll);
	}
}