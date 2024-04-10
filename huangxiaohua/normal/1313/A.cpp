#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,f[66][66][66];
vector<tuple<int,int,int> > v={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1}};

int main() {
	ios::sync_with_stdio(0);
	for(auto [x,y,z]:v){
		for(i=10;i>=0;i--)for(j=10;j>=0;j--)for(k=10;k>=0;k--){
			if(i-x<0||j-y<0||k-z<0)continue;
			f[i][j][k]=max(f[i][j][k],f[i-x][j-y][k-z]+1);
		}
	}
	cin>>t;
	while(t--){
		cin>>i>>j>>k;
		cout<<f[i][j][k]<<endl;
	}
}