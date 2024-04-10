#include <cstdio>
#include <vector>
using namespace std;
#define SZ 500010


int n,N[SZ],E[SZ],P[SZ];
void NUMB(int i,int p,int &K,vector<vector<int> > &e)
{
  N[i]=K;
  P[K]=i;
  K++;
  for(int j=0;j<e[i].size();j++){
    int k=e[i][j];
    if(k!=p){
      NUMB(k,i,K,e);
    }
  }
  E[i]=K;
}

int seg1[1<<20]={0},seg2[1<<20]={0};

void fill(int i,int j,int k,int T,int a,int b)
{
  if(!(b<=j||k<=a)){
    if(a<=j&&k<=b){
      seg1[i]=T;
      //printf("%d %d %d\n",i,j,k);
    }
    else{
      fill(2*i+1,j,(j+k)/2,T,a,b);
      fill(2*i+2,(j+k)/2,k,T,a,b);
    }
  }
}

void emp(int i,int T)
{
  int p=i+(1<<19)-1;
  seg2[p]=T;
  while(p){
    p=(p-1)/2;
    seg2[p]=T;
    //printf("%d\n",p);
  }
}

int TM1(int i)
{
  int p=i+(1<<19)-1,t=seg1[p];
  while(p){
    p=(p-1)/2;
    t=max(t,seg1[p]);
  }
  return t;
}

int TM2(int i,int j,int k,int a,int b)
{
  if(b<=j||k<=a){
    return 0;
  }
  if(a<=j&&k<=b){
    return seg2[i];
  }
  return max(TM2(2*i+1,j,(j+k)/2,a,b),TM2(2*i+2,(j+k)/2,k,a,b));
}

int main()
{
  scanf("%d",&n);
  vector<vector<int> > e(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  int K=0;
  NUMB(0,-1,K,e);
  /*for(int i=0;i<n;i++){
    printf("%d %d %d\n",i+1,N[i],E[i]);
    }*/
  int Q;
  scanf("%d",&Q);
  for(int T=1;T<=Q;T++){
    int v,a;
    scanf("%d%d",&v,&a);
    a--;
    if(v==1){
      fill(0,0,1<<19,T,N[a],E[a]);
    }
    else if(v==2){
      emp(N[a],T);
    }
    else if(v==3){
      int T1=TM1(N[a]),T2=TM2(0,0,1<<19,N[a],E[a]);
      printf("%d\n",T1>T2);
    }
  }
  return 0;
}