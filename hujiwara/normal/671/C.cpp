#include <bits/stdc++.h>
using namespace std;

const int N=200000;
const int INF=10000000;

void setadd(set<pair<int,int> > &s,long long &S,int j,int i,int d)
{
  set<pair<int,int> >::iterator it=s.upper_bound(make_pair(i,INF));
  it--;
  bool F=0;
  while(it!=s.end()&&it->second<d){
    set<pair<int,int> >::iterator nx=it;
    nx++;
    S+=((nx!=s.end()?nx->first:j)-max(it->first,i))*(d-it->second);
    if(it->first>=i){
      s.erase(it);
    }
    it=nx;
    F=1;
  }
  if(F){
    s.insert(make_pair(i,d));
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  static int a[N];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  static int C[N+1]={0},m1[N+1],m2[N+1],M1[N+1],M2[N+1];
  for(int i=1;i<=N;i++){
    m1[i]=m2[i]=n;
    M1[i]=M2[i]=-1;
  }
  for(int i=0;i<n;i++){
    int j=a[i];
    C[j]++;
    if(m1[j]==n){
      m1[j]=i;
    }
    else if(m2[j]==n){
      m2[j]=i;
    }
    M2[j]=M1[j];
    M1[j]=i;
  }
  static int A[N]={0},B[N+1]={0};
  static vector<pair<int,int> > V[N];
  for(int d=1;d<=N;d++){
    int x1=n,x2=n,y1=-1,y2=-1;
    for(int j=d;j<=N;j+=d){
      if(x1>m1[j]){
	x2=x1;
	x1=m1[j];
      }
      else if(x2>m1[j]){
	x2=m1[j];
      }
      if(x2>m2[j]){
	x2=m2[j];
      }
      if(y1<M1[j]){
	y2=y1;
	y1=M1[j];
      }
      else if(y2<M1[j]){
	y2=M1[j];
      }
      if(y2<M2[j]){
	y2=M2[j];
      }
    }
    if(x2+1<n){
      B[x2+1]=max(B[x2+1],d);
    }
    if(y2>=0){
      A[y2]=max(A[y2],d);
    }
    if(x1+1<y1){
      V[y1].push_back(make_pair(d,x1));
    }
  }
  set<pair<int,int> > s;
  s.insert(make_pair(0,0));
  int D2=0;
  long long S=0;
  for(int i=0;i<n;i++){
    if(D2<B[i]){
      D2=B[i];
      s.insert(make_pair(i,D2));
    }
    S+=(--s.end())->second;
    //printf("%d %d %d\n",i,B[i],(--s.end())->second);
  }
  long long ans=S;
  //printf("%lld\n",ans);
  int D=0;
  for(int j=n-1;j>0;j--){
    S-=(--s.end())->second;
    //printf("%d %d\n",(--s.end())->first,(--s.end())->second);
    if((--s.end())->first==j){
      s.erase(--s.end());
    }
    //printf("S %lld\n",S);
    D=max(D,A[j]);
    setadd(s,S,j,0,D);
    //printf("S %lld\n",S);
    for(int t=0;t<V[j].size();t++){
      setadd(s,S,j,V[j][t].second+1,V[j][t].first);
      //printf("%d %d %d\n",j,V[j][t].second,V[j][t].first);
    }
    //printf("S %lld\n",S);
    ans+=S;
    //printf("%lld\n",ans);
  }
  printf("%lld\n",ans);
  return 0;
}