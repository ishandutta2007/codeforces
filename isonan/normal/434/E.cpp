#include <cstdio>
#include <map>

using std::max;

std::map<int,int>map;
int n,Y,K,X,head[100001],nxt[200001],b[200001],power[100001],powe[100001],k,mx[100001],size[100001],root,full,stk[100001],top,inv[100001],v[100001];
long long ans1[100001],ans[100001];
bool vis[100001];
int mul(int a,int b){return 1ll*a*b%Y;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			getroot(b[i],x),size[x]+=size[b[i]],mx[x]=max(mx[x],size[b[i]]);
	mx[x]=max(mx[x],full-size[x]);
	if(mx[x]<mx[root])root=x;
}
void getans(int x,int f,int dis,int val){
	ans[x]+=map[mul(inv[dis],(X+Y-val)%Y)];
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			getans(b[i],x,dis+1,(mul(val,K)+v[b[i]])%Y),size[x]+=size[b[i]];
}
void setans(int x,int f,int dis,int val){
	++map[val];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			setans(b[i],x,dis+1,(val+mul(v[b[i]],powe[dis]))%Y);
}
void getans2(int x,int f,int dis,int val){
	ans1[x]+=map[val];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			getans2(b[i],x,dis+1,(val+mul(v[b[i]],powe[dis]))%Y);
}
void setans2(int x,int f,int dis,int val){
	++map[mul(X+Y-val,inv[dis])];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])
			setans2(b[i],x,dis+1,(mul(val,K)+v[b[i]])%Y);
}
void solve(int rt){
	vis[rt]=1;
	top=0;
	ans[rt]+=v[rt]==X;
	ans1[rt]+=v[rt]==X;
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]])stk[++top]=b[i];
	map.clear();
	for(int i=1;i<=top;i++)
		getans(stk[i],rt,1,v[stk[i]]),setans(stk[i],rt,2,(v[rt]+mul(v[stk[i]],K))%Y);
	ans[rt]+=map[X];
	map.clear();
	map[v[rt]]=1;
	for(int i=top;i;--i)
		getans(stk[i],rt,1,v[stk[i]]),setans(stk[i],rt,2,(v[rt]+mul(v[stk[i]],K))%Y);
		
	map.clear();
	for(int i=1;i<=top;i++)
		getans2(stk[i],rt,2,(v[rt]+mul(v[stk[i]],K))%Y),setans2(stk[i],rt,1,v[stk[i]]);
	ans1[rt]+=map[v[rt]];
	map.clear();
	map[X]=1;
	for(int i=top;i;--i)
		getans2(stk[i],rt,2,(v[rt]+mul(v[stk[i]],K))%Y),setans2(stk[i],rt,1,v[stk[i]]);
		
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]]){
			mx[root=0]=full=size[b[i]];
			getroot(b[i],rt);
			solve(root);
		}
}
int main(){
	scanf("%d%d%d%d",&n,&Y,&K,&X);
	powe[0]=1;
	for(int i=1;i<=n;i++)powe[i]=mul(powe[i-1],K);
	inv[0]=1;inv[1]=qsm(K,Y-2);
	for(int i=2;i<=n;i++)inv[i]=mul(inv[i-1],inv[1]);
	for(int i=1;i<=n;i++)scanf("%d",v+i);
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	mx[root=0]=full=n;
	getroot(1,0);
	solve(root);
	long long tot=0;
	for(int i=1;i<=n;i++){
		tot+=2ll*ans[i]*(n-ans[i])+2ll*ans1[i]*(n-ans1[i])+ans[i]*(n-ans1[i])+ans1[i]*(n-ans[i]);
	}
	printf("%I64d",1ll*n*n*n-(tot>>1ll));
}