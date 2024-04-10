#include<iostream>
#include<algorithm>
#include<cstdio>
#define X first
#define Y second

using namespace std;

typedef pair<int,int>pii;
const int MAXN=300000;
pii P[MAXN];
int n,q,f[MAXN];

int R(int x,int tol,bool mark);

int L(int x,int tol,bool mark)
{
  int k=lower_bound(P,P+n,pii(P[x].X-tol,0))-P;
  if(k==x)
    {
      if(!mark)
	return k;
      return R(k,tol,1);
    }
  tol-=P[x].X-P[k].X;
  tol%=(P[x].X-P[k].X)*2;
  return R(k,tol,1);
}

int R(int x,int tol,bool mark)
{
  int k=lower_bound(P,P+n,pii(tol+P[x].X+1,0))-P;
  k--;
  if(k==x)
    return L(x,tol,0);
  tol-=P[k].X-P[x].X;
  if(mark)
      tol%=(P[k].X-P[x].X)*2;
  return L(k,tol,1);
}


int main()
{
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++)
    {
      scanf("%d",&P[i].X);
      P[i].Y=i;
    }
  sort(P,P+n);
  for(int i=0;i<n;i++)
    f[P[i].Y]=i;
  for(int i=0;i<q;i++)
    {
      int x,y;
      scanf("%d %d",&x,&y);
      x=f[x-1];
      printf("%d\n",P[R(x,y,0)].Y+1);
    }
}