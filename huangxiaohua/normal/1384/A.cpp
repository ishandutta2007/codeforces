#include<bits/stdc++.h>
using namespace std;

int i,n,t,k,j;
char sb[250][250];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=200;i++){
			sb[0][i]='a';
		}
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			for(j=1;j<=200;j++){
				if(j==k+1&&sb[i-1][j]=='a'){sb[i][j]='b';continue;}
				if(j==k+1&&sb[i-1][j]=='b'){sb[i][j]='a';continue;}
				sb[i][j]=sb[i-1][j];
			}
		}
		for(i=0;i<=n;i++){
			puts(sb[i]+1);
		}
	}
}