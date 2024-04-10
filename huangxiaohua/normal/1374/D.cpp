#include<bits/stdc++.h>
using namespace std;

long long sb[200500];
int t,n,k,i,j,tmp,yes;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);yes=0;
		for(i=1;i<=n;i++){
			scanf("%d",&tmp);
			if(tmp%k!=0){
				yes=1;
				sb[i]=k-tmp%k;
			}
			else{sb[i]=0;}
		}
		if(yes==0){puts("0");continue;}
		
		sort(sb+1,sb+n+1);tmp=-1;
		//for(i=1;i<=n;i++){printf("%lld\n",sb[i]);}
		for(i=1;i<=n;i++){
			if(sb[i]==tmp){
				sb[i]=sb[i-1]+k;
			}else{
				tmp=-1;
			}
			if(sb[i]==sb[i+1]&&sb[i]!=0){
				tmp=sb[i];
			}
		}
		
		sort(sb+1,sb+n+1);
		printf("%lld\n",sb[n]+1);
	}
}