#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,rx,ry;
int mx;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector< vector<int> > f(n+2, vector<int>(m+2,0) );
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>f[i][j];
		rx=ry=1;
		for(i=1;i<=n;i++){
			x=y=1;
			vector<pair<int,int> >v;
			mx=-1;
			for(j=1;j<=m;j++){
				if(f[i][j]<mx){
					y=j;
				}
				mx=max(mx,f[i][j]);
			}
			for(j=1;j<=y;j++){
				if(f[i][j]>f[i][y]){
					x=j;break;
				}
			}
			if(y>ry||(y==ry&&x<rx)){rx=x;ry=y;}
		}
		for(i=1;i<=n;i++){
			swap(f[i][rx],f[i][ry]);
			for(j=2;j<=m;j++){
				if(f[i][j]<f[i][j-1]){
					cout<<"-1\n";goto aaa;
				}
			}
		}
		cout<<rx<<' '<<ry<<'\n';
		aaa:;
	}
}