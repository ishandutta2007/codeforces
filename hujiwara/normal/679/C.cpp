#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  static char M[500][510];
  for(int i=0;i<n;i++){
    scanf("%s",M[i]);
  }
  vector<int> S,x1,x2,y1,y2;
  static int b[500][500];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      b[i][j]=-1;
    }
  }
  int N=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(M[i][j]!='.'||b[i][j]!=-1){
	continue;
      }
      queue<pair<int,int> > Q;
      Q.push(make_pair(i,j));
      b[i][j]=N;
      int s=1,X1=i,X2=i,Y1=j,Y2=j;
      while(!Q.empty()){
	int x=Q.front().first,y=Q.front().second;
	Q.pop();
	for(int v=0;v<4;v++){
	  int xx=x+dx[v],yy=y+dy[v];
	    if(0<=xx&&yy<n&&0<=yy&&yy<n&&M[xx][yy]=='.'&&b[xx][yy]==-1){
	      b[xx][yy]=N;
	      s++;
	      X1=min(X1,xx),X2=max(X2,xx);
	      Y1=min(Y1,yy),Y2=max(Y2,yy);
	      Q.push(make_pair(xx,yy));
	    }
	}
      }
      S.push_back(s);
      x1.push_back(X1);
      x2.push_back(X2);
      y1.push_back(Y1);
      y2.push_back(Y2);
      N++;
    }
  }
  static int R1[501][501],R[501][501];
  for(int i=0;i<n;i++){
    R1[i][0]=0;
    for(int j=0;j<n;j++){
      R1[i][j+1]=R1[i][j]+(M[i][j]=='.'?1:0);
    }
  }
  for(int j=0;j<=n;j++){
    R[0][j]=0;
    for(int i=0;i<n;i++){
      R[i+1][j]=R[i][j]+R1[i][j];
    }
  }
  int ans=0;
  for(int i=0;i+k<=n;i++){
    int I=0;
    vector<int> A(N,-1);
    vector<bool> B(N,0);
    for(int c=0;c<N;c++){
      if(i<=x1[c]&&x2[c]<i+k&&y2[c]<k){
	B[c]=1;
	I+=S[c];
      }
    }
    for(int j=0;j+k<=n;j++){
      int t=0;
      if(i>0){
	for(int p=0;p<k;p++){
	  int c=b[i-1][j+p];
	  if(c!=-1&&A[c]!=j){
	    A[c]=j;
	    t+=S[c];
	  }
	}
      }
      if(i+k<n){
	for(int p=0;p<k;p++){
	  int c=b[i+k][j+p];
	  if(c!=-1&&A[c]!=j){
	    A[c]=j;
	    t+=S[c];
	  }
	}
      }

      if(j>0){
	for(int p=0;p<k;p++){
	  int c=b[i+p][j-1];
	  if(c!=-1&&A[c]!=j){
	    A[c]=j;
	    t+=S[c];
	  }
	}
      }

      if(j+k<n){
	for(int p=0;p<k;p++){
	  int c=b[i+p][j+k];
	  if(c!=-1&&A[c]!=j){
	    A[c]=j;
	    t+=S[c];
	  }
	}
      }
      t-=R[i+k][j+k]-R[i+k][j]-R[i][j+k]+R[i][j]-I;
      t+=k*k;
      ans=max(ans,t);
      if(j+k==n){
	break;
      }
      for(int p=0;p<k;p++){
	int c=b[i+p][j];
	if(c!=-1&&B[c]){
	  B[c]=0;
	  I-=S[c];
	}
      }
      for(int p=0;p<k;p++){
	int c=b[i+p][j+k];
	if(c!=-1&&!B[c]&&i<=x1[c]&&x2[c]<i+k&&j+1<=y1[c]&&y2[c]<j+k+1){
	  B[c]=1;
	  I+=S[c];
	}
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}