#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		char s[45],t[45];
		int n;
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)t[i]=s[i];
		std::sort(s+1,s+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)ans+=s[i]!=t[i];
		printf("%d\n",ans);
	}
}