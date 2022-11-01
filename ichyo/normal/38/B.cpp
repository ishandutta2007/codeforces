#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
bool board[8][8];
const int dx[8]={1,2,2,1,-1,-2,-2,-1};
const int dy[8]={2,1,-1,-2,-2,-1,1,2};
void check(int x, int y,int n){
  board[x][y]=true;
  if(n==1){
  REP(i,8){
    board[i][y] = true;
    board[x][i] = true;
  }
  }
  REP(r,8){
    if(x+dx[r]<8&&x+dx[r]>=0){ 
      if(y+dy[r]<8&&y+dy[r]>=0){
        board[x+dx[r]][y+dy[r]] = true;
      }
    }
  }
}
int main(void){
  int x,y,count=0;
  string line;
  cin>>line;
  x = line[0] - 'a';
  y = line[1] - '1';
  check(x,y,1);
  cin>>line;
  x = line[0] - 'a';
  y = line[1] - '1';
  check(x,y,2);
  REP(x,8){
    REP(y,8){
      if(board[x][y]) count++;
    }
  }  
  cout<<64-count<<endl;
  return 0;
}