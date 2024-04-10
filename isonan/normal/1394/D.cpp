#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int n,t[200001],h[200001];
int head[200001],nxt[400001],b[400001],k,f[200001][2];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	int cnt=0;
	long long sum=0;
	std::vector<long long>swi;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			sum+=f[b[i]][0];
			++cnt;
			swi.push_back(f[b[i]][1]-f[b[i]][0]);
		}
	std::sort(swi.begin(),swi.end());
	for(int i=1;i<swi.size();i++)swi[i]+=swi[i-1];
	f[x][0]=f[x][1]=1e13;
	for(int i=0;i<=swi.size();i++){
		if(F){
			f[x][0]=std::min(f[x][0],std::max(i+1,cnt-i)*t[x]+sum+(i?swi[i-1]:0));
			f[x][1]=std::min(f[x][1],std::max(i,cnt-i+1)*t[x]+sum+(i?swi[i-1]:0));
		}
		else{
			f[x][0]=std::min(f[x][0],std::max(i,cnt-i)*t[x]+sum+(i?swi[i-1]:0));
		}
	}
	if(F){
		if(h[x]>h[F])f[x][0]=1e13;
		if(h[x]<h[F])f[x][1]=1e13;
	}
//	printf("%d %lld %lld\n",x,f[x][0],f[x][1]);
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",t+i);
	for(int i=1;i<=n;i++)scanf("%lld",h+i);
	for(int i=1,u,v;i<n;i++)scanf("%lld%lld",&u,&v),push(u,v),push(v,u);
	dfs(1,0);
	printf("%lld\n",f[1][0]);
}