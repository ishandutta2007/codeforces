#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define int long long

int n,m;
long long que[50001][3],L[200010],top;
std::vector<int>con[200010];
bool vis[200010],vis2[200010];
char str[11];
long long f(long long x){
	if(!(x&(x-1)))return x;
	return f(x&(x-1));
}
int fa[200010];
int find(int x){
	return fa[x]?fa[x]=find(fa[x]):x;
}
void add(int x){
	vis2[x]=1;
	for(int i=0;i<con[x].size();++i){
		if(!vis2[con[x][i]])continue;
		int u=find(x),v=find(con[x][i]);
		if(u!=v)fa[u]=v;
	}
}
int ans[50001],at;
signed main(){
	scanf("%lld%lld",&n,&m);
	L[++top]=0;
	for(int i=1;i<=m;++i){
		scanf("%s%lld%lld",str+1,&que[i][1],&que[i][2]);
		que[i][0]=str[1]=='b';
		if(que[i][0]){
			L[++top]=que[i][1];
			L[++top]=que[i][2]+1;
		}
	}
	std::sort(L+1,L+top+1);
	int now=top;
	L[++top]=1ll<<n;
	for(int i=1;i<=now;++i){
		long long l=L[i],r=L[i+1]-1,x=f(l^r);
		if(l==r||(!(l&(x-1))))continue;
		L[++top]=(l^(l&(x-1)))|x;
	}
	std::sort(L+1,L+top+1);
	--top;
	for(int i=0;i<n;++i)
		for(int j=0;j<2;++j){
			for(int k=1,now=1;k<=top;++k){
				long long l=L[k],r=L[k+1]-1,v;
				if(((l>>i)&1)==j)v=l;
				else v=((l>>i)+1)<<i;
				if(v<=r){
					v^=1ll<<i;
					while(v>=L[now+1])++now;
					con[k].push_back(now);
					con[now].push_back(k);
				}
			}
		}
	for(int i=m;i;--i)
		if(que[i][0]){
			long long l=que[i][1],r=que[i][2]+1;
			int p=std::lower_bound(L+1,L+top+1,r)-L-1;
			for(;p&&L[p]>=l;--p)vis[p]=1;
		}
	for(int i=1;i<=top;++i)if(!vis[i])add(i);
	for(int i=m;i;--i)
		if(que[i][0]){
			long long l=que[i][1],r=que[i][2]+1;
			int p=std::lower_bound(L+1,L+top+1,r)-L-1;
			for(;p&&L[p]>=l;--p)add(p);
		}
		else{
			long long a=std::upper_bound(L+1,L+top+1,que[i][1])-L-1,b=std::upper_bound(L+1,L+top+1,que[i][2])-L-1;
			ans[++at]=find(a)==find(b);
		}
	for(int i=at;i;--i)printf("%d\n",ans[i]);
}