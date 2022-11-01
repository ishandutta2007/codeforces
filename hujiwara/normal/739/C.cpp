#include <bits/stdc++.h>
using namespace std;

const int sz=19;
int seg1[1<<20],seg2[1<<20],seg3[1<<20],seg4[1<<20],seg5[1<<20];

typedef long long ll;

void scal(int i,ll v)
{
  if(v<0){
    seg1[i]=0;
    seg2[i]=seg3[i]=seg4[i]=seg5[i]=1;
  }
  else if(v>0){
    seg2[i]=0;
    seg1[i]=seg3[i]=seg4[i]=seg5[i]=1;
  }
  else{
    seg1[i]=seg2[i]=seg3[i]=seg4[i]=seg5[i]=0;
  }
}

int W[1<<20];

void cal(int i)
{
  int l=2*i,r=2*i+1,w=W[i]/2;
  seg1[i]=(seg1[r]==w?seg1[l]+w:seg1[r]);
  seg2[i]=(seg2[l]==w?seg2[r]+w:seg2[l]);
  seg3[i]=(seg2[r]==w?seg3[l]+w:seg3[r]==w?seg1[l]+w:seg3[r]);
  seg4[i]=(seg1[l]==w?seg4[r]+w:seg4[l]==w?seg2[r]+w:seg4[l]);
  seg5[i]=max(max(seg5[l],seg5[r]),max(seg1[l]+seg4[r],seg3[l]+seg2[r]));
  /*if(i==(1<<18)||i==(1<<18)+1||i==(1<<17)){
    printf("%d %d %d %d %d %d\n",w,seg1[i],seg2[i],seg3[i],seg4[i],seg5[i]);
    }*/
}


int main()
{
  int  n;
  scanf("%d",&n);
  static ll a[300000];
  for(int i=0;i<n;i++){
    scanf("%I64d",a+i);
  }
  static ll D[1<<19];
  for(int i=0;i<1<<sz;i++){
    int p=i+(1<<sz);
    W[p]=1;
    D[i]=(i<n-1?a[i+1]-a[i]:0);
    scal(p,D[i]);
  }
  for(int i=(1<<sz)-1;i>0;i--){
    W[i]=W[2*i]*2;
    cal(i);
  }
  int m;
  scanf("%d",&m);
  while(m--){
    int l,r;
    ll d;
    scanf("%d%d%I64d",&l,&r,&d);
    l--;
    r--;
    if(l>0){
      D[l-1]+=d;
      int p=(l-1)+(1<<sz);
      scal(p,D[l-1]);
      while(p>1){
	p/=2;
	cal(p);
      }
    }
    if(r<n-1){
      D[r]-=d;
      int p=r+(1<<sz);
      scal(p,D[r]);
      while(p>1){
	p/=2;
	cal(p);
      }
    }
    printf("%d\n",seg5[1]+1);
  }
  return 0;
}