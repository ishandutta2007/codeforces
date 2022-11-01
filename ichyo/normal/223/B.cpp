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
int binary(vector<int>& v, int n){
  if(v.empty()) return -1;
  if(v[0] > n) return -1;
  int b = 0, f = v.size();
  while(f - b > 1){
    int m = (f + b) / 2;
    if(v[m] <= n){
      b = m;
    }else{
      f = m;
    }
  }
  assert(f == v.size() || v[f] > n);
  assert(v[b] <= n);
  return v[b];
}
bool solve(string s, string t){
  int need[200001] = {};
  vector<int> c_idx[26];
  for(int i = s.size() - 1, now = t.size();  i >= 0; i--){
    if(now - 1 >= 0 && t[now-1] == s[i]){
      now --;
    }
    need[i] = now;
  }
  int N = s.size(), M = t.size();
  REP(i, M) c_idx[t[i] - 'a'].push_back(i);
  int last_idx = -1;
  REP(i, N){
    int use_idx = binary(c_idx[s[i] - 'a'], min(last_idx + 1, M - 1));
    if(use_idx == -1 || use_idx < need[i]) {
      return false;
    }
    if(use_idx == last_idx + 1) last_idx = use_idx;
  }
  assert(last_idx == M - 1);
  return true;
}

int main(){
  string s, t;
  while(cin>>s>>t){
    if(solve(s, t)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}