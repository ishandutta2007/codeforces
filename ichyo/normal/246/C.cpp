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
map<int, vector<int> > memo;
set<int> used[50];
int N, K;
vector<int> a;
void dfs(int idx, int sum){
  if(idx >= N) return;
  if(memo.size() > K) return;
  if(used[idx].count(sum)) return;
  used[idx].insert(sum);
  vector<int> v = memo[sum];
  v.push_back(a[idx]);
  memo[sum + a[idx]] = v;
  dfs(idx + 1, sum + a[idx]);
  dfs(idx + 1, sum);
}

int main(){
  cin>>N>>K;
  a = vector<int>(N);
  REP(i, N) scanf("%d", &a[i]);
  memo[0] = vector<int>();
  dfs(0, 0);
  FORIT(it, memo){
    if(it->first == 0) continue;
    if(K == 0) break;
    K--;
    vector<int> v = it->second;
    printf("%d ",(int)v.size());
    REP(i, v.size()){
      printf("%d", v[i]);
      if(i != v.size() - 1) putchar(' ');
      else putchar('\n');
    }
  }
  return 0;
}