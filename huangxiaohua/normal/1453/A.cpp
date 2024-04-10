#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,t,res,m,sb[105];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(sb,0,sizeof(sb));res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			sb[k]=1;
		}
		for(i=1;i<=m;i++){
			scanf("%d",&k);
			if(sb[k]){res++;}
		}
		printf("%d\n",res);
	}
}