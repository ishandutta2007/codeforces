#include <algorithm>
#include <cstdio>
#include <cmath>
//#define double long double
using std::pow;
using std::sqrt;

using std::max;

const int lim=5,lim2=20;
double w[200001],v[400001],val[400001],tot,fin,ans=1e20;
int n,head[200001],nxt[400001],b[400001],k,size[200001],mx[200001],full,root,stk[200001],top,prime[1000001],pos;
bool pri[1000001];
bool vis[200001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])getroot(b[i],x),mx[x]=max(mx[x],size[b[i]]),size[x]+=size[b[i]];
	mx[x]=max(mx[x],full-size[x]);
	if(mx[x]<mx[root])root=x;
}
void getans(int x,int f,double dis,int add){
	fin+=w[x]*sqrt(dis)*(double)dis;
	val[add]+=w[x]*sqrt(dis)*2.;
	tot+=w[x]*sqrt(dis);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getans(b[i],x,dis+(double)v[i],add);
}
void getsize(int x,int f){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])getsize(b[i],x),size[x]+=size[b[i]];
}
void solve(int rt){
	if(vis[rt])return;
	vis[rt]=1;
	tot=fin=0.;
	for(int i=head[rt];i;i=nxt[i]){
		val[b[i]]=0.;
		getans(b[i],rt,v[i],b[i]);
	}
	if(fin<ans)ans=fin,pos=rt;
	for(int i=head[rt];i;i=nxt[i])
		if(tot<val[b[i]]){
			getsize(b[i],rt);
			mx[root=0]=full=size[b[i]];
			getroot(b[i],rt);
			solve(root);
			return;
		}
}
void get(int x,int f,double dis){
	tot+=pow(dis,1.5)*w[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)get(b[i],x,dis+(double)v[i]);
}
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",w+i);
	for(int i=1,s,t,val;i<n;i++){
		s=read(),t=read(),val=read();
		push(s,t,val);
		push(t,s,val);
	}
	mx[root=0]=full=n;
	getroot(1,0);
	solve(root);
	printf("%d %.10lf\n",pos,ans);
}