#include <cstdio>
#include <map> 

std::map<long long,int>map;
int n,head[100010],nxt[200001],b[200001],k;
long long x[100010],ans;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
void dfs(int x,int f,std::map<long long,int>map){
	++map[0];
	std::map<long long,int>tem;
	for(std::map<long long,int>::iterator it=map.begin();it!=map.end();++it)
		tem[gcd(it->first,::x[x])]+=(it->second),ans+=1ll*gcd(it->first,::x[x])*(it->second);
	ans%=1000000007;
	map.clear();
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,tem);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",x+i);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
	}
	dfs(1,0,map);
	printf("%I64d\n",ans%1000000007);
}