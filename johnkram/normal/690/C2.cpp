#include<cstdio>
#include<cstring>
int h[100005],ne[200005],p[200005],d[100005],n,m,i,j,k;
bool b[100005];
void dfs(int x)
{
    b[x]=1;
    for(int i=h[x];i;i=ne[i])if(!b[p[i]])
    {
        d[p[i]]=d[x]+1;
        dfs(p[i]);
    }
}
int main()
{
    scanf("%d%*d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        p[++m]=k;
        ne[m]=h[j];
        h[j]=m;
        p[++m]=j;
        ne[m]=h[k];
        h[k]=m;
    }
    dfs(1);
    for(i=j=1;i<=n;i++)if(d[i]>d[j])j=i;
    memset(b,0,sizeof(b));
    d[j]=0;
    dfs(j);
    for(i=j=1;i<=n;i++)if(d[i]>d[j])j=i;
    printf("%d\n",d[j]);
    return 0;
}