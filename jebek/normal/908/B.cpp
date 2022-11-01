#include<iostream>
#include<algorithm>
using namespace std;

int f[4],n,m,ans,xs,ys;
char c[100][100];
string s;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int go(int x,int y,int ind)
{
  if(x<0 || x>=n || y<0 || y>=m || c[x][y]=='#') return 0;
  if(c[x][y]=='E') return 1;
  if(ind>=s.size()) return 0;
  x+=dx[f[int(s[ind]-'0')]];
  y+=dy[f[int(s[ind]-'0')]];
  return go(x,y,ind+1);
}

int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      {
	cin>>c[i][j];
	if(c[i][j]=='S') xs=i,ys=j;
      }
  cin>>s;
  for(int i=0;i<4;i++)
    f[i]=i;
  do{
    ans+=go(xs,ys,0);
  }while(next_permutation(f,f+4));
  cout<<ans<<endl;
}