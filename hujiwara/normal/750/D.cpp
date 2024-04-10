#include <bits/stdc++.h>
using namespace std;

const int PARA=8,SZ=160;
bool P[2][400][400]={0};
pair<int,int> Q[1<<(PARA+1)];
int A[1<<(PARA+1)];
int M;

int dx[2][4]={{0,-1,0,1},{1,-1,-1,1}};
int dy[2][4]={{1,0,-1,0},{1,1,-1,-1}};

void rec(int *t,int k,int n,int ang,int x,int y,bool tp)
{
  //printf("%d %d %d %d\n",k,x,y,ang);
  if(k==n){
    if(tp){
      Q[M]=make_pair(x,y);
      A[M]=ang;
      M++;
    }
    return;
  }
  for(int i=0;i<t[k];i++){
    P[tp][x+i*dx[k%2][ang]+SZ][y+i*dy[k%2][ang]+SZ]=1;
  }
  int nx=x+(t[k]-1)*dx[k%2][ang],ny=y+(t[k]-1)*dy[k%2][ang];
  int nang=(ang+(k%2==0?1:3))%4;
  rec(t,k+1,n,ang,nx+dx[(k+1)%2][ang],ny+dy[(k+1)%2][ang],tp);
  rec(t,k+1,n,nang,nx+dx[(k+1)%2][nang],ny+dy[(k+1)%2][nang],tp);
}

int main()
{
  int n;
  scanf("%d",&n);
  int t[100];
  for(int i=0;i<n;i++){
    scanf("%d",t+i);
  }
  int m=min(n,PARA);
  M=0;
  rec(t,m,n,0,0,0,0);
  rec(t,0,m,0,0,0,1);
  int ans=0;
  for(int x=-SZ;x<=SZ;x++){
    for(int y=-SZ;y<=SZ;y++){
      if(P[1][x+SZ][y+SZ]){
	ans++;
	continue;
      }
      for(int t=0;t<M;t++){
	int tx=x-Q[t].first,ty=y-Q[t].second;
	if(A[t]==1){
	  int ttx=ty,tty=-tx;
	  tx=ttx,ty=tty;
	}
	else if(A[t]==2){
	  tx*=-1;
	  ty*=-1;
	}
	else if(A[t]==3){
	  int ttx=-ty,tty=tx;
	  tx=ttx,ty=tty;
	}
	if(-SZ<=tx&&tx<=SZ&&-SZ<=ty&&ty<=SZ&&P[0][tx+SZ][ty+SZ]){
	  //printf("%d %d %d %d %d\n",x,y,Q[t].first,Q[t].second,A[t]);
	  ans++;
	  break;
	}
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}