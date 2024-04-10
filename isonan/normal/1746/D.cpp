#include <bits/stdc++.h>

int t,n,a[200001],p[200001],s[200001],K;
int head[200001],nxt[400001],b[400001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int d[200001];
std::map<int,long long>map[200001];
long long getans(int x,int k){
	// printf("getans %d %d\n",x,k);
	if(map[x].count(k))return map[x][k];
	long long &p=map[x][k];
	p=1ll*s[x]*k;
	std::vector<long long>tem;
	for(int i=head[x];i;i=nxt[i]){
		long long t=getans(b[i],k/d[x]);
		p+=t;
		if(k%d[x]!=0)tem.push_back(getans(b[i],(k+d[x]-1)/d[x])-t);
	}
	std::sort(tem.begin(),tem.end());
	if(d[x]>0)
		for(int j=k%d[x];j;--j){
			p+=tem.back();
			tem.pop_back();
		}
	return p;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;++i)d[i]=head[i]=0;
		k=0;
		for(int i=2;i<=n;++i){
			int p;
			scanf("%d",&p);
			d[p]++;
			push(p,i);
		}
		for(int i=1,tem;i<=n;++i){
			scanf("%d",s+i);
			map[i].clear();
		}
		printf("%lld\n",getans(1,K));
	}
}