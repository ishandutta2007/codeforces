#include <bits/stdc++.h>
using namespace std;

struct pt
{
  int i,j,v,c;
};

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static char s[1010][1010];
  for(int i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  static bool B[1010][1010][4][3]={0};
  queue<pt> Q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='S'){
	for(int v=0;v<4;v++){
	  pt p;
	  p.i=i,p.j=j,p.v=v,p.c=0;
	  Q.push(p);
	  B[i][j][v][0]=1;
	}
      }
    }
  }
  int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
  while(!Q.empty()){
    pt p=Q.front();
    Q.pop();
    int i=p.i,j=p.j,v=p.v,c=p.c;
    int ni=i+di[v],nj=j+dj[v];
    if(0<=ni&&ni<n&&0<=nj&&nj<m&&s[ni][nj]!='*'&&!B[ni][nj][v][c]){
      B[ni][nj][v][c]=1;
      pt np;
      np.i=ni,np.j=nj,np.v=v,np.c=c;
      Q.push(np);
    }
    if(c<2){
      for(int nv=0;nv<4;nv++){
	if(!B[i][j][nv][c+1]){
	  B[i][j][nv][c+1]=1;
	  pt np;
	  np.i=i,np.j=j,np.v=nv,np.c=c+1;
	  Q.push(np);
	}
      }
    }
  }
  bool F=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='T'){
	for(int v=0;v<4;v++){
	  for(int c=0;c<3;c++){
	    F|=B[i][j][v][c];
	  }
	}
      }
    }
  }
  puts(F?"YES":"NO");
  return 0;
}