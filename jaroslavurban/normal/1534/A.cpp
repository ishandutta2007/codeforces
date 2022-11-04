#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,m;cin>>n>>m;
	vector<string>f(n);
	for(int i=0;i<n;++i)cin>>f[i];
	int type[2]={-1,-1};
	bool pos=true;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			if(f[i][j]!='.'){
				int c=(i+j)&1;
				if(~type[c]&&type[c]!=f[i][j])pos=false;
				type[c]=f[i][j];
			}
		}
	if(!pos||(type[0]==type[1]&&~type[0])){cout<<"NO\n";return;}
	if(type[0]==-1&&type[1]==-1){
		type[0]='R';
		type[1]='W';
	}
	if(type[0]=='R')type[1]='W';
	if(type[0]=='W')type[1]='R';
	if(type[1]=='R')type[0]='W';
	if(type[1]=='W')type[0]='R';
	cout<<"YES\n";
	for(int i=0;i<n;++i,cout<<"\n")
		for(int j=0;j<m;++j)
			cout<<char(type[(i+j)&1]);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}