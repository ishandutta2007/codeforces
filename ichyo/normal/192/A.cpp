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
//C++11
#if __cplusplus == 201103L
#include <tuple>
#endif

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int main(){
  int n;
  vector<int> tri;
  set<int> check;
  const ll MAX = 1000000000;
  for(ll n = 1; n * (n + 1) /2 < MAX; n++){
    tri.push_back(n * (n + 1) /2);
    check.insert(n * (n + 1) / 2);
  }
  int N = tri.size();
  while(cin>>n && n){
    bool ok = false;
    for(int i = 0; i < N && tri[i] < n; i++){
      int m = n - tri[i];
      if(check.count(m)) ok = true;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }

  return 0;
}