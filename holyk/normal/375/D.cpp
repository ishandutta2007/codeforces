#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=1e5+7;
int n,m,c[N];
vector<int> g[N];
struct ask{int x,id;};
vector<ask> q[N];
int siz[N];
void dfsp(int x,int f){
	siz[x]=1;
	for(int y:g[x])if(y!=f)dfsp(y,x),siz[x]+=siz[y];
}
int ans[N],cnt[N];

int t[N];
void update(int p,int x){
	if(!p)return;
	while(p<=n)t[p]+=x,p+=p&-p;
}
int query(int p){
	int ans=0;if(p>n)p=n;
	while(p)ans+=t[p],p-=p&-p;
	return ans;
}

void add(int x,int f,int w){
	update(cnt[c[x]],-1);update(cnt[c[x]]+=w,1);
	for(int y:g[x])if(y!=f)add(y,x,w);
}
void dfs(int x,int f){
	int son=0;
	for(int y:g[x])if(y!=f&&siz[y]>siz[son])son=y;
	for(int y:g[x])if(y!=f&&y!=son)dfs(y,x),add(y,x,-1);
	if(son)dfs(son,x);
	for(int y:g[x])if(y!=f&&y!=son)add(y,x,1);
	update(cnt[c[x]],-1);update(++cnt[c[x]],1);
	for(auto k:q[x])ans[k.id]=query(n)-query(k.x-1);
}
int main(){
	n=read(),m=read();
	REP(i,1,n)c[i]=read();
	REP(i,2,n){
		int x=read(),y=read();g[x].push_back(y);g[y].push_back(x);
	}
	REP(i,1,m){int x=read();q[x].push_back({read(),i});}
	memset(t,0,sizeof t);
	dfsp(1,0);dfs(1,0);
	REP(i,1,m)printf("%d\n",ans[i]);
	return 0;
}