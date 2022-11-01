#include <bits/stdc++.h>
using namespace std;

namespace std{
  bool operator<(vector<int> v1,vector<int> v2)
  {
    for(int x=0;x<v1.size()&&x<v2.size();x++){
      if(v1[x]!=v2[x]){
	return v1[x]<v2[x];
      }
    }
    return v1.size()<v2.size();
  }
};

int sub[100000];

void dfs(int i,int p,vector<vector<int> > &e)
{
  sub[i]=1;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p){
      continue;
    }
    dfs(j,i,e);
    sub[i]+=sub[j];
  }
}

int cent(vector<vector<int> > &e)
{
  dfs(0,-1,e);
  int a=0,p=-1,n=sub[0];
  while(1){
    int S=0,q=-1;
    for(int x=0;x<e[a].size();x++){
      int j=e[a][x];
      if(j==p){
	continue;
      }
      if(S<sub[j]){
	S=sub[j];
	q=j;
      }
    }
    if(S<=n/2){
      break;
    }
    p=a;
    a=q;
  }
  return a;
}

void makesubtr(int i,int p,vector<vector<int> > &e,vector<vector<int> > &ne,vector<int> &X)
{
  int a=ne.size();
  X.push_back(i);
  ne.push_back(vector<int>(0));
  for(int y=0;y<e[i].size();y++){
    int j=e[i][y];
    if(j!=p){
      int b=ne.size();
      makesubtr(j,i,e,ne,X);
      ne[a].push_back(b);
      ne[b].push_back(a);
    }
  }
}

void rec(vector<vector<int> > &e,vector<int> &A){
  int n=e.size(),c=cent(e);
  A[c]=1;
  //printf("%d %d\n",n,c);
  for(int x=0;x<e[c].size();x++){
    int i=e[c][x];
    vector<vector<int> > ne;
    vector<int> X;
    makesubtr(i,c,e,ne,X);
    int N=ne.size();
    vector<int> SA(N);
    rec(ne,SA);
    for(int i=0;i<N;i++){
      A[X[i]]=SA[i]+1;
    }
  }
}


int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int a[100000],b[100000];
  for(int i=0;i<m;i++){
    scanf("%d%d",a+i,b+i);
    a[i]--,b[i]--;
  }
  static vector<vector<int> > e(n);
  for(int i=0;i<n;i++){
    e[i].push_back(1);
    e[i].push_back(n-1);
  }
  for(int i=0;i<m;i++){
    e[a[i]].push_back((b[i]+n-a[i])%n);
    e[b[i]].push_back((a[i]+n-b[i])%n);
  }
  vector<vector<int> > B(n);
  for(int i=0;i<n;i++){
    sort(e[i].begin(),e[i].end());
    B[i]=vector<int>(e[i].size()-1,-1);
    /*for(int x=0;x<e[i].size();x++){
      printf("%d %d\n",i,e[i][x]);
      }*/
  }
  int T=0;
  static vector<int> M[100010];
  for(int i=0;i<n;i++){
    for(int x=0;x<e[i].size()-1;x++){
      if(B[i][x]!=-1){
	continue;
      }
      M[T].push_back(i);
      B[i][x]=T;
      int j=(i+e[i][x+1])%n,p=i;
      while(j!=i){
	M[T].push_back(j);
	int y=lower_bound(e[j].begin(),e[j].end(),(p+n-j)%n)-e[j].begin();
	B[j][y]=T;
	//printf("%d %d %d %d\n",j,p,y,e[j][y+1]);
	p=j;
	j=(j+e[j][y+1])%n;
      }
      T++;
    }
  }
  static pair<vector<int>,int> P[100010];
  for(int i=0;i<=m;i++){
    P[i].first=M[i];
    sort(P[i].first.begin(),P[i].first.end(),greater<int>());
    P[i].second=i;
  }
  sort(P,P+m+1);
  vector<vector<int> > E(m+1);
  for(int i=0;i<n;i++){
    for(int x=0;x+2<e[i].size();x++){
      //printf("%d %d\n",B[i][x],B[i][x+1]);
      E[B[i][x]].push_back(B[i][x+1]);
    }
  }
  vector<int> A(m+1);
  rec(E,A);
  for(int i=0;i<=m;i++){
    int k=A[P[i].second];
    printf("%d%c",k,i==m?'\n':' ');
  }
  return 0;
}