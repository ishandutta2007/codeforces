#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <map>
using namespace std;
typedef long long LL;
static const double EPS = 1e-9;
typedef pair<int,int> P;
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int n,m,k;
bool full[30][30];
map<string, P> mp;
P find(int x, int y){
  for(int j=y; j<m; j++){
    if(!full[x][j]){
      full[x][j]=true;
      return P(x,j);
    }
  }
  for(int i=x+1;i<n;i++){
    for(int j=0;j<m;j++){
      if(!full[i][j]){
        full[i][j]=true;
        return P(i,j);
      }
    }
  }
  return P(-1,-1);
}

int main(void){
  ifstream infile("input.txt");
  ofstream outfile("output.txt"); 
  infile>>n>>m>>k;
  set<string> nameset;
  int count=0;
  REP(i,k){
    string pl;
    int x,y;
    string name;
    infile>>pl;
    if(pl=="+1"){
      infile>>x>>y>>name;
      P point = find(x-1,y-1);
      if(point.first==-1) continue;
      mp.insert(pair<string, P>(name,point));
      nameset.insert(name);
    }else{
      infile>>name;
      if(nameset.find(name)==nameset.end()){
        outfile<<"-1 -1"<<endl;
      }else{
      P point = mp[name];
      int x=point.first;
      int y=point.second;
      full[x][y]=false;
      mp.erase(name);
      nameset.erase(name);
      outfile<<x+1<<" "<<y+1<<endl;
      }
    }
  }
  return 0;
}