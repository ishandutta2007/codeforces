#include <bits/stdc++.h>
using namespace std;

const int MN=200000,BS=18;
int mem[1<<16];
vector<int> seg[1<<(BS+1)];

vector<int> mg(vector<int> a,vector<int> b)
{
  vector<int> c=a;
  for(int t=0;t<b.size();t++){
    int s=b[t],i,n=c.size();
    for(i=0;i<n;i++){
      int p=((c[i]>>16)==0?mem[c[i]]:mem[c[i]>>16]+16);
      if((s>>(p+1))!=0){
	break;
      }
      if((s>>p)&1){
	s^=c[i];
      }
    }
    if(s>0){
      if(i<n){
	c.push_back(c[n-1]);
	for(int k=n-1;k>i;k--){
	  c[k]=c[k-1];
	}
	c[i]=s;
      }
      else{
	c.push_back(s);
      }
    }
  }
  return c;
}

vector<int> segr(int i,int j,int k,int a,int b)
{
  vector<int> ret;
  if(a<=j&&k<=b){
    ret=seg[i];
  }
  else if(a<k&&j<b){
    ret=mg(segr(2*i,j,(j+k)/2,a,b),segr(2*i+1,(j+k)/2,k,a,b));
  }
  else{
    ret=vector<int>(0);
  }
  return ret;
}

void segv(int i,int v)
{
  int p=i+(1<<BS);
  seg[p]=(v==0?vector<int>(0):vector<int>(1,v));
  p/=2;
  while(p>0){
    seg[p]=mg(seg[2*p],seg[2*p+1]);
    p/=2;
  }
}

template<class T> class LEsegtree
{
private:
  void ragin(int i,int j,int k,int a,int b,T v)
  {
    if(a<=j&&k<=b){
      seg[i]=(*op)(seg[i],v);
    }
    else if(a<k&&j<b){
      ragin(2*i,j,(j+k)/2,a,b,v);
      ragin(2*i+1,(j+k)/2,k,a,b,v);
    }
  }
public:
  T *seg;
  int S;
  T (*op)(T,T);
  T TINF;
  LEsegtree(int BS,T (*top)(T,T),T INF){
    S=BS;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
    op=top;
    TINF=INF;
    for(int t=1;t<1<<(S+1);t++){
      seg[t]=TINF;
    }
  }
  T val(int i){
    int p=i+(1<<S);
    T ret=TINF;
    while(p>0){
      ret=(*op)(ret,seg[p]);
      p/=2;
    }
    return ret;
  }
  void rag(int a,int b,T v){
    return ragin(1,0,1<<S,a,b,v);
  }
};

int Xor(int a,int b){return a^b;}

int main()
{
  for(int i=0;i<16;i++){
    for(int x=1<<i;x<1<<(i+1);x++){
      mem[x]=i;
    }
  }
  int n,q;
  scanf("%d%d",&n,&q);
  static int a[MN];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  static int b[MN];
  for(int i=0;i<n-1;i++){
    b[i]=a[i]^a[i+1];
  }
  for(int i=0;i<(1<<BS);i++){
    seg[i+(1<<BS)]=(i+1<n&&b[i]!=0?vector<int>(1,b[i]):vector<int>(0));
  }
  for(int i=(1<<BS)-1;i>0;i--){
    seg[i]=mg(seg[2*i],seg[2*i+1]);
  }
  LEsegtree<int> sega(BS,Xor,0);
  for(int i=0;i<n;i++){
    sega.seg[i+(1<<BS)]=a[i];
  }
  for(int T=0;T<q;T++){
    int t;
    scanf("%d",&t);
    if(t==1){
      int l,r,k;
      scanf("%d%d%d",&l,&r,&k);
      l--;
      sega.rag(l,r,k);
      if(l>0){
	b[l-1]^=k;
	segv(l-1,b[l-1]);
      }
      if(r<n){
	b[r-1]^=k;
	segv(r-1,b[r-1]);
      }
    }
    else{
      int l,r;
      scanf("%d%d",&l,&r);
      l--;
      int al=sega.val(l);
      vector<int> ret=segr(1,0,1<<BS,l,r-1);
      /*for(int t=0;t<ret.size();t++){
	printf("%d%c",ret[t],t+1<ret.size()?' ':'\n');
	}*/
      if(al!=0){
	ret=mg(ret,vector<int>(1,al));
      }
      printf("%d\n",1<<ret.size());
    }
  }
  return 0;
}