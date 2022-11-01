#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

ll f(ll a){

  ll r = 0;
  // 2^x - 1 - 2^y, y <= x-2
  REP(x,61) REP(y,61){
    if (x-2 < y) continue;
    if (a >= ((1LL<<x)-1-(1LL<<y))) ++r;
  } return r;
  
}

int main(){

  ll a, b;
  cin >> a >> b;
  cout << f(b) - f(a-1) << endl;
  return 0;
  
}