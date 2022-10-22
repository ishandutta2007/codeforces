#include<bits/stdc++.h>
using namespace std;
const int M=1009;
int n;
bool in[29],vis[29][29],dp[7][29][29];
char s[M];
void work(){
	scanf("%d%s",&n,s+1);
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	memset(in,0,sizeof(in));
	for(int i=1;i<=n;++i){
		in[s[i]-'a'+1]=1;
		if(i<n)vis[s[i]-'a'+1][s[i+1]-'a'+1]=1;
		if(i<n-1&&s[i]-'a'+1<=3)dp[s[i]-'a'+1][s[i+1]-'a'+1][s[i+2]-'a'+1]=1;
	}
	for(int i=1;i<=26;++i){
		if(!in[i]){
			printf("%c\n",i+'a'-1);
			return;
		}
	}
	for(int i=1;i<=26;++i){
		for(int j=1;j<=26;++j){
			if(!vis[i][j]){
				printf("%c%c\n",i+'a'-1,j+'a'-1);
				return;
			}
		}
	}
	for(int i=1;i<=4;++i){
		for(int j=1;j<=26;++j){
			for(int k=1;k<=26;++k){
				if(!dp[i][j][k]){
					printf("%c%c%c\n",i+'a'-1,j+'a'-1,k+'a'-1);
					return;
				}
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;	
}