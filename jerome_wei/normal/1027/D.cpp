#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=2e5+5,M=5e5+5;
int n,m;
int hed[N],nxt[M],to[M];
int cnt;
void adde(int u,int v){
    cnt++;
    nxt[cnt]=hed[u],to[cnt]=v;
    hed[u]=cnt;
}
int val[N];
int de[N],co[N],low[N],dfn[N],si[N];
int col;
int num;
int st[N+M],top=0;
void Tarjan(int u){
    dfn[u]=low[u]=++num;
    st[++top]=u;
    for(int i=hed[u];i;i=nxt[i]){
	int v=to[i];
	if(!dfn[v]){
	    Tarjan(v);
	    low[u]=min(low[u],low[v]);
	}
	else
	    if(!co[v])
		low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
	co[u]=++col;
	++si[col];
	while(st[top]!=u){
	    ++si[col];
	    co[st[top]]=col;
	    top--;
	}
	--top;
    }
}
int V[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	for(int i=1,v;i<=n;i++){
		scanf("%d",&v);
		if(v!=i);
		adde(i,v);
    }
    for(int i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i);
    for(int i=1;i<=col;i++)V[i]=INF;
	for(int i=1;i<=n;i++){
		V[co[i]]=min(V[co[i]],val[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=hed[i];j;j=nxt[j])
			if(co[i]!=co[to[j]])
			de[co[i]]++;
    }
    long long ans=0;
	for(int i=1;i<=col;i++)if(!de[i]){
		ans+=V[i];
	}
	printf("%lld\n",ans);
}