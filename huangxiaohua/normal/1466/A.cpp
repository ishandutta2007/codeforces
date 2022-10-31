#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[105],sb[105],res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;
		memset(sb,0,sizeof(sb));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n-1;i++){
			for(j=i+1;j<=n;j++){
				if(!sb[a[j]-a[i]]){
					res++;
					sb[a[j]-a[i]]=1;
				}
			}
		}
		printf("%d\n",res);
	}
}