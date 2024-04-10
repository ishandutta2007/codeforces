#include <bits/stdc++.h>
using namespace std;

const int MN=100000,BS=17;
int segs[1<<(BS+1)]={0},segm[1<<(BS+1)]={0};

void segadd(int i,int j,int k,int a,int b,int s)
{
  if(a<=j&&k<=b){
    segs[i]+=s;
    segm[i]+=s;
  }
  else if(a<k&&j<b){
    segadd(2*i,j,(j+k)/2,a,b,s);
    segadd(2*i+1,(j+k)/2,k,a,b,s);
    segm[i]=min(segm[2*i],segm[2*i+1])+segs[i];
  }
}

int segbs(int i,int j,int k,int v)
{
  if(j+1==k){
    return j;
  }
  v-=segs[i];
  if(segm[2*i+1]>v){
    return segbs(2*i,j,(j+k)/2,v);
  }
  return segbs(2*i+1,(j+k)/2,k,v);
}

int segv(int i)
{
  int ret=0,p=i+(1<<BS);
  while(p>0){
    ret+=segs[p];
    p/=2;
  }
  return ret;
}


const int INF=10000000;

int main()
{
  int n;
  scanf("%d",&n);
  segadd(1,0,1<<BS,n+1,1<<BS,INF);
  static int X[MN+10];
  for(int i=0;i<n;i++){
    int p,t;
    scanf("%d%d",&p,&t);
    p--;
    if(t==0){
      segadd(1,0,1<<BS,p+1,n+1,-1);
    }
    else{
      scanf("%d",X+p);
      segadd(1,0,1<<BS,p+1,n+1,1);
    }
    int v=segv(n);
    if(segm[1]>=v){
      puts("-1");
    }
    else{
      int j=segbs(1,0,1<<BS,v-1);
      printf("%d\n",X[j]);
    }
  }
  return 0;
}