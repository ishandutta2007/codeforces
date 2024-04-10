#include <bits/stdc++.h>
using namespace std;

const int MN=100000,BS=18;


vector<int> e[MN];

int N;
int A[MN],B[2*MN],X[2*MN];
int P[MN];

void euler_tour(int i,int p)
{
  A[i]=N;
  X[N]=A[i];
  N++;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    P[j]=i;
    euler_tour(j,i);
    X[N]=A[i];
    N++;
  }
  B[A[i]]=N;
}

const int INF=10000000;

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
  T TINF;
  segmintree(int BS,T inf){
    S=BS;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
    TINF=inf;
  }
  segmintree(int BS,T inf,int n,T *a)
  {
    S=BS;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
    TINF=inf;
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

pair<int,bool> cal(int &i,vector<pair<int,bool> > &Pr)
{
  int a=Pr[i].first;
  bool b=Pr[i].second;
  int ret=0,c=0;
  bool F=!b;
  i++;
  while(i<Pr.size()&&Pr[i].first<B[a]){
    pair<int,bool> p=cal(i,Pr);
    ret+=p.first;
    if(!b){
      ret+=p.second;
    }
    else{
      c+=p.second;
    }
  }
  if(b){
    if(c>=2){
      ret++;
    }
    else if(c>=1){
      F=1;
    }
  }
  return make_pair(ret,F);
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  N=0;
  euler_tour(0,-1);
  segmintree<int> seg(BS,INF,N,X);
  int q;
  scanf("%d",&q);
  while(q--){
    int k;
    scanf("%d",&k);
    vector<int> x(k);
    set<int> st;
    for(int i=0;i<k;i++){
      scanf("%d",&(x[i]));
      x[i]--;
      st.insert(x[i]);
    }
    bool F=0;
    for(int i=0;i<k;i++){
      if(x[i]!=0&&st.find(P[x[i]])!=st.end()){
	F=1;
	break;
      }
    }
    if(F){
      puts("-1");
      continue;
    }
    vector<int> a(k);
    for(int i=0;i<k;i++){
      a[i]=A[x[i]];
    }
    sort(a.begin(),a.end());
    vector<pair<int,bool> > pr(2*k-1);
    for(int i=0;i<k;i++){
      pr[i]=make_pair(a[i],0);
    }
    int G=k;
    for(int i=0;i<k-1;i++){
      pr[i+k]=make_pair(seg.rag(a[i],a[i+1]),1);
    }
    sort(pr.begin(),pr.end());
    vector<pair<int,bool> > Pr;
    for(int i=0;i<2*k-1;i++){
      if(i==0||pr[i-1].first<pr[i].first){
	Pr.push_back(pr[i]);
      }
    }
    int i=0;
    pair<int,bool> ans=cal(i,Pr);
    printf("%d\n",ans.first);
  }
  return 0;
}