#include <bits/stdc++.h>
using namespace std;

const int BS=20;

const long long mod=1000000007ll;

pair<int,long long> bitmax(int *bit,long long *g,int i)
{
  int p=i,ret=0;
  long long G=0ll;
  while(p>0){
    if(ret<bit[p]){
      ret=bit[p];
      G=g[p];
    }
    else if(ret==bit[p]){
      G+=g[p];
      G%=mod;
    }
    p-=p&-p;
  }
  return make_pair(ret,G);
}

void bitval(int *bit,long long *g,int i,int v,long long G)
{
  int p=i+1;
  while(p<1<<BS){
    if(bit[p]<v){
      bit[p]=v;
      g[p]=G;
    }
    else if(bit[p]==v){
      g[p]+=G;
      g[p]%=mod;
    }
    p+=p&-p;
  }
}



int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int h[400000],H[800000];
  for(int i=0;i<n;i++){
    scanf("%d",h+i);
    H[i]=h[i];
  }
  static int a[400000],b[400000];
  static vector<int> e[400000];
  for(int j=0;j<m;j++){
    scanf("%d%d",a+j,b+j);
    a[j]--;
    e[a[j]].push_back(j);
    H[n+j]=b[j];
  }
  sort(H,H+n+m);
  for(int i=0;i<n;i++){
    h[i]=lower_bound(H,H+n+m,h[i])-H;
  }
  for(int j=0;j<m;j++){
    b[j]=lower_bound(H,H+n+m,b[j])-H;
  }
  static int L1[400000],L2[400000];
  static int S1[400000],S2[400000];
  static long long G1[400000],G2[400000];
  static int bit1[1<<20]={0},bit2[1<<20]={0};
  static long long g1[1<<20]={0},g2[1<<20]={0};
  int ans=0;
  for(int i=0;i<n;i++){
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      pair<int,long long> p=bitmax(bit1,g1,b[j]);
      L1[j]=p.first;
    }
    pair<int,long long> p=bitmax(bit1,g1,h[i]);
    S1[i]=p.first;
    G1[i]=(S1[i]==0?1:p.second);
    bitval(bit1,g1,h[i],S1[i]+1,G1[i]);
    ans=max(ans,S1[i]+1);
  }
  for(int i=n-1;i>=0;i--){
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      pair<int,long long> p=bitmax(bit2,g2,n+m-1-b[j]);
      L2[j]=p.first;
    }
    pair<int,long long> p=bitmax(bit2,g2,n+m-1-h[i]);
    S2[i]=p.first;
    G2[i]=(S2[i]==0?1:p.second);
    bitval(bit2,g2,n+m-1-h[i],S2[i]+1,G2[i]);
  }
  long long g=0;
  for(int i=0;i<n;i++){
    if(S1[i]+S2[i]+1==ans){
      g+=G1[i]*G2[i]%mod;
      g%=mod;
    }
  }
  for(int j=0;j<m;j++){
    int i=a[j];
    printf("%d\n",max(L1[j]+L2[j]+1,ans-(S1[i]+S2[i]+1==ans&&G1[i]*G2[i]%mod*ans%mod==g?1:0)));
  }
  return 0;
}