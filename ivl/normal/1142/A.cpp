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
typedef pair<int, int> pii;

ll gcd(ll x, ll y){
  while (y) x %= y, swap(x, y);
  return abs(x);
}

int n, k;
int a, b;

ll x = +1e18, y = -1e18;

void check3(ll l){
  x = min(x, (ll)n*k / gcd((ll)n*k, l));
  y = max(y, (ll)n*k / gcd((ll)n*k, l));
}

void check2(ll lk){
  REP(ln,n) check3(lk + (ll)ln * k);
}

// s+l = b (mod k)
// l = b-s (mod k)
void check(int s){
  check2(+b-s);
  check2(-b-s);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  cin >> a >> b;

  check(+a);
  check(-a);

  cout << x << " " << y << endl;
  
  return 0;
}