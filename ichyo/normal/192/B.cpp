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
typedef pair<int, int> P;

int main(){
  int N;
  while(cin>>N && N){
    vector<P> event(N);
    REP(i, N){
      int A; cin>>A;
      event[i] = P(A, i);
    }
    sort(event.begin(), event.end());
    bool breaked[1000] = {};
    REP(t, N){
      breaked[event[t].second] = true;
      bool ok = true;
      if(breaked[0] || breaked[N-1]) ok = false;
      for(int i = 0; i < N - 1; i++){
        if(breaked[i] && breaked[i+1]) ok = false;
      }
      if(!ok){
        cout<<event[t].first<<endl;
        break;
      }
    }
  }
  return 0;
}