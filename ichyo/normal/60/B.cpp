#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
//grid[z][x][y]
//y+100*x+10000*k
int k,n,m;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int pti(int x,int y,int k){
  return y+100*x+10000*k;
}
bool ok(int x,int y,int z){
  if(x<1||x>n) return false;
  if(y<1||y>m) return false;
  if(z<1||z>k) return false;
  return true;
}
int main(void){
  string grid[11][11];
  bool used[11][11][11]={};
  cin>>k>>n>>m;
  REP(i,k){
    REP(j,n){
      cin>>grid[i][j];
    }
  }
  int x,y;
  cin>>x>>y;
  queue<PII> que; 
  que.push(PII(pti(x,y,1),0));
  int ans = 0;
  while(!que.empty()){
    int nx,ny,nz;
    PII p = que.front(); que.pop();
    int tmp = p.first;
    ny = tmp%100; tmp/=100;
    nx = tmp%100; tmp/=100;
    nz = tmp%100;
    if(used[nx][ny][nz]) continue;
    used[nx][ny][nz] = true;
    if(grid[nz-1][nx-1][ny-1]=='#') continue;
    //printf("%d:%d,%d,%d\n",ans,nx,ny,nz);
    ans++;
    REP(r,6){
      int xx = nx + dx[r];
      int yy = ny + dy[r];
      int zz = nz + dz[r];
      if(ok(xx,yy,zz)){
        que.push(PII(pti(xx,yy,zz),p.second+1));
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}