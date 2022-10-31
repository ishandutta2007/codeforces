#include <bits/stdc++.h>
using namespace std;
 
int n,t,i,m,a[205],res,k;

int main(){
	scanf("%d\n",&t);
	while(t--){
		memset(a,0,sizeof(a));res=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a[k]=1;
		}
		for(i=1;m>=0;i++){
			if(a[i]==0){m--;}
			res++;
		}
		printf("%d\n",res-1);
	}
}