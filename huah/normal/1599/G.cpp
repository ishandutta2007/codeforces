#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
mt19937 gen(time(0));
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=2e5+5,mod=1e9+7;
typedef long long ll;
int n,k;
struct node
{
  int x,y,id;
  bool operator<(const node&o)const
  {
    if(x==o.x) return y<o.y;
    return x<o.x;
  }
}a[N];
pair<int,int>slope(int y,int x)
{
  int g=__gcd(x,y);
  y/=g;x/=g;
  if(x<0) y*=-1,x*=-1;
  return {y,x};
}
bool judge(int x)
{
  map<pair<int,int>,bool>vis;
  for(int i=1;i<=min(n,4);i++)
    if(x!=i)
    {
      pair<int,int>s=slope(a[i].y-a[x].y,a[i].x-a[x].x);
      if(vis.count(s)) return false;
      vis[s]=true;
    }
  return true;
}
double dis(node&x,node&y)
{
  return sqrt(1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y));
}
void up(double &x,double y)
{
  if(y<x) x=y;
}
void sol(int x)
{
  double ans=1e9;
  swap(a[x],a[n]);
  sort(a+1,a+n);
  if(a[n].id==k)
    ans=dis(a[1],a[n-1])+min(dis(a[1],a[n]),dis(a[n-1],a[n]));
  else
  {
    for(int i=1;i<=n-1;i++)
      if(a[i].id==k)
      {
        k=i;break;
      }
    rep(i,1,n-1)
    {
      if(i<=k)
      {
        up(ans,dis(a[k],a[n-1])+dis(a[n-1],a[i])+dis(a[i],a[n])+(i>1?dis(a[n],a[i-1])+dis(a[i-1],a[1]):0));
        up(ans,dis(a[k],a[i])+dis(a[n-1],a[i])+dis(a[n-1],a[n])+(i>1?dis(a[n],a[i-1])+dis(a[i-1],a[1]):0));
      }
      if(i>=k)
      {
        up(ans,dis(a[k],a[1])+dis(a[1],a[i])+dis(a[i],a[n])+(i<n-1?dis(a[n],a[i+1])+dis(a[i+1],a[n-1]):0));
        up(ans,dis(a[k],a[i])+dis(a[1],a[i])+dis(a[1],a[n])+(i<n-1?dis(a[n],a[i+1])+dis(a[i+1],a[n-1]):0));
      }
    }
  }
  printf("%.10f\n",ans);
}
int main()
{
	// freopen("1.in", "r", stdin);
  // freopen("1.in","r",stdin);
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++)
    if(judge(i))
    {
      sol(i);
      break;
    }
}