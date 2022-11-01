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
typedef pair<int,int> P;

int main(){
  int n;
  while(cin>>n){
    vector<P> v(n);
    REP(i,n){
      cin>>v[i].first;
    }
    REP(i,n){
      cin>>v[i].second;
    }
    sort(v.begin(), v.end());
    REP(i,n){
      cout<<v[i].second;
      putchar((i==n-1)?'\n':' ');
    }
  }
  return 0;
}