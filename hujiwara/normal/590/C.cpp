#include <bits/stdc++.h>
using namespace std;

const int INF=100000000;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  char M[1010][1010];
  for(int i=0;i<n;i++){
    scanf("%s",M[i]);
  }
  static int d[3][1010][1010];
  for(int c=0;c<3;c++){
    queue<pair<int,int> > Q;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	if(M[i][j]=='1'+c){
	  Q.push(make_pair(i,j));
	  d[c][i][j]=0;
	}
	else{
	  d[c][i][j]=INF;
	}
      }
    }
    while(!Q.empty()){
      int i=Q.front().first,j=Q.front().second;
      Q.pop();
      for(int v=0;v<4;v++){
	int x=i+dx[v],y=j+dy[v];
	if(x<0||n<=x||y<0||m<=y){
	  continue;
	}
	if(M[x][y]!='#'&&d[c][x][y]==INF){
	  d[c][x][y]=d[c][i][j]+1;
	  Q.push(make_pair(x,y));
	}
      }
    }
  }
  int D=INF,D2[3]={INF,INF,INF};
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      D=min(D,d[0][i][j]+d[1][i][j]+d[2][i][j]-2);
      if('1'<=M[i][j]&&M[i][j]<='3'){
	int c=M[i][j]-'1',nc=(c+1)%3;
	D2[c]=min(D2[c],d[nc][i][j]-1);
      }
    }
  }
  for(int c=0;c<3;c++){
    D=min(D,D2[c]+D2[(c+1)%3]);
  }
  printf("%d\n",D>=INF/2?-1:D);
  return 0;
}