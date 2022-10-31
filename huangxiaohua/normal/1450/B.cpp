#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,res,x[505],y[505];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		for(i=1;i<=n;i++){
			res=0;
			for(j=1;j<=n;j++){
				res=max(res,abs(x[i]-x[j])+abs(y[i]-y[j]));
			}
			if(res<=k){puts("1");goto aaa;}
		}
		puts("-1");
		aaa:;
	}
}