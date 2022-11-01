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

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  vector<ll> fib;
  fib.push_back(0);
  fib.push_back(1);
  while(true){
    ll next = (ll)fib.back() +  fib[fib.size()-2];
    if(next >= 1000000000) break;
    fib.push_back(next);
  }
  int N = fib.size();
  int n;
  while(cin>>n){
    REP(i, N) FOR(j, i, N) FOR(k, j, N){
      ll a = fib[i] + fib[j] + fib[k];
      if(a == n){
        cout<<fib[i]<<" "<<fib[j]<<" "<<fib[k]<<endl;
        goto END;
      }else if(i == N-1 && i == j && j == k){
        cout<<"I'm too stupid to solve this problem"<<endl;
      }
    }
END:;
  }
  return 0;
}