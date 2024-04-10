#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,res,f[3050],g[3050];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(f,1,sizeof(f));f[0]=0;
		while(n--){
			scanf("%d",&k);
			memset(g,1,sizeof(g));
			for(j=0;j<=2000;j++){
				g[max(0,j-k)]=min(g[max(0,j-k)],f[j]+k);
				g[j+k]=min(g[j+k],max(0,f[j]-k));
			}
			memcpy(f,g,sizeof(f));
		}
		res=114514;
		for(i=0;i<=2000;i++)res=min(res,i+f[i]);
		printf("%d\n",res);
	}
}