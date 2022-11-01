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

int main(){
  int N, M;
  cin>>N>>M;
  vector<int> color(N);
  REP(i, N) scanf("%d", &color[i]);
  set<int> neibor[100000];
  REP(i, M){
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    int c1 = color[u];
    int c2 = color[v];
    if(c1 != c2){
      neibor[c1].insert(c2);
      neibor[c2].insert(c1);
    }
  }
  int ans = color[0];
  REP(i, N){
    int c = color[i];
    if(neibor[c].size() > neibor[ans].size() || 
        (neibor[c].size() == neibor[ans].size() && c < ans)){
      ans = c;
    }
  }
  cout<<ans<<endl;
  return 0;
}