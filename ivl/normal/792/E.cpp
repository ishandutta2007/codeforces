#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int n;
int a[505];

ll f(int c){ ++c;
  bool check = true;
  ll sum = 0;
  REP(i,n){
    int x = (a[i]+c-1)/c;
    int y = x*c-a[i];
    if (y > x) check = false;
    sum += x;
  }
  if (check) return sum;
  else return 1e18;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];

  // a = x*c - y, y <= x, r = x = (a+c-1)/c

  ll sol = 1e18;

  FOR(c,1,1e5)
    sol = min(sol, f(c));
  
  FOR(c,1,1e5){
    sol = min(sol, f(a[0]/c));
    if (a[0]%c == 0) sol = min(sol, f(a[0]/c-1));
  }

  cout << sol << endl;

  return 0;
}