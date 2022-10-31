// Hydro submission #6289ed3760218028ca5d72ef@1653206327627
#include<queue>
#include<queue>
#include<cstdio>
#include<cstring>
#define db double
#define gc getchar
#define pc putchar
#define U unsigned
#define ll long long
#define ld long double
#define ull unsigned long long
#define Tp template<typename _T>
#define Me(a,b) memset(a,b,sizeof(a))
Tp _T mabs(_T a){ return a>0?a:-a; }
Tp _T mmax(_T a,_T b){ return a>b?a:b; }
Tp _T mmin(_T a,_T b){ return a<b?a:b; }
Tp void mswap(_T &a,_T &b){ _T tmp=a; a=b; b=tmp; return; }
Tp void print(_T x){ if(x<0) pc('-'),x=-x; if(x>9) print(x/10); pc((x%10)+48); return; }
#define EPS (1e-7)
#define INF (0x7fffffff)
#define LL_INF (0x7fffffffffffffff)
#define maxn 500039
#define maxm
#define MOD
#define Type int
#ifndef ONLINE_JUDGE
//#define debug
#endif
using namespace std;
Type read(){
	char c=gc(); Type s=0; int flag=0;
	while((c<'0'||c>'9')&&c!='-') c=gc(); if(c=='-') c=gc(),flag=1;
	while('0'<=c&&c<='9'){ s=(s<<1)+(s<<3)+(c^48); c=gc(); }
	if(flag) return -s; return s;
}
int n,m,x,y,z,head[maxn],nex[maxn],to[maxn],c[maxn],kkk;
#define add(x,y,z) nex[++kkk]=head[x]; head[x]=kkk; to[kkk]=y; c[kkk]=z
queue<int> q; int dis[maxn],col[maxn],vis[maxn];
int main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(); m=read(); int i,cur; if(n==1){ printf("0\n0"); return 0; }
	for(i=1;i<=m;i++){ x=read(); y=read(); z=read(); add(y,x,z); }
	Me(col,-1); vis[n]=dis[n]=0; q.push(n);
	while(!q.empty()){
		cur=q.front(); q.pop(); if(cur==1) break;
		for(i=head[cur];i;i=nex[i]){
			if(vis[to[i]]) continue;
			if(col[to[i]]==-1||col[to[i]]==1-c[i]) col[to[i]]=1-c[i];
			else q.push(to[i]),vis[to[i]]=1,dis[to[i]]=dis[cur]+1;
		}
	} print(dis[1]?dis[1]:-1),pc('\n');
	for(i=1;i<=n;i++) print(col[i]==-1?0:col[i]);
	return 0;
}
/////////