#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(i+j==2){printf("W");}
				else{printf("B");}
			}puts("");
		}
	}
}