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
  int x, t, a, b, da, db;
  while(cin>>x>>t>>a>>b>>da>>db){
    bool ans = false;
    REP(i, t)REP(j, t){
      if(a - i * da + b - j * db == x){
        ans = true;
      }
      if(a - i * da == x){
        ans = true;
      }
      if(b - j * db == x){
        ans = true;
      }
      if(x == 0){
        ans = true;
      }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}