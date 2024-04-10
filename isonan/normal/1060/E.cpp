#include <cstdio>
#include <iostream>

long long head[200001],nxt[400001],b[400001],k,n,m,s,t,f[200001][2];
long long size[400001];
long long sum;
void push(long long s,long long t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(long long x,long long F){
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			size[x]+=size[b[i]];
			sum+=size[b[i]]*(n-size[b[i]]);
			f[x][0]+=f[b[i]][1];
			f[x][1]+=f[b[i]][0];
		}
	f[x][0]++;
}
int main(){
	std::cin>>n;
	for(int i=1;i<n;i++){
		std::cin>>s>>t;
		push(s,t);
		push(t,s);
	}
	dfs(1,0);
	std::cout<<((1+sum+(f[1][0]*f[1][1]))>>1);
}