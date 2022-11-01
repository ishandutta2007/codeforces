#include<bits/stdc++.h>
using namespace std;
const int N=1500000;
int n,m,qq,ans,res,las=1,a[N],rt[N],ls[N*20],rs[N*20],sum[N*20],cnt,num[N],tot=1,son[N][26],fa[N],ff[N][21],len[N];
vector<int>endpos[N],v;
char s[N],ss[N];
int newnode() { return ++cnt;}
int copynode(int x){int now=newnode();ls[now]=ls[x];rs[now]=rs[x];sum[now]=sum[x];return now;}
int work(int p,int c)
{
    int nq=++tot,q=son[p][c];
    len[nq]=len[p]+1;
    fa[nq]=fa[q];fa[q]=nq;
    memcpy(son[nq],son[q],sizeof(son[q]));
    while(p&&son[p][c]==q) son[p][c]=nq,p=fa[p];
    return nq;
}
int ins(int p,int c)
{
    if(son[p][c])
    {
        int q=son[p][c];
        if(len[q]==len[p]+1) return q;
        return work(p,c);
    }
    int np=++tot;len[np]=len[p]+1;
    while(p&&!son[p][c]) son[p][c]=np,p=fa[p];
    if(!p) fa[np]=1;
    else
    {
        int q=son[p][c];
        if(len[q]==len[p]+1) fa[np]=q;
        else fa[np]=work(p,c);
    }
    return np;
}
void Insert(int l,int r,int x,int &now)
{
    if(!now) now=newnode();
    else now=copynode(now);
    if(l==r){sum[now]++;return;}
    int m=l+r>>1;
    if(x<=m) Insert(l,m,x,ls[now]);
    else Insert(m+1,r,x,rs[now]);
    sum[now]=max(sum[ls[now]],sum[rs[now]]);
}
int Merge(int l,int r,int x,int y)
{
    if(!x||!y) return x+y;
    int now=newnode();
    if(l==r) sum[now]=sum[x]+sum[y];
    else
    {
        int m=l+r>>1;
        ls[now]=Merge(l,m,ls[x],ls[y]);
        rs[now]=Merge(m+1,r,rs[x],rs[y]);
        sum[now]=max(sum[ls[now]],sum[rs[now]]);
    }
    return now;
}
void query(int l,int r,int x,int y,int now)
{
    if(r<x||l>y||!now||sum[now]<res||sum[now]==res&&l>ans) return;
    if(l==r){ans=l;res=sum[now];return;}
    int m=l+r>>1;
    query(l,m,x,y,ls[now]);query(m+1,r,x,y,rs[now]);
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        las=ins(las,s[i]-'a'),a[i]=las;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s",ss+1);
        las=1;
        for(int j=1;ss[j];j++)
            las=ins(las,ss[j]-'a'),endpos[las].push_back(i);
    }
    queue<int>q;
    for(int i=2;i<=tot;i++) num[fa[i]]++;
    for(int i=1;i<=tot;i++)
        if(!num[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        v.push_back(u);
        for(int i=0;i<endpos[u].size();i++)
            Insert(1,m,endpos[u][i],rt[u]);
        rt[fa[u]]=Merge(1,m,rt[fa[u]],rt[u]);
        num[fa[u]]--;
        if(!num[fa[u]]) q.push(fa[u]);
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        int u=v[i];
        ff[u][0]=fa[u];
        for(int j=1;j<=20;j++)
            ff[u][j]=ff[ff[u][j-1]][j-1];
    }
    scanf("%d",&qq);
    while(qq--)
    {
        int l,r,pl,pr;scanf("%d%d%d%d",&l,&r,&pl,&pr);
        int u=a[pr],k=pr-pl+1;
        for(int i=20;i>=0;i--)
            while(len[ff[u][i]]>=k) u=ff[u][i];
        ans=res=0;
        query(1,m,l,r,rt[u]);
        if(res==0) ans=l;
        printf("%d %d\n",ans,res);
    }
}