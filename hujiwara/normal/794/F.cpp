#include <bits/stdc++.h>
using namespace std;

typedef long long T;

class LEsegtree
{
private:
  vector<T> sumin(int i,int j,int k,int a,int b)
  {
    vector<T> ret(10,0ll);
    if(a<=j&&k<=b){
      ret=seg[i];
    }
    else if(a<k&&j<b){
      vector<T> ret1=sumin(2*i,j,(j+k)/2,a,b);
      vector<T> ret2=sumin(2*i+1,(j+k)/2,k,a,b);
      for(int x=0;x<10;x++){
	ret[tab[i][x]]+=ret1[x]+ret2[x];
      }
    }
    return ret;
  }
  void tab_change(int i,int X,int Y){
    if(X==Y)return;
    for(int x=0;x<10;x++){
      if(tab[i][x]==X){
	tab[i][x]=Y;
      }
    }
    seg[i][Y]+=seg[i][X];
    seg[i][X]=0;
  }
  void ragin(int i,int j,int k,int a,int b,int X,int Y)
  {
    if(a<=j&&k<=b){
      tab_change(i,X,Y);
    }
    else if(a<k&&j<b){
      vector<long long> tp1(10,0ll),tp2(10,0ll);
      for(int x=0;x<10;x++){
	tab[2*i][x]=tab[i][tab[2*i][x]];
	tab[2*i+1][x]=tab[i][tab[2*i+1][x]];
	tp1[tab[i][x]]+=seg[2*i][x];
	tp2[tab[i][x]]+=seg[2*i+1][x];
      }
      seg[2*i]=tp1,seg[2*i+1]=tp2;
      for(int x=0;x<10;x++){
	tab[i][x]=x;
      }
      ragin(2*i,j,(j+k)/2,a,b,X,Y);
      ragin(2*i+1,(j+k)/2,k,a,b,X,Y);
      for(int x=0;x<10;x++){
	seg[i][x]=seg[2*i][x]+seg[2*i+1][x];
      }
    }
  }
public:
  vector<vector<T> > seg;
  vector<vector<int> > tab;
  int S;
  LEsegtree(int BS){
    S=BS;
    seg=vector<vector<T> >(1<<(S+1));
    tab=vector<vector<int> >(1<<(S+1));
    for(int t=1;t<1<<(S+1);t++){
      seg[t]=vector<T>(10,0ll);
      tab[t]=vector<int>(10);
      for(int x=0;x<10;x++){
	tab[t][x]=x;
      }
    }
  }
  void add(int i,long long a){
    int p=i+(1<<S);
    while(p>0){
      long long P=1ll;
      while(P<=a){
	seg[p][a/P%10]+=P;
	P*=10;
      }
      p/=2;
    }
  }
  vector<T> sum(int a,int b){
    return sumin(1,0,1<<S,a,b);
  }
  void rag(int a,int b,int X,int Y){
    ragin(1,0,1<<S,a,b,X,Y);
  }
};

int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  static long long a[100000];
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  const int S=17;
  LEsegtree segs(S);
  for(int i=0;i<n;i++){
    segs.add(i,a[i]);
  }
  while(q--){
    int ty;
    scanf("%d",&ty);
    if(ty==1){
      int l,r,x,y;
      scanf("%d%d%d%d",&l,&r,&x,&y);
      l--;
      segs.rag(l,r,x,y);
    }
    else{
      int l,r;
      scanf("%d%d",&l,&r);
      l--;
      long long ans=0ll;
      vector<long long> ret=segs.sum(l,r);
      for(int x=0;x<10;x++){
	//printf("%d %d %d %d\n",t,x,ret[x],segs.seg[t][l+(1<<S)][x]);
	ans+=x*ret[x];
      }
      printf("%lld\n",ans);
    }
  }
  return 0;
}