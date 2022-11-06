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
vector<pii> ans;
const int N=4e5+7;
int n,d,k,cnt,deg[N],lim[N];
void out(){
	puts("YES");
	for(auto p:ans)printf("%d %d\n",p.X,p.Y);
	exit(0);
}
void dfs(int x){
	if(lim[x])REP(i,deg[x]+1,k){
		ans.push_back({x,++cnt});
		if(cnt==n)out();
		lim[cnt]=lim[x]-1;deg[cnt]=1;
		dfs(cnt);
	}
}
int main(){
	cin>>n>>d>>k;
	if(d>=n||k==1&&d>1)return puts("NO"),0;
	REP(i,1,d)ans.pb({i,i+1}),lim[i]=min(i-1,d+1-i);
	REP(i,2,d)deg[i]=2;deg[1]=deg[d+1]=1;
	cnt=d+1;if(cnt==n)out();
	REP(i,2,d)dfs(i);
	
	puts("NO");
	return 0;
}