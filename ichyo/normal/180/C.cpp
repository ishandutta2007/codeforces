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
const int SIZE = 100000+1;

int main(){
  string s;
  while(cin>>s){
  int n = s.size();
  int sum[SIZE]={};
  REP(i,n)sum[i+1] = sum[i] + isupper(s[i]);
  int ans = INF;
  for(int i = 0; i <= s.size(); i++){
    int m = 0;
    m += i - sum[i];
    m += sum[n] - sum[i];
    ans = min(ans, m);
  }
  cout<<ans<<endl;
  }
  return 0;
}