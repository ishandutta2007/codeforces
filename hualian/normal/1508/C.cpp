#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int FFFF;
bool pppp;
struct edge{
	int x,y,w;
	bool operator<(const edge&X)const{
		return w<X.w;
	}
}e[2*N];
int n,m,cnt,sum,ans,res;
int fa[N];
int sz[N];
signed get(int x){
	return fa[x]==x?x:(fa[x]=(get(fa[x])));
}
inline bool merge(int x,int y){
	int tx=get(fa[x]),ty=get(fa[y]);
	if(tx==ty)return false;
	fa[tx]=ty;
	cnt--;
	return true;
}
struct node{
	signed nt,x,pre;
}a[N];
map<signed,bool>mp[N];
int vis[N];
namespace tree{
	struct EDGE{
		signed pre,to,w;
	}e[2*N];
	signed last[N],dep[N];
	signed idx;
	signed fa[N][22];
	bool v[N][22];
	inline void add(int x,int y,int w){
		e[++idx].pre=last[x];
		e[idx].to=y;
		e[idx].w=w;
		last[x]=idx;
	}
	void dfs(int x,int f){
		dep[x]=dep[f]+1;
		fa[x][0]=f;
		for(int i=1;i<=20;i++){
			fa[x][i]=fa[fa[x][i-1]][i-1];
			v[x][i]=v[x][i-1]|v[fa[x][i-1]][i-1];
		}for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;if(to==f)continue;
			if(e[i].w)v[to][0]=1;
			dfs(to,x);
		}
	}
	bool LCA(int x,int y){
		int ans=0;
		if(dep[x]<dep[y])swap(x,y);
		for(int i=20;i>=0;i--){
			if(dep[fa[x][i]]>=y)ans|=v[x][i],x=fa[x][i];
		}
		if(x==y)return ans;
		for(int i=20;i>=1;i--){
			if(fa[x][i]==fa[y][i])continue;
			ans|=v[x][i]|v[y][i];
			x=fa[x][i],y=fa[y][i];
		}
		ans|=v[x][0]|v[y][0];
		return ans;
	}
}
bool ppppp;
int rd[N];
signed main(){
//	printf("%.5lf",(&ppppp-&pppp)/1024.0/1024.0);
	n=read(),m=read();cnt=n;sum=n*(n-1)/2-m;
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),w=read();
		e[i]=(edge){x,y,w};
		rd[x]++,rd[y]++;
		mp[x][y]=1;
		mp[y][x]=1;
		res^=w;
	}
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,mp[i][i]=1;
	int son=0;rd[0]=1e18;
	for(int i=1;i<=n;i++)
		if(rd[i]<rd[son])son=i;
	for(int i=1;i<=n;i++)if(!mp[i][son])if(merge(i,son))sum--,tree::add(i,son,1),tree::add(son,i,1);
	for(int i=1;i<=n;i++){
		if(get(i)==get(son))continue;
		for(int j=1;j<=n;j++){
			if(!mp[i][j])if(merge(i,j))sum--,tree::add(i,j,1),tree::add(j,i,1);
		}
	}
	if(cnt==1&&(sum||res==0)){puts("0");return 0;}
//	if(m==199800)cout<<cnt<<" "<<sum<<" "<<res<<endl;
	sort(e+1,e+1+m);
	for(int i=0;i<=m;i++){
		if(merge(e[i].x,e[i].y)){
			ans+=e[i].w;
			tree::add(e[i].x,e[i].y,0);
			tree::add(e[i].y,e[i].x,0);
			vis[i]=1;
		}
		if(cnt==1){
			if(sum){cout<<ans<<endl;return 0;}
			tree::dfs(1,0);
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[i])continue;
		int ok=tree::LCA(e[i].x,e[i].y);
		if(ok){
			printf("%lld\n",ans+min(res,e[i].w));
			return 0;
		}
	}
	
	return 0;
}