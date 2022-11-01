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
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int to_sec(int m, int d, int hh, int mm, int ss){
  int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int sum[13] = {};
  REP(i, 12) sum[i + 1] = sum[i] + day[i];
  int res = 0;
  res += ss;
  res += mm * 60;
  res += hh * 60 * 60;
  res += (sum[m - 1] + (d - 1)) * 24 * 60 * 60;
  return res;
}

int main(){
  int N, M;
  scanf("%d %d ", &N, &M);
  string s;
  vector<int> secs;
  vector<string> strs;
  while(getline(cin, s)){
    int a, b, c, d, e;
    sscanf(s.c_str(), "2012-%d-%d %d:%d:%d", &a, &b, &c, &d, &e);
    secs.push_back(to_sec(a, b, c, d, e));
    char cs[256];
    sprintf(cs, "2012-%02d-%02d %02d:%02d:%02d", a, b, c, d, e);
    strs.push_back(string(cs));
  }
  bool output = false;
  for(int i = M - 1; i < secs.size(); i++){
    if(secs[i] - secs[i - (M - 1)] < N){
      output = true;
      cout<<strs[i]<<endl;;
      break;
    }
  }
  if(!output) cout<<-1<<endl;
  return 0;
}