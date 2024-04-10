#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[1005000][3],pre[1005000];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%1d",&k);
			pre[i]=pre[i-1]+k;
			if(k){
				f[i][1]=f[i-1][0];
				if(i>m){f[i][1]=min(f[i][1],f[i-m][1]+pre[i-1]-pre[i-m]);}
				
				f[i][0]=f[i-1][0]+1;
				
				f[i][2]=min(f[i-1][2],f[i-1][1])+1;
			}
			else{
				f[i][1]=f[i-1][0]+1;
				if(i>m){f[i][1]=min(f[i][1],f[i-m][1]+pre[i-1]-pre[i-m]+1);}
				
				f[i][0]=f[i-1][0];
				
				f[i][2]=min(f[i-1][2],f[i-1][1]);
			}
		}
		printf("%d\n",min({f[n][0],f[n][1],f[n][2]}));
	}
}