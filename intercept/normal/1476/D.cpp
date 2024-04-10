#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e5+9;
int n;
char s[M];
int pre[M],suf[M];
void work(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]!=s[i-1])pre[i]=pre[i-1]+1;
		else pre[i]=1;
	}
	suf[n+1]=0;
	for(int i=n;i>=1;--i){
		if(s[i]!=s[i+1])suf[i]=suf[i+1]+1;
		else suf[i]=1;
	}
	for(int i=0;i<=n;++i){
		int ans=1;
		if(s[i]=='L')ans+=pre[i];
		if(s[i+1]=='R')ans+=suf[i+1];
		printf("%d ",ans);
	}
	printf("\n");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
2
5 6
-1 1
-1 2
*/