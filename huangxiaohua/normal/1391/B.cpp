#include<bits/stdc++.h>
using namespace std;

int n,i,t,m,res;
char sb[125][125];
int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d%d\n",&m,&n);
		res=0;
		for(i=1;i<=m;i++){
			gets(sb[i]+1);
		}
		for(i=1;i<=m;i++){
			if(sb[i][n]=='R'){res++;}
		}
		for(i=1;i<=n;i++){
			if(sb[m][i]=='D'){res++;}
		}
		printf("%d\n",res);
	}
}