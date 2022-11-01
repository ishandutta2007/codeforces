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
#include <ctime>

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

string to_str(int n){
  stringstream ss;
  ss << n;
  string s = ss.str();
  while(s.size() < 4) s = "0" + s;
  return s;
}
vector<int> value[10000]; // 4-digit -> set of value
map<int, vector<int> > v_index; // value -> set of 4-digit
string str5[10000];
void init(){
  for(int n = 0; n <= 9999; n++){
    string s = to_str(n);
    str5[n] = s;
    set<int> dp[4][5];
    for(int l = 1; l <= 4; l++){
      for(int i = 0; i + l <= 4; i++){
        int x = 0;
        REP(j, l) x = x * 10 + s[i + j] - '0';
        dp[i][i + l].insert(x);
      }
    }
    for(int l = 2; l <= 4; l++){
      for(int i = 0; i + l <= 4; i++){
        int k = i + l;
        for(int j = i + 1; j < k; j++){
          FORIT(it1, dp[i][j]) FORIT(it2, dp[j][k]) dp[i][k].insert(*it1 + *it2);
          FORIT(it1, dp[i][j]) FORIT(it2, dp[j][k]) dp[i][k].insert(*it1 * *it2);
          FORIT(it1, dp[i][j]) FORIT(it2, dp[j][k]) dp[i][k].insert(*it1 - *it2);
        }
      }
    }
    FORIT(it, dp[0][4]) value[n].push_back(*it);
    FORIT(it, dp[0][4]) value[n].push_back(-1 * (*it));
    FORIT(it, dp[0][4]){
      int x = *it;
      v_index[x].push_back(n);
      v_index[-x].push_back(n);
    }
  }
}
vector<string> solve(int k, int m){
  vector<string> res;
  for(int n = 0; n <= 9999; n++){
    vector<int>& v = value[n];
    bool used[10000] = {};
    REP(i, v.size()){
      int x = v[i];
      int k2 = k - v[i];
      vector<int>& w = v_index[k2];
      REP(j, w.size()){
        int y = w[j];
        used[y] = true;
      }
    }
    REP(n2, 10000) if(used[n2]) {
      res.push_back(str5[n] + str5[n2]);
      if(res.size() == m) return res;
    }
  }
  assert(false);
}
void check(){
  clock_t last, curr;
  last = clock(); 
  init();
  curr = clock();
  printf("%f sec\n", double(curr-last)/CLOCKS_PER_SEC);
  const int MAX_M = 3 * 100000;
  const int MIN_K = 0;
  const int MAX_K = 10000;
  const int CHECK_NUM = 12;
  int check[CHECK_NUM] = {0, 1, 9, 10, 99, 100, 999, 1000, 9997, 9998, 9999, 10000};
  last = clock();
  for(int i = 0; i < CHECK_NUM; i++){
    int k = check[i];
    vector<string> res = solve(k, MAX_M);
    assert(res.size() == MAX_M);
    FORIT(it, res) assert(it->size() == 8);
    curr = clock();
    printf("k = %d is ok. (%.3fsec)\n", k, double(curr-last)/CLOCKS_PER_SEC);
    last = curr;
  }
}
int main(){
  init();
  int k, m;
  cin >> k >> m;
  vector<string> res = solve(k, m);
  REP(i, res.size()) cout << res[i] << endl;
  return 0;
}