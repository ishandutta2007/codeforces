#include <cstdio>
#include <queue>
using namespace std;

int main()
{
  static int B[1000][1000]={0},b[1000][1000]={0};
  const int S=500;
  int n;
  scanf("%d",&n);
  queue<pair<int,int> > Q;
  B[S][S]+=n;
  Q.push(make_pair(S,S));
  b[S][S]=1;
  while(!Q.empty()){
    pair<int,int> p=Q.front();
    Q.pop();
    int x=p.first,y=p.second;
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    for(int v=0;v<4;v++){
      int X=x+dx[v],Y=y+dy[v];
      B[X][Y]+=B[x][y]/4;
      if(B[X][Y]>=4&&!b[X][Y]){
	Q.push(make_pair(X,Y));
	b[X][Y]=1;
      }
      /*if(X<=0||2*S<=X||Y<=0||2*S<=Y){
	printf("%d %d\n",X,Y);
	}*/
    }
    B[x][y]%=4;
    b[x][y]=0;
  }
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d\n",x<=-S||S<=x||y<=-S||S<=y?0:B[x+S][y+S]);
  }
  return 0;
}