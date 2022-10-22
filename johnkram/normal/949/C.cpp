#include<bits/stdc++.h>
using namespace std;
const int Len=1<<24,MAXN=100005,MAXM=1000005;
char _buf[Len],*S=_buf,c;
inline void get(int &x)
{
    for(c=*S++;c<'0'||c>'9';c=*S++);
    x=c^'0';
    for(c=*S++;c>='0'&&c<='9';c=*S++)x=x*10+(c^'0');
}
int ans,n,m,M,P,i,j,k,a[MAXN],h[MAXN],d[MAXN],ne[MAXM],p[MAXM],in[MAXN],t,top,dfn[MAXN],low[MAXN],nx,s[MAXN],f[MAXN],E[MAXN],siz[MAXN],hn[MAXN],nen[MAXM],pn[MAXM],mn,w[MAXN],q[MAXN],he,ta;
bool b[MAXN];
void Tarjan(int i)  
{
    int j,k;
    dfn[i]=low[i]=++t;
    b[i]=1;
    s[++top]=i;
    for(k=h[i];k;k=ne[k])if(!dfn[j=p[k]])
    {
        Tarjan(j);
        low[i]=min(low[i],low[j]);
    }
    else if(b[j])low[i]=min(low[i],dfn[j]);
    if(dfn[i]==low[i])
    {
        nx++;
        do
        {
            j=s[top--];
            b[j]=0;
            siz[f[j]=nx]++;
        }
        while(j!=i);
    }
}
int dfs(int now)
{
    if(d[now]!=-1)return d[now];
    int s=0,i;
    for(i=hn[now];i;i=nen[i])s=max(s,dfs(pn[i]));
    return d[now]=s+w[now];
}
int main()
{
    fread(_buf,1,Len,stdin);
    get(n);
    get(m);
	get(P);
	for(i=1;i<=n;i++)get(a[i]);
    for(i=1;i<=m;i++)
    {
        get(j);
        get(k);
		if((a[j]+1)%P==a[k]){
        p[++M]=k;
        ne[M]=h[j];
			h[j]=M;}
		if((a[k]+1)%P==a[j]){
        p[++M]=j;
        ne[M]=h[k];
			h[k]=M;}
    }
    for(i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
    for(i=1;i<=n;i++)for(j=h[i];j;j=ne[j])if(f[i]!=f[p[j]])E[f[i]]++;
	siz[0]=n+1;
	for(ans=0,i=1;i<=nx;i++)if(!E[i]&&siz[i]<siz[ans])ans=i;
	printf("%d\n",siz[ans]);
	for(i=1;i<=n;i++)if(f[i]==ans)printf("%d ",i);
    return 0;
}