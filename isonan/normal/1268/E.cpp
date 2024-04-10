#include <cstdio>
#include <vector>
#include <algorithm>

int head[500001],nxt[1000001],b[1000001],k=1,n,m,stk[500010],top,cnt,dfn[500010],low[500010],now,V[500010],pre[500010];
int f[1000001],oth[1000001],edg[1000001][2],g[1000001];
std::vector<std::pair<int,int> >con[1000001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
//	printf("push %d %d %d\n",s,t,k);
}
void tarjan(int x,int f){
//	printf("tarjan %d %d\n",x,f);
	stk[++top]=x;
	V[top]=f;
	low[x]=dfn[x]=++now;
	for(int i=head[x];i;i=nxt[i])
		if((i>>1)!=(f>>1)){
			if(!dfn[b[i]]){
				tarjan(b[i],i);
				low[x]=std::min(low[x],low[b[i]]);
				if(low[b[i]]>dfn[x]){
					++cnt;
					con[x].push_back(std::make_pair(b[i],i)),--top;
				}
				if(low[b[i]]==dfn[x]){
					++cnt;
					con[x].push_back(std::make_pair(cnt,pre[stk[top]]));
					con[cnt].push_back(std::make_pair(x,pre[stk[top]]));
					while(stk[top+1]!=b[i]){
						con[cnt].push_back(std::make_pair(stk[top],V[top]));
						--top;
					}
//					for(int i=0;i<con[cnt].size();i++)printf("%d ",con[cnt][i].second);putchar('\n');
				}
			}
			else{
				low[x]=std::min(low[x],dfn[b[i]]);
//				printf("fa %d %d\n",x,b[i]);
				if(dfn[b[i]]<dfn[x])pre[x]=i;
			}
		}
}
void solve(int x){
	if(x<=n){
		for(int i=0;i<con[x].size();i++)
			solve(con[x][i].first);
	}
	else{
		int mn=0,mx=0;
		for(int i=1;i<con[x].size();i++){
			if(con[x][mn].second>con[x][i].second)mn=i;
			if(con[x][mx].second<con[x][i].second)mx=i;
			solve(con[x][i].first);
		}
		int stat=0;
		for(int i=mx;;){
			int nxt=(i==con[x].size()-1)?0:(i+1);
			if(con[x][nxt].second>con[x][i].second)break;
			i=nxt;
			if(i==mn){
				stat|=1;
				break;
			}
		}
		for(int i=mx;;){
			int nxt=(i?i:con[x].size())-1;
			if(con[x][nxt].second>con[x][i].second)break;
			i=nxt;
			if(i==mn){
				stat|=2;
				break;
			}
		}
		if(stat==3)oth[con[x][mn].second>>1]=con[x][mx].second>>1;
	}
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=1;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),push(u,v),push(v,u),edg[i][0]=u,edg[i][1]=v;
	cnt=n;
	tarjan(1,0);
	solve(1);
	for(int i=m;i;i--)
		g[i]=f[edg[i][0]]=(f[edg[i][1]]+=f[edg[i][0]]-g[oth[i]]);
	for(int i=1;i<=n;i++)printf("%d ",f[i]-1);
}