#include <bits/stdc++.h>
using namespace std;

vector<int> a0,a1,a2,a3;
vector<vector<int> > M;
void move(int i,int j,int k,int l)
{
  a0.push_back(i);
  a1.push_back(j);
  a2.push_back(k);
  a3.push_back(l);
  //printf("%d %d %d %d\n",i+1,j+1,k+1,l+1);
  assert(M[i][j]!=-1);
  assert(M[k][l]==-1);
  M[k][l]=M[i][j];
  M[i][j]=-1;
}

int n,m;

vector<int> sol(vector<int> &x,vector<int> &y)
{
  M=vector<vector<int> >(n,vector<int>(n,-1));
  for(int i=0;i<m;i++){
    M[x[i]-1][y[i]-1]=i;
  }
  vector<int> T(n,0);
  int t=0;
  for(int i=0;i<n;i++){
    int T=0;
    for(int j=0;j<n;j++){
      if(M[i][j]!=-1){
	T++;
      }
    }
    for(int j=0;j<t;j++){
      if(M[i][j]!=-1){
	int k=j+1;
	while(M[i][k]!=-1){
	  k++;
	}
	while(k>j){
	  move(i,k-1,i,k);
	  k--;
	}
      }
    }
    for(int j=n-1;j>=t+T;j--){
      if(M[i][j]!=-1){
	int k=j-1;
	while(M[i][k]!=-1){
	  k--;
	}
	while(k<j){
	  move(i,k+1,i,k);
	  k++;
	}
      }
    }
    for(int j=t;j<t+T;j++){
      for(int k=i;k>0;k--){
	move(k,j,k-1,j);
      }
    }
    t+=T;
  }
  vector<int> a(m);
  for(int i=0;i<m;i++){
    a[i]=M[0][i];
  }
  return a;
}

int main()
{
  scanf("%d%d",&n,&m);
  if(n==1){
    printf("0\n");
    return 0;
  }
  vector<int> x0(m),y0(m),x1(m),y1(m);
  for(int i=0;i<m;i++){
    scanf("%d%d",&x0[i],&y0[i]);
  }
  for(int i=0;i<m;i++){
    scanf("%d%d",&x1[i],&y1[i]);
  }
  vector<int> A0,A1,A2,A3,B0,B1,B2,B3;
  //puts("A");
  vector<int> S1=sol(x1,y1);
  B0=a0,B1=a1,B2=a2,B3=a3;
  a0.clear(),a1.clear(),a2.clear(),a3.clear();
  //puts("B");
  vector<int> S0=sol(x0,y0);
  //puts("C");
  for(int i=0;i<m;i++){
    int g=-1;
    for(int t=i;t<m;t++){
      if(M[0][t]==S1[i]){
	g=t;
	break;
      }
    }
    move(0,g,1,g);
    for(int k=g;k>i;k--){
      move(1,k,1,k-1);
      move(0,k-1,0,k);
    }
    move(1,i,0,i);
  }
  A0=a0,A1=a1,A2=a2,A3=a3;
  a0.clear(),a1.clear(),a2.clear(),a3.clear();
  for(int t=B0.size()-1;t>=0;t--){
    A0.push_back(B2[t]);
    A1.push_back(B3[t]);
    A2.push_back(B0[t]);
    A3.push_back(B1[t]);
  }
  printf("%d\n",(int)A0.size());
  for(int t=0;t<A0.size();t++){
    printf("%d %d %d %d\n",A0[t]+1,A1[t]+1,A2[t]+1,A3[t]+1);
  }
  return 0;
}