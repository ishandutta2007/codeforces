#include<bits/stdc++.h>
using namespace std;

int n,i,j,m,t,a[1050],tmp,b[1050];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=m;i++){
			scanf("%d",&tmp);a[tmp]=1;
		}
		
		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		for(i=1;i<=n;i++){
			if(a[b[i]]==1){printf("YES\n1 %d\n",b[i]);goto aaa;}
		}
		puts("NO");
		aaa:continue;
	}
}