#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
int dx[8] = {-1,-1,0,1,1,0,1,-1};
int dy[8] = {0,1,1,1,0,0,-1,-1};
char grid[8][9];
bool used[8][8];
bool valid(int x,int y){
  return x>=0&&x<8&&y>=0&&y<8;
}
bool dfs(int x,int y){
  if(y >= 7)return true;
  if(used[y][x]) return false;
  used[y][x] = true;
  REP(r,8){
    int nx = x+dx[r];
    int ny = y+dy[r];
    if(valid(nx,ny)&&grid[ny][nx]!='S'){
      ny++;
      if(!valid(nx,ny)||grid[ny][nx]!='S'){
        if(dfs(nx,ny)) return true;
      }
    }
  }
  return false;
}
int main(){
  REP(i,8)cin>>grid[7-i];
  if(dfs(0,0))cout<<"WIN"<<endl;
  else cout<<"LOSE"<<endl;
  return 0;
}