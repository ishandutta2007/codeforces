#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,res,a[2050][2050];
bool b[2050][2050];
vector<pair<int,int> >d={{0,1},{0,-1},{1,0},{-1,0}};

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		res=0;
		for(i=0;i<=n+5;i++)for(j=0;j<=n+5;j++)b[i][j]=0;
		for(i=2;i<=n+n;i+=2){
			for(j=1;j<=i;j++){
				x=j;y=i-j;
				if(x<=0||y<=0||x>n||y>n)continue;
				k=0;
				for(auto [dx,dy]:d){
					dx+=x;dy+=y;
					k|=b[dx][dy];
				}
				if(!k){
					res^=a[x][y];
					res^=a[n+1-x][y];
					for(auto [dx,dy]:d){
						b[dx+x][dy+y]^=1;
					}
				}
			}
		}
		
		cout<<res<<'\n';
	}
}