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
vector<int> permut(int n){
  vector<int> res(n);
  REP(i, n) res[i] = i;
  return res;
}
void test(int n){
  vector<int> v1 = permut(n);
  vector<int> v2 = permut(n);
  vector<int> v3 = permut(n);
  do{
    do{
      bool ok = true;
      REP(i, n) if((v1[i] + v2[i]) % n != v3[i]) ok = false;
      if(!ok) continue;
      debug(v2.begin(), v2.end());
      debug(v3.begin(), v3.end());
      cout << endl;
    }while(next_permutation(v3.begin(), v3.end()));
  }while(next_permutation(v2.begin(), v2.end()));
}
void output(vector<int>& v){
  for(int i = 0; i < v.size(); i++){
    cout << v[i];
    if(i == v.size() - 1) cout << endl;
    else cout << " ";
  }
}

void solve(int n){
  if(n % 2 == 0){
    cout << -1 << endl;
    return;
  }
  vector<int> v1 = permut(n), v2 = permut(n);
  vector<int> v3(n);
  REP(i, n) v3[i] = (v1[i] + v2[i]) % n;
  output(v1);
  output(v2);
  output(v3);
}

int main(){
  int n;
  while( cin >> n){
    solve(n);
  }
  return 0;
}