#include<bits/stdc++.h>
const int MAXN=100000,MAXQ=1000,inf=1e9;
int n,q;
char s[MAXN+5];
int next[MAXN+5][26];
int len[4];
char a[4][255];
int dp[255][255][255];
void update(int x){
	for(int i=x==1?len[1]:0;i<=len[1];++i){
		for(int j=x==2?len[2]:0;j<=len[2];++j){
			for(int k=x==3?len[3]:0;k<=len[3];++k){
				dp[i][j][k]=inf;
				if(i&&dp[i-1][j][k]!=inf){
					dp[i][j][k]=std::min(dp[i][j][k],next[dp[i-1][j][k]+1][a[1][i]-'a']);
				}
				if(j&&dp[i][j-1][k]!=inf){
					dp[i][j][k]=std::min(dp[i][j][k],next[dp[i][j-1][k]+1][a[2][j]-'a']);
				}
				if(k&&dp[i][j][k-1]!=inf){
					dp[i][j][k]=std::min(dp[i][j][k],next[dp[i][j][k-1]+1][a[3][k]-'a']);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int c=0;c<26;++c){
		next[n+1][c]=inf;
		for(int i=n;i;--i){
			if(s[i]=='a'+c){
				next[i][c]=i;
			}else{
				next[i][c]=next[i+1][c];
			}
		}
	}
	for(int i=1;i<=q;++i){
		char opt,c;
		int x;
		scanf(" %c%d",&opt,&x);
		if(opt=='+'){
			scanf(" %c",&c);
			a[x][++len[x]]=c;
			update(x);
		}else{
			--len[x];
		}
		if(dp[len[1]][len[2]][len[3]]!=inf){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}