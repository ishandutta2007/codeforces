#include<bits/stdc++.h>
#define lson o<<1
#define rson o<<1|1
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=2e5+7;
int n,m,w[N],tot,head[N],v[N<<1],nxt[N<<1],cnt,in[N],out[N],dep[N];
inline void adde(int x,int y){v[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x){
	in[x]=++cnt;
	for(int i=head[x];i;i=nxt[i]){
		int &y=v[i];if(!in[y])dep[y]=dep[x]+1,dfs(y);
	}
	out[x]=cnt;
}
int a[N],b[N];
inline void add(int*c,int p,int x){if(p)while(p<=n)c[p]+=x,p+=p&-p;}
inline int query(int*c,int p){
	int ret=0;
	while(p)ret+=c[p],p-=p&-p;
	return ret;
}
int main(){
	n=read(),m=read();
	REP(i,1,n)w[i]=read();
	REP(i,2,n){
		int x=read(),y=read();
		adde(x,y);adde(y,x);
	}
	dep[1]=1;dfs(1);
	while(m--){
		int q=read(),x=read();
		if(q==1){
			int k=read();
			if(dep[x]&1)add(a,in[x],k),add(a,out[x]+1,-k);
			else add(b,in[x],k),add(b,out[x]+1,-k);
		}
		else{
			if(dep[x]&1)printf("%d\n",w[x]+query(a,in[x])-query(b,in[x]));
			else printf("%d\n",w[x]+query(b,in[x])-query(a,in[x]));
		}
	}
	return 0;
}