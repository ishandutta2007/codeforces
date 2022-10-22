#include<bits/stdc++.h>
using namespace std;
int n,m,q;
string s[1000009];
vector<int>dp[1000009];
int p[1000009],f[1000009][23];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]=" "+s[i];
		dp[i].resize(m+1);
	}
	for(int i=0;i<=m;++i)s[0].push_back('.');
	dp[0].resize(m+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i-1][j]!='.'&&s[i][j-1]!='.')dp[i][j]=1;
		}
	}
	for(int i=1;i<=m;++i){
		p[i]=0;
		for(int j=1;j<=n;++j){
			p[i]|=dp[j][i];
		}
		p[i]+=p[i-1];
	}
	cin>>q;
	for(int i=1,l,r;i<=q;++i){
		cin>>l>>r;
		if(p[r]-p[l]>0)puts("NO");
		else puts("YES");
	}
	return 0;
}
/*
4 5
..xxx
..xxx
..xxx
..xxx
5
1 3
1 4
1 5
3 4
2 3
*/