#include <cstdio>
#include <algorithm>

int n,m,q;
int head[200001],nxt[400001],b[400001],v[400001],k;
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
int ans[200001];
int low[200001],dfn[200001],now,stk[200001],top,S;
bool instack[200001];
long long Gcd[200001];
long long gcd(long long a,long long b){
	if(a<0&&b<0)return -gcd(-a,-b);
	if(!b)return a;
	if(!a)return b;
	if(a<0)return gcd(a+1ll*(((-a)+b-1)/b)*b,b);
	if(b<0)return gcd(b+1ll*((a+(-b)-1)/a)*a,a);
	return gcd(b,a%b);
}
void tarjan(int x){
//	printf("tarjan %d\n",x);
	instack[x]=1;
	stk[++top]=x;
	low[x]=dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if(i&1){
			if(!dfn[b[i]]){
				tarjan(b[i]);
				low[x]=std::min(low[x],low[b[i]]);
			}
			else if(instack[b[i]]){
				low[x]=std::min(low[x],dfn[b[i]]);
			}
		}
	if(low[x]==dfn[x]){
		++S;
		do{
			ans[stk[top]]=S;
			instack[stk[top]]=0;
			--top;
//			printf("%d\n",top);
		}while(stk[top+1]!=x);
//		putchar('&');
	}
//	printf("%d\n",x);
}
int vis[200001];
long long val[200001];
void dfs(int x,int f,int now){
//	printf("dfs %d %d %d\n",x,f,now);
	vis[x]=++::now;
	for(int i=head[x];i;i=nxt[i])
		if(i&1){
			if(ans[b[i]]==now){
				if(!vis[b[i]]){
					val[b[i]]=val[x]+v[i];
					dfs(b[i],x,now);
				}
				else if(vis[b[i]]<vis[x]){
//					printf("%d %d\n",now,val[x]-val[b[i]]+v[i]);
					Gcd[now]=gcd(Gcd[now],val[x]-val[b[i]]+v[i]);
				}
			}
		}
	for(int i=head[x];i;i=nxt[i])
		if(i%2==0){
			if(ans[b[i]]==now){
				if(!vis[b[i]]){
					val[b[i]]=val[x]+v[i];
					dfs(b[i],x,now);
				}
				else if(vis[b[i]]<vis[x]){
//					printf("%d %d\n",now,val[x]-val[b[i]]+v[i]);
					Gcd[now]=gcd(Gcd[now],val[x]-val[b[i]]+v[i]);
				}
			}
		}
//	printf("end %d\n",x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,l;i<=m;++i){
		scanf("%d%d%d",&u,&v,&l);
		push(u,v,l);
		push(v,u,-l);
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;++i)
		if(low[i]==dfn[i])dfs(i,0,ans[i]);
	scanf("%d",&q);
	for(int i=1,v,s,t;i<=q;++i){
		scanf("%d%d%d",&v,&s,&t);
		s=t-s;
//		printf("%d %d %d\n",s,t,Gcd[ans[v]]);
		if(gcd(t,s)%gcd(Gcd[ans[v]],t)==0)puts("YES");
		else puts("NO");
	}
}