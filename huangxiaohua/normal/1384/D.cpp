#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[50];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=1;j<=32;j++){
				a[j]+=k&1;k>>=1;
			}
		}
		for(i=32;i>=1;i--){
			if((a[i]%4)==1){puts("WIN");goto aaa;}
			if((a[i]%4)==3){puts((n&1)?"LOSE":"WIN");goto aaa;}
		}
		puts("DRAW");
		aaa:;
	}
}