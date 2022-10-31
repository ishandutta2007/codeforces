#include <bits/stdc++.h>
using namespace std;

long long M[6][10001];

long long F(int q,long long x)
{
  x=min(x,10000ll);
  if(q==0){
    return 0;
  }
  if(q==1){
    return x;
  }
  if(M[q][x]!=-1){
    return M[q][x];
  }
  long long t=F(q-1,x);
  for(int p=0;p<x;p++){
    t++;
    t+=F(q-1,x+t);
  }
  M[q][x]=t;
  //printf("%d %lld %lld\n",q,x,t);
  return t;
}

int main()
{
  for(int q=0;q<=5;q++){
    for(int x=1;x<=10000;x++){
      M[q][x]=-1;
    }
  }
  //printf("%lld\n",F(5,1));
  long long x=1;
  for(int q=4;q>=0;q--){
    int k=(int)min(x,10000ll);
    printf("%d\n",k);
    static long long t[10000];
    t[0]=x+F(q,x);
    for(int p=1;p<k;p++){
      t[p]=t[p-1]+1+F(q,t[p-1]+1);
    }
    for(int p=0;p<k;p++){
      printf("%lld%c",t[p],p==k-1?'\n':' ');
    }
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    if(ret<0){
      break;
    }
    x=(ret==0?x:t[ret-1]+1);
  }
  return 0;
}