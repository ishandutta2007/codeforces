#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,t,m,a[105];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		if(a[n]<=m||a[1]+a[2]<=m){puts("YES");}
		else{puts("NO");}
	}
}