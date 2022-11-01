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
string solve(string s, string t){
  if(s.size() != t.size()) return "NO";
  int N = s.size();
  vector<int> v;
  REP(i,N)if(s[i]!=t[i])v.push_back(i);
  if(v.size() != 2) return "NO";
  swap(s[v[0]], s[v[1]]);
  if(s == t) return "YES";
  else return "NO";
}

int main(){
  string s,t;
  while(cin>>s>>t){
    cout<<solve(s,t)<<endl;
  }
    
  return 0;
}