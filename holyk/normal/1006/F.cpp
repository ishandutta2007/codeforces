#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
unordered_map<ll,ll> f[22];
int n,m;
ll a[22][22],ans,k;
void dfs1(int x,int y,ll v){
	v^=a[x][y];
	if(x+y-1==m){++f[x][v];return;}
	if(x<n)dfs1(x+1,y,v);
	if(y<m)dfs1(x,y+1,v);
}
void dfs2(int x,int y,ll v){
//	v^=a[x][y];
	if(x+y-1==m){
		auto it=f[x].find(v^k);
		if(it!=f[x].end())ans+=it->Y;
		return;
	}
	if(x>1)dfs2(x-1,y,v^a[x][y]);
	if(y>1)dfs2(x,y-1,v^a[x][y]);
}
int main(){
	cin>>n>>m>>k;
	REP(i,1,n)REP(j,1,m)cin>>a[i][j];
	dfs1(1,1,0);dfs2(n,m,0);
	cout<<ans;
	return 0;
}