#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=101000,maxk=20100;
int n,k;
long long ans;
int head[maxn],rdc[maxn<<1],nxt[maxn<<1],tnt;
int size[maxn],del[maxn],fa[maxn],dis[maxn],rt,trsize;
int sum[maxk],buck[maxn<<1],clr[maxn<<1],top;
bool vis[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void addedge(int u,int v){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
}
int lowbit(int p){
	return p&-p;
}
void getrt(int p){
	size[p]=1;del[p]=0;
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=fa[p]&&!vis[rdc[i]]){
			fa[rdc[i]]=p;
			getrt(rdc[i]);
			del[p]=max(del[p],size[rdc[i]]);
			size[p]+=size[rdc[i]];
		}
	del[p]=max(del[p],trsize-size[p]);
	if(del[p]<del[rt])
		rt=p;
}
void getlen(int p){
	if(dis[p]>k)return;
	buck[++buck[0]]=dis[p];
	for(register int i=head[p];i;i=nxt[i])
		if(rdc[i]!=fa[p]&&!vis[rdc[i]]){
			dis[rdc[i]]=1+dis[p];
			fa[rdc[i]]=p;
			getlen(rdc[i]);
		}
}
void conquer(int p){
	size[fa[p]]=trsize-size[p];
	fa[fa[p]]=p;
	vis[p]=true;
	for(register int i=head[p];i;i=nxt[i])
		if(!vis[rdc[i]]){
			dis[rdc[i]]=1;buck[0]=0;
			getlen(rdc[i]);
			for(register int j=1;j<=buck[0];++j)
				ans+=sum[k-buck[j]];
			for(register int j=1;j<=buck[0];++j)
				++sum[buck[j]],clr[++top]=buck[j];
		}
	while(top)
		sum[clr[top]]=0,--top;
	for(register int i=head[p];i;i=nxt[i])
		if(!vis[rdc[i]]){
			trsize=size[rdc[i]];
			del[rt=0]=n+1;
			getrt(rdc[i]);
			conquer(rt);
		}
}
int main(){
	n=read();k=read();
	for(register int i=1,x,y,z;i<n;++i){
		x=read();y=read();
		addedge(x,y);addedge(y,x);
	}
	sum[0]=1;
	del[rt=0]=n+1;trsize=n;
	getrt(1);
	conquer(rt);
	printf("%I64d",ans);
	return 0;
}