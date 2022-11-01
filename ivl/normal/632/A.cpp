#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int main(){

  int n, p;
  cin >> n >> p;
  vector < string > v(n);
  REP(i,n) cin >> v[i];

  int cnt = 0;
  ll t = 0;
  reverse(v.begin(), v.end());
  for (auto x : v){
    t <<= 1;
    if (x == "halfplus") ++t, ++cnt;
  }

  cout << t*p - cnt*p/2 << endl;
  
  return 0;
}