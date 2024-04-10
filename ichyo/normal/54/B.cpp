#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
vector<string> rotate(vector<string> grid){
  vector<string> ret;
  int sizey = grid.size();
  int sizex = grid[0].size();
  REP(x,sizex){
    string emp;
    REP(y,sizey){
      emp += grid[sizey-1-y][x];
    }
    ret.push_back(emp);
  }
  return ret;
}
int main(void){
  int H,W;
  int ans = 0;
  int minarea = 1e8;
  PII minans(1e8,1e8);
  cin>>H>>W;
  vector<string> grid(H);
  REP(i,H)cin>>grid[i];
  for(int dy = 1;dy<=H;dy++){
    if(H%dy!=0) continue;
    for(int dx = 1; dx<=W; dx++){
      if(W%dx!=0) continue;
      set< vector<string> > exi;
      bool NO = false;
      for(int ky = 0; ky*dy<H; ky++){
        for(int kx = 0; kx*dx<W; kx++){
          vector<string> piece;
          int bx = kx*dx;
          int by = ky*dy;
          REP(i,dy){
            piece.push_back(grid[by+i].substr(bx,dx));
          }
          REP(i,4){
            piece = rotate(piece);
            if(exi.find(piece)!=exi.end()){
              NO = true;
              goto END;
            }
          }
          exi.insert(piece);
        }
      }
END:
      if(!NO){
        ans++;
        if(dx*dy<=minarea){
          if(minarea==dx*dy){
            if(dy<minans.first) minans = PII(dy,dx);
          }else{
            minans = PII(dy,dx);
          }
          minarea = dx*dy;
        }
      }
    }
  }
  cout<<ans<<endl;
  cout<<minans.first<<" "<<minans.second<<endl;
  return 0;
}