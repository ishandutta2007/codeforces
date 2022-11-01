#include <bits/stdc++.h>

using namespace std;

const int MAXN=100000,BS=18,INF=1500000000;


const pair<int,int> TINF=make_pair(INF,-1);

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
  segmintree(int BS,int n,T *a)
  {
    S=BS;
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
  int n;
  scanf("%d",&n);
  static int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
  for(int i=0;i<n;i++){
    scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
  }
  static int X[2*MAXN];
  for(int i=0;i<n;i++){
    X[i]=a[i];
    X[i+n]=c[i];
  }
  sort(X,X+2*n);
  for(int i=0;i<n;i++){
    a[i]=lower_bound(X,X+2*n,a[i])-X;
    c[i]=lower_bound(X,X+2*n,c[i])-X;
  }
  static vector<pair<int,int> > v[2*MAXN];
  int P[MAXN];
  queue<int> Q;
  for(int i=0;i<n;i++){
    if(X[a[i]]<=0&&b[i]<=0){
      P[i]=-1;
      Q.push(i);
    }
    else{
      P[i]=-2;
      v[a[i]].push_back(make_pair(b[i],i));
    }
  }
  for(int i=0;i<2*n;i++){
    v[i].push_back(make_pair(INF,-1));
    sort(v[i].begin(),v[i].end());
  }
  static pair<int,int> F[2*MAXN];
  for(int i=0;i<2*n;i++){
    F[i]=v[i][0];
  }
  static segmintree<pair<int,int> > seg(BS,2*n,F);
  static int D[2*MAXN]={0};
  while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    while(1){
      pair<int,int> p=seg.rag(0,c[i]+1);
      if(p.first>d[i]){
	break;
      }
      int j=p.second;
      D[a[j]]++;
      seg.set(a[j],v[a[j]][D[a[j]]]);
      Q.push(j);
      P[j]=i;
    }
  }
  if(P[n-1]==-2){
    puts("-1");
  }
  else{
    vector<int> ans;
    int i=n-1;
    while(P[i]!=-1){
      ans.push_back(i);
      i=P[i];
    }
    ans.push_back(i);
    printf("%d\n",ans.size());
    for(int t=ans.size()-1;t>=0;t--){
      printf("%d%c",ans[t]+1,t==0?'\n':' ');
    }
  }
  return 0;
}