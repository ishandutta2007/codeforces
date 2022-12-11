#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int mod=998244353;
const int maxn=201000;
int n,m,k,ans;
int cntd[maxn],cntdc[maxn];
int dve[10][10],pm[maxn],stdhash;
priority_queue <pair<int,int> > pq[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int mmod(int p){
	return p>=mod?p-mod:p;
}
void dfs(int p,int phash){
	if(p==k+1){
		ans+=(stdhash==phash);
		return;
	}
	for(register int i=1;i<=p;++i)
		dfs(p+1,mmod(phash+dve[p][i]));
}
int main(){
	n=read();m=read();k=read();
	for(register int i=1,u,v,z;i<=m;++i){
		u=read();v=read();z=read();
		pq[u].push(make_pair(z,v));
		++cntd[u];
	}
	pm[0]=1;
	for(register int i=1;i<=n;++i){
		pm[i]=mmod(pm[i-1]<<1);
		cntdc[i]=cntd[i];
		stdhash=mmod(stdhash+pm[i]);
	}
	for(register int i=1;i<=n;++i)
		while(cntdc[i]){
			dve[cntd[i]][cntdc[i]]=mmod(dve[cntd[i]][cntdc[i]]+pm[pq[i].top().second]);
			--cntdc[i];
			pq[i].pop();
		}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}