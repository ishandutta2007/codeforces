#include <bits/stdc++.h>
using namespace std;

int mrand(){
  return ((rand()%(1<<15))<<15)+(rand()%(1<<15));
}

int main()
{
  int n,start,x;
  scanf("%d%d%d",&n,&start,&x);
  //pxrintf("%d\n",RAND_MAX);
  int X=1000;
  X=min(X,n);
  vector<int> ask(X);
  ask[0]=start;
  vector<int> R(n);
  for(int i=0;i<n;i++){
    R[i]=i+1;
  }
  swap(R[start-1],R[n-1]);
  for(int t=1;t<X;t++){
    int k=mrand()%(n-t);
    ask[t]=R[k];
    swap(R[k],R[n-t-1]);
  }
  vector<pair<int,int> > P(X);
  vector<int> V(n+1,0),A(n+1),B(n+1);
  for(int t=0;t<X;t++){
    int i=ask[t];
    printf("? %d\n",i);
    fflush(stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    V[i]=1,A[i]=a,B[i]=b;
    P[t]=make_pair(a,i);
  }
  sort(P.begin(),P.end());
  int s=0;
  while(s+1<P.size()&&P[s+1].first<x){
    s++;
  }
  int i=P[s].second;
  int ans;
  int T=X;
  //assert(i==start||P[s].first<x);
  while(1){
    int a,b;
    if(!V[i]){
      assert(T<1999);
      //assert(1<=i&&i<=n);
      T++;
      V[i]=1;
      printf("? %d\n",i);
      fflush(stdout);
      scanf("%d%d",&a,&b);
      //assert(a!=-1||b!=-1);
      A[i]=a,B[i]=b;
    }
    else{
      a=A[i],b=B[i];
    }
    if(a>=x){
      ans=a;
      break;
    }
    if(b==-1){
      ans=-1;
      break;
    }
    i=b;
  }
  printf("! %d\n",ans);
  fflush(stdout);
  return 0;
}