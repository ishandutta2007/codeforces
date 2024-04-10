#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
int n,m,r,c;
char s[59][59];
void work(){
	cin>>n>>m>>r>>c;
	bool flag=0;
	for(int i=1;i<=n;++i){
		cin>>(s[i]+1);
		for(int j=1;j<=m;++j){
			if(s[i][j]=='B')flag=1;
		}
	}
	if(!flag){
		puts("-1");
		return;
	}
	int sr=0,sc=0;
	for(int i=1;i<=m;++i){
		if(s[r][i]=='B')sr=1;
	}
	for(int i=1;i<=n;++i){
		if(s[i][c]=='B')sc=1;
	}
	if(s[r][c]=='B')puts("0");
	else if(sr==1||sc==1)puts("1");
	else puts("2");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/