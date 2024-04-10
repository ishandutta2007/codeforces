#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define x first
#define y second
#define pii pair < int, int >

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

ll x, y;

void f(ll n, ll b, ll p){
  if (n == 1) return;
  ll t = 1;
  while (t <= n) t <<= 1; t >>= 1;
  x += t/2 + b*t;
  y += p*t;
  f(n-t/2, b, p);
}

int main(){
  ll n, b, p;
  cin >> n >> b >> p;
  f(n, b, p);
  cout << x << " " << n*p << endl;
  return 0;
}