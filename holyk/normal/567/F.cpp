#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
template<typename T,typename U>inline char smax(T&x,const U&y){return x<y?x=y,1:0;}
template<typename T,typename U>inline char smin(T&x,const U&y){return x>y?x=y,1:0;}
#define N 75
vector<int>g[5][N];
int n,k;
inline bool okeq(int x,int y){
	for(int i:g[1][x])if(i==y)return 0;
	for(int i:g[2][x])if(i==y)return 0;	
	return 1;
}
inline bool okls(int x,int l,int r){	
	for(int i:g[0][x])if(i>=l&&i<=r)return 0;
	for(int i:g[2][x])if(i>=l&&i<=r)return 0;
	for(int i:g[4][x])if(i>=l&&i<=r)return 0;
	return 1;
}
ll f[N][N];
ll dfs(int l,int r){
	if(l>=r)return 0;
	ll&ans=f[l][r];if(~ans)return ans;ans=0;
	if(okeq(l,l+1)&&okls(l,l+2,r)&&okls(l+1,l+2,r))ans+=dfs(l+2,r);
	if(okeq(r,r-1)&&okls(r,l,r-2)&&okls(r-1,l,r-2))ans+=dfs(l,r-2);
	if(okeq(l,r)&&okls(l,l+1,r-1)&&okls(r,l+1,r-1))ans+=dfs(l+1,r-1);
	return ans;
}
map<string,int>p;
int main(){
	p["="]=0,p["<"]=1,p[">"]=2,p["<="]=3,p[">="]=4;
	cin>>n>>k;
	memset(f,-1,sizeof f);
	while(k--){
		int x,y;string s;cin>>x>>s>>y;
		#define pb push_back
		switch(p[s]){
			case 0:g[0][x].pb(y),g[0][y].pb(x);break;
			case 1:g[1][x].pb(y);g[2][y].pb(x);if(x==y)return puts("0"),0;break;
			case 2:g[2][x].pb(y);g[1][y].pb(x);if(x==y)return puts("0"),0;break;
			case 3:g[3][x].pb(y);g[4][y].pb(x);break;
			case 4:g[4][x].pb(y);g[3][y].pb(x);break;
		}
	}
	REP(i,2,n<<1)f[i-1][i]=okeq(i-1,i);
	cout<<dfs(1,n<<1)<<endl;
	return 0;
}