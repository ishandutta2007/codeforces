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
string solve(string& s, string& t){
  if(s.size() != t.size()) return "NO";
  int cnt[2] = {};
  REP(i, s.size()) cnt[0] += (s[i] - '0');
  REP(i, t.size()) cnt[1] += (t[i] - '0');
  if(cnt[0] == 0 || cnt[1] == 0){
    if(cnt[0] == cnt[1]) return "YES";
    else return "NO";
  }else{
    return "YES";
  }
}

int main(){
  string s;
  string t;
  cin>>s>>t;
  cout<<solve(s, t)<<endl;
  return 0;
}