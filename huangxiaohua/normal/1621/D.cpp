#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,a[666][666],vis[666][666];
ll res,ans;
vector<pair<int,int> >v={{1,0},{-1,0},{0,1},{0,-1}};

struct sb{
	ll x,y,w;
	bool operator<(const sb a)const{
		return w>a.w;
	}
}s;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		res=0;
		for(i=1;i<=n+n;i++){
			for(j=1;j<=n+n;j++){
				cin>>a[i][j];
				vis[i][j]=0;
				if(i>n&&j>n){
					res+=a[i][j];
					a[i][j]=0;
				}
				if(i<=n&&j<=n){
					res+=a[i][j];
					a[i][j]=0;
				}
			}
		}
		
		cout<<res+min({a[1][n+1],a[1][n+n],a[n][n+1],a[n][n+n],a[n+1][1],a[n+1][n],a[n+n][1],a[n+n][n]})<<'\n';
	}
}