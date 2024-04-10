#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1,0,0,1,1,1};

void ProGamerMove(){
	int n,m;cin>>n>>m;
	vector<string>f(n,string(m,'0'));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)if(i==0||i==n-1||j==0||j==m-1){
			bool good=true;
			for(int x=0;x<8;++x){
				int ny=i+dy[x];
				int nx=j+dx[x];
				if(ny<0||ny>=n||nx<0||nx>=m||f[ny][nx]=='0')continue;
				good=false;break;
			}
			if(good)f[i][j]='1';
		}
	for(int i=0;i<n;++i)cout<<f[i]<<"\n";
	cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}