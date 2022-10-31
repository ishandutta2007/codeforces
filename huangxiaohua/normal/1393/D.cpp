#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
 
#include<bits/stdc++.h>
using namespace std;
 
queue<int> x,y;
 
int t,n,m,res,jb[2055][2055],i,j,dp[2055][2055],tmp,used[2055][2055],a,b;
char s[2055][2055];
 
int main(){
	scanf("%d%d\n",&m,&n);
	for(i=1;i<=m;i++){
		gets(s[i]+1);
	}
	for(i=0;i<=m+1;i++){
		used[i][0]=1;
		used[i][n+1]=1;
	}
	for(i=0;i<=n+1;i++){
		used[0][i]=1;
		used[m+1][i]=1;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(s[i][j]==s[i+1][j]&&s[i][j]==s[i][j+1]&&s[i][j]==s[i-1][j]&&s[i][j]==s[i][j-1]){
				continue;
			}
			x.push(i);
			y.push(j);
			used[i][j]=1;
		}
	}
	while(!x.empty()){
		a=x.front(),b=y.front();res+=dp[a][b];
		if(!used[a+1][b]){dp[a+1][b]=dp[a][b]+1;x.push(a+1);y.push(b);used[a+1][b]=1;}
		if(!used[a][b+1]){dp[a][b+1]=dp[a][b]+1;x.push(a);y.push(b+1);used[a][b+1]=1;}
		if(!used[a-1][b]){dp[a-1][b]=dp[a][b]+1;x.push(a-1);y.push(b);used[a-1][b]=1;}
		if(!used[a][b-1]){dp[a][b-1]=dp[a][b]+1;x.push(a);y.push(b-1);used[a][b-1]=1;}
		x.pop();y.pop();
	}
	printf("%d",res+m*n);
}