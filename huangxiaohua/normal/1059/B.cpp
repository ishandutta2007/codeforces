#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int i,j,k,n,m,t,f[1050][1050];
char s[1050][1050];
vector<pair<int,int> >v={{1,1},{0,1},{-1,1},{1,0},{-1,0},{1,-1},{0,-1},{-1,-1}};

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i]+1;
	}
	for(i=2;i<n;i++){
		for(j=2;j<m;j++){
			for(auto [x,y]:v){
				if(s[i+x][j+y]!='#'){
					goto aaa;
				}
			}
			for(auto [x,y]:v){
				f[i+x][j+y]=1;
			}
			aaa:;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s[i][j]=='#'&&!f[i][j]){
				cout<<"NO";return 0;
			}
		}
	}
	cout<<"YES";
}