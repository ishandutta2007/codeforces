#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e6+5;
typedef long long ll;
struct Lct
{
  int n,m,id[N],root,a[N],t[N][2],mn[N],fa[N],lz[N],s[N],si[N];
  bool rev[N];
  int U[N],V[N];
  void pushup(int x)
  {
      s[x]=s[t[x][0]]+s[t[x][1]]+a[x];
      si[x]=si[t[x][0]]+si[t[x][1]]+(x>n);
      mn[x]=min(id[x],min(mn[t[x][0]],mn[t[x][1]]));
  }
  void Rev(int x){swap(t[x][0],t[x][1]);rev[x]^=1;}
  void up(int x,int z)
  {
    lz[x]=z;
    z--;
    if(z) s[x]=si[x];
    else s[x]=0;
  }
  void pushdown(int x)
  {
      if(lz[x])
      {
        if(t[x][0]) up(t[x][0],lz[x]);
        if(t[x][1]) up(t[x][1],lz[x]);
        lz[x]=0;
      }
      if(rev[x])
      {
        if(t[x][0]) Rev(t[x][0]);
        if(t[x][1]) Rev(t[x][1]);
        rev[x]=false;
      }
  }
  bool nroot(int x)
  {
      return t[fa[x]][0]==x|t[fa[x]][1]==x;
  }
  void Rotate(int x)
  {
      int y=fa[x],z=fa[y],k=(t[y][1]==x)^1;
      if(nroot(y)) t[z][t[z][1]==y]=x;
      t[y][k^1]=t[x][k];
      if(t[x][k]) fa[t[x][k]]=y;
      t[x][k]=y;
      fa[y]=x;
      fa[x]=z;
      pushup(y);
  }
  int st[N];
  void splay(int x)
  {
      int y=x,z=0;
      st[++z]=y;
      while(nroot(y)) st[++z]=y=fa[y];
      while(z) pushdown(st[z--]);
      while(nroot(x))
      {
          y=fa[x],z=fa[y];
          if(nroot(y)) Rotate((t[y][1]==x)^(t[z][1]==y)?x:y);
          Rotate(x);
      }
      pushup(x);
  }
  void access(int x)
  {
      for(int y=0;x;x=fa[y=x])
      {
          splay(x);t[x][1]=y;pushup(x);
      }
  }
  void makeroot(int x)
  {
      access(x);splay(x);Rev(x);
  }
  int findroot(int x)
  {
      access(x);splay(x);
      while(t[x][0]) pushdown(x),x=t[x][0];
      splay(x);
      return x;
  }
  bool con(int x,int y)
  {
    makeroot(x);
    return findroot(y)==x;
  }
  void link(int x,int y)
  {
      makeroot(x);
      fa[x]=y;
  }
  void cut(int x,int y)
  {
      makeroot(x);
      if(findroot(y)==x&&fa[y]==x&&!t[y][0])
      {
          fa[y]=t[x][1]=0;
          pushup(x);
      }
  }
  void split(int x,int y)
  {
      makeroot(x);
      access(y);splay(y);
  }
  bool deled[N];
  bool ok(int i)
  {
    if(!con(U[i],V[i]))
    {
      link(i+n,U[i]);
      link(i+n,V[i]);
      return true;
    }
    split(U[i],V[i]);
    if(s[U[i]]) return false;
    int j=mn[U[i]];
    deled[j]=true;
    cut(j+n,U[j]);
    cut(j+n,V[j]);
    link(i+n,U[i]);
    link(i+n,V[i]);
    split(U[j],V[j]);
    up(V[j],2);
    return true;
  }
  void del(int i)
  {
    if(deled[i])
    {
      split(U[i],V[i]);
      up(V[i],1);
      return;
    }
    cut(i+n,U[i]);
    cut(i+n,V[i]);
  }
}lct;
int main()
{
    scanf("%d%d",&lct.n,&lct.m);
    lct.mn[0]=inf;
    for(int i=1;i<=lct.n;i++) lct.id[i]=inf;
    for(int i=1;i<=lct.m;i++) lct.id[i+lct.n]=i;
    for(int i=1;i<=lct.m;i++) scanf("%d%d",&lct.U[i],&lct.V[i]);
    ll ans=0;
    for(int i=1,j=0;i<=lct.m;i++)
    {
      while(j<lct.m&&lct.ok(j+1)) j++;
      ans+=j-i+1;
      lct.del(i);
    }
    printf("%lld\n",ans);
}