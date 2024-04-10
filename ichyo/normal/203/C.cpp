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
typedef pair<ll,ll> P;

int main(){
  ll n, d;
  while(cin>>n>>d){
    ll a, b; cin>>a>>b;
    vector<P> v(n);
    REP(i, n){
      ll x, y; cin>>x>>y;
      v[i] = P(a*x+b*y, i);
    }
    sort(v.begin(), v.end());
    vector<ll> ans;
    REP(i, n){
      if(d - v[i].first >= 0){
        d -= v[i].first;
        ans.push_back(v[i].second);
      }
    }
    cout<<ans.size()<<endl;
    REP(i, ans.size()){
      cout<<ans[i] + 1;
      if(i != ans.size() - 1) cout<<" ";
      else cout<<endl;
    }
  }


  return 0;
}