#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > e(n);
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      a--,b--;
      e[a].push_back(b);
      e[b].push_back(a);
    }
    vector<int> ans(n,0);
    bool F=0;
    vector<bool> b(n,0);
    for(int cn=0;cn<n;cn++){
      if(b[cn])continue;
      b[cn]=1;
      vector<int> v(1,cn);
      queue<int> Q;Q.push(cn);
      while(!Q.empty()){
	int j=Q.front();Q.pop();
	for(int x=0;x<e[j].size();x++){
	  int k=e[j][x];
	  if(!b[k]){
	    b[k]=1;
	    v.push_back(k);
	    Q.push(k);
	  }
	}
      }
      int N=v.size(),M=0;
      for(int t=0;t<N;t++){
	M+=e[v[t]].size();
      }
      M/=2;
      if(N<=M){
	F=1;
	for(int t=0;t<N;t++){
	  ans[v[t]]=1;
	}
	break;
      }
      int c=0,s=-1;
      for(int t=0;t<N;t++){
	int i=v[t];
	if(e[i].size()>=4){
	  F=1;
	  ans[i]=2;
	  for(int x=0;x<4;x++){
	    ans[e[i][x]]=1;
	  }
	  break;
	}
	if(e[i].size()==3){
	  if(s==-1){
	    s=i;
	    continue;
	  }
	  vector<int> B(n,-1);
	  queue<int> Q;
	  Q.push(s);
	  B[s]=s;
	  while(!Q.empty()){
	    int j=Q.front();Q.pop();
	    for(int x=0;x<e[j].size();x++){
	      int k=e[j][x];
	      if(B[k]==-1){
		B[k]=j;
		Q.push(k);
	      }
	    }
	  }
	  int p=i;
	  while(p!=s){
	    ans[p]=2;
	    p=B[p];
	  }
	  ans[s]=2;
	  for(int x=0;x<3;x++){
	    int j=e[s][x];
	    if(ans[j]!=2)ans[j]=1;
	    j=e[i][x];
	    if(ans[j]!=2)ans[j]=1;
	  }
	  F=1;
	  break;
	}
      }
      if(F){
	break;
      }
      if(s==-1){
	continue;
      }
      pair<int,int> P[3];
      vector<int> V[3];
      for(int x=0;x<3;x++){
	int a=e[s][x],p=s;
	V[x].push_back(a);
	while(e[a].size()==2){
	  int b=e[a][0]+e[a][1]-p;
	  p=a;
	  a=b;
	  V[x].push_back(a);
	}
	P[x]=make_pair(V[x].size(),x);
      }
      //printf("%d %d %d\n",P[0].first,P[1].first,P[2].first);
      sort(P,P+3);
      int p0=P[0].second,p1=P[1].second,p2=P[2].second;
      if(P[0].first>=2){
	ans[s]=3;
	ans[V[p0][0]]=2;
	ans[V[p0][1]]=1;
	ans[V[p1][0]]=2;
	ans[V[p1][1]]=1;
	ans[V[p2][0]]=2;
	ans[V[p2][1]]=1;
	F=1;
	break;
      }
      if(P[1].first>=2&&P[2].first>=5){
	ans[s]=6;
	ans[V[p0][0]]=3;
	ans[V[p1][0]]=4;
	ans[V[p1][1]]=2;
	ans[V[p2][0]]=5;
	ans[V[p2][1]]=4;
	ans[V[p2][2]]=3;
	ans[V[p2][3]]=2;
	ans[V[p2][4]]=1;
	F=1;
	break;
      }
      if(P[1].first>=3){
	ans[s]=4;
	ans[V[p0][0]]=2;
	ans[V[p1][0]]=3;
	ans[V[p1][1]]=2;
	ans[V[p1][2]]=1;
	ans[V[p2][0]]=3;
	ans[V[p2][1]]=2;
	ans[V[p2][2]]=1;
	F=1;
	break;
      }
    }
    if(!F)puts("NO");
    else{
      puts("YES");
      for(int i=0;i<n;i++){
	printf("%d ",ans[i]);
      }
      putchar('\n');
    }
  }
  return 0;
}