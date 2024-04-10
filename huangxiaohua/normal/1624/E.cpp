#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)))

int i,j,k,n,m,t,dep,vis[1050];
char s[1050][1050];

tuple<int,int,int> p1[11][11],p2[11][11][11];

bool dfs(int x){
	if(vis[x])return 0;
	vis[x]=1;
	dep++;
	if(!x){
		cout<<dep-1<<'\n';
		return 1;
	}
	
	if(x>=2){
		auto [a,b,c]=p1[s[n+1][x-1]][s[n+1][x]];
		if(a&&b&&c&&dfs(x-2)){
			cout<<a<<' '<<b<<' '<<c<<'\n';
			return 1;
		}
	}
	
	if(x>=3){
		auto [a,b,c]=p2[s[n+1][x-2]][s[n+1][x-1]][s[n+1][x]];
		if(a&&b&&c&&dfs(x-3)){
			cout<<a<<' '<<b<<' '<<c<<'\n';
			return 1;
		}
	}
	dep--;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		dep=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		for(i=1;i<=n+1;i++){
			cin>>s[i]+1;
			for(j=1;j<=m;j++){
				s[i][j]-='0';
			}
		}
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				p1[i][j]={0,0,0};
				for(k=0;k<10;k++){
					p2[i][j][k]={0,0,0};
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(j+1<=m){
					p1[s[i][j]][s[i][j+1]]={j,j+1,i};
				}
				if(j+2<=m){
					p2[s[i][j]][s[i][j+1]][s[i][j+2]]={j,j+2,i};
				}
			}
		}
		if(dfs(m))continue;
		else cout<<-1<<'\n';
	}
}