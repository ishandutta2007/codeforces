#include <cstdio>
#include <vector> 

int n,K,cnt[300001][3],head[300001],nxt[600001],b[600001],v[600001],k,ans;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int vis[300001];
char str[300001];
int f[300001],s[300001],col[300001],diff[300001],g[300001],con[300001],val[300001],tot[300001];
int ope(int x,int y){return y?-x:x;}
int find(int x){
	int k=(f[x]?f[x]=find(f[x]):x);
	return k;
}
void dfs(int x,int f,int c){
//	printf("dfs %d %d %d\n",x,f,c);
	vis[x]=c;
	if(c==1)++ans;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,ope(c,v[i]));
}
void reroute(int x,int f){
	val[x]^=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)reroute(b[i],x);
}
int main(){
	scanf("%d%d",&n,&K);
	scanf("%s",str+1);
	for(int i=1,tem,b;i<=K;i++){
		scanf("%d",&tem);
		for(int j=1;j<=tem;j++){
			scanf("%d",&b);
			cnt[b][++cnt[b][0]]=i;
		}
	}
	for(int i=1;i<=K;i++)s[i]=g[i]=1;
	for(int i=1;i<=n;i++){
		if(cnt[i][0]==1){
			if(!vis[cnt[i][1]]){
				int fu=find(cnt[i][1]);
				ans-=con[fu];
				if(str[i]=='1')vis[cnt[i][1]]=-1;
				else vis[cnt[i][1]]=1;
				dfs(cnt[i][1],0,vis[cnt[i][1]]);
			}
		}
		else if(cnt[i][0]==2){
			int fu=find(cnt[i][1]),fv=find(cnt[i][2]);
			bool change=(str[i]=='0');
			if(fu!=fv){
				if(s[fu]>s[fv])std::swap(fu,fv);
				bool same=val[cnt[i][1]]^val[cnt[i][2]]^change;
				push(fv,fu,same);
				push(fu,fv,same);
				if(vis[fu]==0&&vis[fv]){
					ans-=con[fu];
//					printf("%d\n",ans); 
					dfs(fu,fv,ope(vis[fv],same));
				}
				else if(vis[fv]==0&&vis[fu]){
					ans-=con[fv];
//					printf("%d\n",ans);
					dfs(fv,fu,ope(vis[fu],same));
				}
				if(vis[fv]==0)ans-=con[fv];
				if(vis[fu]==0)ans-=con[fu];
				f[fu]=fv;
				s[fv]+=s[fu];
				g[fv]+=same?s[fu]-g[fu]:g[fu];
				if(same){
					reroute(fu,fv);
				}
				con[fv]=std::min(g[fv],s[fv]-g[fv]);
				if(vis[fv]==0)ans+=con[fv];
//				printf("%d %d %d %d %d\n",s[fv],g[fv],change,fv,con[fv]);
			}
//			for(int i=1;i<=n;i++)printf("%d %d %d\n",i,find(i),val[i]);
		}
		printf("%d\n",ans);
	}
}