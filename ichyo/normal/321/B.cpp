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
int tact1(vector<string> type, vector<int> val, vector<int> ciel){
  vector<int> val2;
  REP(i, type.size()) if(type[i] == "ATK") val2.push_back(val[i]);
  sort(ciel.begin(), ciel.end());
  reverse(ciel.begin(), ciel.end());
  int ans = 0;
  sort(val2.begin(), val2.end());
  REP(i, min(ciel.size(), val2.size())){
    if(ciel[i] >= val2[i]){
      ans += ciel[i] - val2[i];
    }else{
      break;
    }
  }
  return ans;
}
int tact2(vector<string> type, vector<int> val, vector<int> ciel){
  sort(ciel.begin(), ciel.end());
  REP(i, type.size()) if(type[i] == "DEF"){
    int k = upper_bound(ciel.begin(), ciel.end(), val[i]) - ciel.begin();
    if(k == ciel.size()) return 0;
    ciel.erase(ciel.begin() + k);
  }
  vector<int> val2;
  REP(i, type.size()) if(type[i] == "ATK") val2.push_back(val[i]);
  sort(val2.begin(), val2.end());
  reverse(val2.begin(), val2.end());
  sort(ciel.begin(), ciel.end());
  reverse(ciel.begin(), ciel.end());
  if(val2.size() > ciel.size()) return 0;
  int ans = 0;
  for(int i = 0; i < val2.size(); i++){
    if(val2[i] > ciel[i]) return 0;
    ans += ciel[i] - val2[i];
  }
  for(int i = val2.size(); i < ciel.size(); i++){
    ans += ciel[i];
  }
  return ans;
}

int main(){
  int N, M;
  while(cin >> N >> M){
    vector<string> type(N);
    vector<int> val(N);
    REP(i, N) cin >> type[i] >> val[i];
    vector<int> ciel(M);
    REP(i, M) cin >> ciel[i];
    //printf("%d %d\n", tact1(type, val, ciel), tact2(type, val, ciel));
    cout << max(tact1(type, val, ciel), tact2(type, val, ciel)) << endl;
  }
  return 0;
}