#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void fin(ll t){
  cout << t << endl;
  exit(0);
}

int main(){

  ll s, x;
  cin >> s >> x;
  
  if (s%2 != x%2){cout << 0 << endl; return 0;}
  if (s < x){cout << 0 << endl; return 0;}
  
  ll alfa = (s-x)/2;
  if (alfa & x){cout << 0 << endl; return 0;}

  ll R2 = 1;
  for (; x; x /= 2)
    if (x & 1)
      R2 *= 2;

  if (!alfa) R2 -= 2;
  cout << R2 << endl;
  
  return 0;
}