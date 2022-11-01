#include <bits/stdc++.h>
using namespace std;

const int TINF=100000000;
const int MAXN=100000,BS=17;

template<class T> class bitmax{
 public:
  int S;
  T *bit;
  bitmax(int BS){
    S=BS;
    bit=(T *)calloc(sizeof(T),1<<S);
    for(int i=0;i<1<<S;i++){
      bit[i]=-TINF;
    }
  }
  bitmax(int BS,T v){
    S=BS;
    bit=(T *)calloc(sizeof(T),1<<S);
    for(int i=0;i<1<<S;i++){
      bit[i]=v;
    }
  }
      
  T rag(int i)
  {
    int p=i;
    T ret=-TINF;
    while(p>0){
      ret=max(ret,bit[p]);
      p-=p&-p;
    }
    return ret;
  }
  void set(int i,T v)
  {
    int p=i+1;
    while(p<1<<S){
      bit[p]=max(bit[p],v);
      p+=p&-p;
    }
  }
};

template<class T> class bitmin{
 public:
  int S;
  T *bit;
  bitmin(int BS){
    S=BS;
    bit=(T *)calloc(sizeof(T),1<<S);
    for(int i=0;i<1<<S;i++){
      bit[i]=TINF;
    }
  }
  bitmin(int BS,T v){
    S=BS;
    bit=(T *)calloc(sizeof(T),1<<S);
    for(int i=0;i<1<<S;i++){
      bit[i]=v;
    }
  }
      
  T rag(int i)
  {
    int p=i;
    T ret=TINF;
    while(p>0){
      ret=min(ret,bit[p]);
      p-=p&-p;
    }
    return ret;
  }
  void set(int i,T v)
  {
    int p=i+1;
    while(p<1<<S){
      bit[p]=min(bit[p],v);
      p+=p&-p;
    }
  }
};


int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  static long long aa[MAXN],a[MAXN],A[MAXN];
  for(int i=0;i<n;i++){
    scanf("%d",aa+i);
  }
  for(int i=0;i<n-1;i++){
    a[i]=abs(aa[i+1]-aa[i]);
    A[i]=a[i];
  }
  n--;
  sort(A,A+n);
  static bitmax<int> bit1(BS);
  static bitmin<int> bit2(BS);
  static int L[MAXN],R[MAXN];
  for(int i=0;i<n;i++){
    int k=lower_bound(A,A+n,a[i])-A;
    L[i]=max(bit1.rag(n-k-1),-1);
    bit1.set(n-k-1,i);
  }
  for(int i=n-1;i>=0;i--){
    int k=lower_bound(A,A+n,a[i])-A;
    R[i]=min(bit2.rag(n-k),n);
    bit2.set(n-k-1,i);
  }
  for(int t=0;t<q;t++){
    int l,r;
    scanf("%d%d",&l,&r);
    l--,r--;
    long long ans=0ll;
    for(int i=l;i<r;i++){
      ans+=a[i]*(min(R[i]-1,r-1)-i+1)*(i-max(L[i]+1,l)+1);
    }
    printf("%lld\n",ans);
  }
  return 0;
}