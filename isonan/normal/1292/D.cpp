#include <cstdio>
#include <algorithm>
#define int long long
 
int head[1000001],nxt[2000001],b[2000001],v[2000001],k,n,K[1000001],Cnt[1000001],stk[1000001],node[1000001],top,tot[200001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int prime[100001],Top,root,cnt,len[100001],pre[5001][5001];
bool pri[100001];
long long dis[1000001],s[1000001],size[1000001];
void dfs(int x,int f){
	size[x]=tot[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs(b[i],x);
			dis[x]+=dis[b[i]]+1ll*size[b[i]]*v[i];
			size[x]+=size[b[i]];
		}
}
void getans(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dis[b[i]]=dis[x]+1ll*(n-(size[b[i]])*2ll)*v[i];
			getans(b[i],x);
		}
}
int getf(int x,int y){
	int ans=0;
	while(y%x==0)y/=x,++ans;
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for(int i=2;i<=5000;i++){
		if(!pri[i])prime[++Top]=i;
		for(int j=1;j<=Top&&i*prime[j]<=5000;j++){
			pri[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=n;i++)scanf("%lld",K+i),++Cnt[K[i]?K[i]:1];
	root=++cnt;
	tot[root]=Cnt[1];
	stk[++top]=0;
	node[top]=1;
	len[1]=0;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=Top;j++)
			pre[i][j]=pre[i-1][j]+getf(prime[j],i);
	for(int i=2;i<=5000;i++){
		int length=0;
		for(int j=1;j<=Top;j++)len[i]+=pre[i][j];
		for(int j=Top;j;j--){
			int cnti=pre[i][j],cntp=pre[i-1][j];
			if(cnti!=cntp){
				length+=std::min(cnti,cntp);
				break;
			}
			else length+=cnti;
		}
		while(top>1&&stk[top-1]>=length){
			push(node[top-1],node[top],stk[top]-stk[top-1]);
			--top;
		}
		int p=++cnt;
		if(stk[top]>length)push(p,node[top],stk[top]-length),--top;
		if(stk[top]==length){
			stk[++top]=len[i];
			--cnt;
		}
		else{
			stk[++top]=length;
			node[top]=p;
			stk[++top]=len[i];
		}
		::tot[node[top]=++cnt]=Cnt[i];
	}
	while(top>1){
			push(node[top-1],node[top],stk[top]-stk[top-1]);
			--top;
			
	}
	dfs(1,0);
	getans(1,0);
	long long ans=dis[1];
	for(int i=1;i<=cnt;i++)ans=std::min(ans,dis[i]);
	printf("%lld\n",ans);
}