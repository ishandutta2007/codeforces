#include <bits/stdc++.h>
using namespace std;

const int TINF=1000000000;

template<class T> class segmintree
{
private:
  T ragin(int i,int j,int k,int a,int b)
  {
    return a<=j&&k<=b?seg[i]:k<=a||b<=j?TINF:min(ragin(2*i,j,(j+k)/2,a,b),ragin(2*i+1,(j+k)/2,k,a,b));
  }
public:
  T *seg;
  int S;
  segmintree(int BS){
    S=BS;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
  }
  segmintree(vector<T> &a)
  {
    int n=a.size();
    S=0;
    while((1<<S)<=n)S++;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
    for(int i=0;i<1<<S;i++){
      seg[i+(1<<S)]=(i<n?a[i]:TINF);
    }
    for(int i=(1<<S)-1;i>0;i--){
      seg[i]=min(seg[2*i],seg[2*i+1]);
    }
  }
  void set(int i,T k){
    int p=i+(1<<S);
    seg[p]=k;
    while(p>1){
      p/=2;
      seg[p]=min(seg[2*p],seg[2*p+1]);
    }
  }
  T rag(int a,int b){
    return ragin(1,0,1<<S,a,b);
  }
  T val(int i){
    int p=i+(1<<S);
    return seg[p];
  }
};

int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  bool F=0;
  for(int i=0;i<n;i++){
    if(a[i]==q){
      F=1;
    }
  }
  for(int i=0;i<n;i++){
    if(a[i]==0){
      if(!F){
	a[i]=q;
	F=1;
      }
      else{
	a[i]=(i==0?1:a[i-1]);
      }
    }
  }
  if(!F){
    puts("NO");
    return 0;
  }
  vector<int> mn(q+1,n+1),mx(q+1,-1);
  for(int i=0;i<n;i++){
    mx[a[i]]=max(mx[a[i]],i);
    mn[a[i]]=min(mn[a[i]],i);
  }
  segmintree<int> seg(a);
  bool C=1;
  for(int t=1;t<=q;t++){
    if(mx[t]!=-1){
      int g=seg.rag(mn[t],mx[t]+1);
      if(g<t){
	C=0;
	break;
      }
    }
  }
  if(C){
    puts("YES");
    for(int i=0;i<n;i++){
      printf("%d%c",a[i],i==n-1?'\n':' ');
    }
  }
  else{
    puts("NO");
  }
  return 0;
}