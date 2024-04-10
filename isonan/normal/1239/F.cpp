#include <cstdio>
#include <algorithm>

int T,n,m,head[500001],nxt[1000001],b[1000001],d[500001],k,cnt[3];
int dis[500001],q[500001],h,t,pre[500001],Nxt[500001],sum[500001],p,fa[500001],size[500001],full;
bool vis[500001],ans[500001],val[500001],did;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int dfn[500001],now,stk[500010],top;
int have;
void get(int x,int f){
//	printf("get %d %d\n",x,f);
	if(have)return;
	stk[++top]=x;
	dfn[x]=++now;
	int con=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=p)
			if(dfn[b[i]]&&b[i]!=f){
				if(!con||dfn[con]<dfn[b[i]])con=b[i];
			}
	if(have)return;
	if(con&&dfn[con]<dfn[x]){
		for(int i=1;i<=n;i++)ans[i]=0;
		do{
			ans[stk[top]]=1;
			--top;
		}while(stk[top+1]!=con);
		have=1;
		return;
	}
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=p)
			if(!dfn[b[i]]){
				get(b[i],x);
			}
	--top;
}
void getpath(int x,int f){
//	printf("getpath %d %d\n",x,f);
	ans[x]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&b[i]!=p){
			if(val[b[i]]){
				ans[b[i]]=1;
				return;
			} 
			getpath(b[i],x);
			return;
		}
}
void mark(int x,int f){
	if(vis[x])return;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
		mark(b[i],x);
}
void init(int x,int f){
	size[x]=val[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			init(b[i],x);
			size[x]+=size[b[i]];
		}
}
void getany(int x,int f){
	if(val[x]){
		getpath(x,f);
		return;
	}
	int cnt=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)++cnt;
	if(cnt>1){
		cnt=2;
		ans[x]=1;
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f&&b[i]!=p){
				getpath(b[i],x);
				--cnt;
				if(!cnt)return;
			}
	}
	else
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f&&b[i]!=p)getany(b[i],x);
}
void getans(int x,int f){
	if(did)return;
	size[x]=val[x];
	int cnt=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&b[i]!=p){
			getans(b[i],x);
			size[x]+=size[b[i]];
			if(size[b[i]]>1)++cnt;
		}
	if(full-size[x]>1)++cnt;
	if(did)return;
	if(cnt>1){
		cnt=2;
		did=1;
		for(int i=head[x];i;i=nxt[i])
			if(b[i]!=f&&b[i]!=p&&size[b[i]]>1){
				getany(b[i],x);
				--cnt;
				if(!cnt)return;
			}
		if(cnt&&full-size[x]>1){
			init(f,x);
			getany(f,x);
			return;
		}
	}
}
void solve(int fd){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)head[i]=d[i]=0;
	k=0;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v),++d[u],++d[v],push(u,v),push(v,u);
//		if(fd==186){
//			printf("%d %d\n",u,v);
//		}
	}
//	if(T>20)return;
	if(n<=3){
		puts("No");
		return;
	}
	for(int i=0;i<3;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)++cnt[d[i]%3];
	if(cnt[0]){
		for(int i=1;i<=n;i++)
			if(d[i]%3==0){
				printf("Yes\n%d\n",n-1);
				for(int j=1;j<=n;j++)
					if(i!=j)printf("%d ",j);
				putchar('\n');
				return;
			}
	}
//	return;
//	for(int i=1;i<=n;i++)printf("%d %d\n",i,d[i]%3);
	if(cnt[1]>1){
		h=t=0;
		for(int i=1;i<=n;i++)dis[i]=-1,pre[i]=0;
		int p=0;
		for(int i=1;i<=n;i++)
			if(d[i]%3==1){
				p=i;
				break;
			}
		q[++t]=p;
		dis[p]=0;
		while(h<t){
			++h;
//			printf("%d %d\n",q[h],dis[q[h]]); 
			for(int i=head[q[h]];i;i=nxt[i])
				if(!~dis[b[i]]){
					dis[b[i]]=dis[q[h]]+1;
					pre[b[i]]=q[h];
					q[++t]=b[i];
					if(d[b[i]]%3==1){
						if(dis[b[i]]==n-1){
							puts("No");
							return;
						}
						else{
							printf("Yes\n%d\n",n-dis[b[i]]-1);
							for(int j=1;j<=n;j++)vis[j]=0;
							for(int j=b[i];j;j=pre[j])vis[j]=1;
							for(int j=1;j<=n;j++)if(!vis[j])printf("%d ",j);
							putchar('\n');
							return;
						}
					}
				}
		}
	}
	p=0;
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=-1,pre[i]=0,dfn[i]=0;
	have=0;
	for(int i=1;i<=n;i++)if(d[i]%3==1)p=i;
	for(int i=head[p];i;i=nxt[i])--d[b[i]];
	vis[p]=1;
	h=t=0;
	for(int i=1;i<=n;i++)if(i!=p&&d[i]==1)q[++t]=i;
	while(h<t){
		++h;
		vis[q[h]]=1;
		for(int i=head[q[h]];i;i=nxt[i])
			if(b[i]!=p){
				--d[b[i]];
				if(d[b[i]]==1&&!vis[b[i]])q[++t]=b[i];
			}
	}
	top=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			now=0;
			for(int j=1;j<=n;j++)ans[j]=0;
			get(i,0);	
			int cnt=0;
			for(int j=1;j<=n;j++)if(!ans[j])++cnt;
//			printf("%d\n",cnt);
//			putchar('*');
			if(!cnt||cnt==n){
				puts("No");
				return;
			}
			printf("Yes\n%d\n",cnt);
			for(int j=1;j<=n;j++)if(!ans[j])printf("%d ",j);
			putchar('\n');
			return;
		}
	if(!p){
		puts("No");
		return;
	}
//	putchar('*');
//	putchar('*');
	for(int i=1;i<=n;i++)d[i]=val[i]=vis[i]=0;
	for(int i=1;i<=n;i++)
		if(i!=p)for(int j=head[i];j;j=nxt[j])++d[b[j]];
		else for(int j=head[i];j;j=nxt[j])val[b[j]]=1;
	vis[p]=1;
	int p2=0;
//	putchar('*');
//	printf("%d\n",p);
	for(int i=1;i<=n;i++)
		if(d[i]==1&&!vis[i]){
			if(p2){
				for(int i=1;i<=n;i++)ans[i]=0;
				getpath(p2,0);
				getpath(i,0);
				ans[p]=1;
				int cnt=0;
				for(int i=1;i<=n;i++)if(!ans[i])++cnt;
				if(!cnt){
					puts("No");
					return;
				}
				printf("Yes\n%d\n",cnt);
				for(int i=1;i<=n;i++)if(!ans[i])printf("%d ",i);
				putchar('\n');
				return;
			}
			p2=i;
			mark(p2,0);
		}
//	putchar('*');
	for(int i=1;i<=n;i++)ans[i]=0;
	full=0;
	for(int i=head[p];i;i=nxt[i])full++;
	did=0;
	if(p){
		getans(p2,0);
		if(did){
			int cnt=0;
			ans[p]=1;
			for(int i=1;i<=n;i++)if(!ans[i])++cnt;
			printf("Yes\n%d\n",cnt);
			for(int i=1;i<=n;i++)if(!ans[i])printf("%d ",i);
			putchar('\n');
			return;
		}
	}
	puts("No");
}
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++)solve(fd);
}
//1
//10 13
//1 2
//2 3
//3 4x
//4 1
//3 5
//5 6
//3 6
//3 7
//7 8
//3 8
//3 9
//9 10
//3 10