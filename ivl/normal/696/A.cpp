#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

map < ll, ll > cost;

ll f(ll &x, ll &y){
  ll tmp;
  if (x < y) tmp = y, y /= 2;
  else tmp = x, x /= 2;
  return tmp;
}

int main(){
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  REP(ttt,q){
    ll t, v, u;
    cin >> t >> v >> u;
    if (t == 1){
      ll w; cin >> w;
      while (u != v) cost[f(u, v)] += w;
    } else {
      ll r = 0;
      while (u != v) r += cost[f(u, v)];
      cout << r << endl;
    }
  }

  return 0;
}