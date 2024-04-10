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

int n, l;
int _a[600015], *a = _a + 200005;
int _b[600015], *b = _b + 200005;

bool check(int limit){
  vector<pii> all;
  int lo = -n, hi = -n;
  REP(i,n){
    while (a[i] - b[lo] >   limit) ++lo;
    while (a[i] - b[hi] >= -limit) ++hi;
    all.pb({lo, hi-1});
  }

  REP(i,n) all.pb({all[i].x + n, all[i].y + n});
  
  //      b.hi - a.lo + 1 >= b - a + 1
  // <=>  b.hi - b >= a.lo - a
  REP(i,2*n) all[i].x -= i, all[i].y -= i;
  int prev = -1e9;
  REP(i,2*n){
    prev = max(prev, all[i].x);
    if (prev > all[i].y) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> l;
  for (auto p : {a, b}){
    REP(i,n){
      cin >> p[i];
      p[i-n] = p[i] - l;
      p[i+n] = p[i] + l;
    }
    sort(p-n, p+2*n);
    p[2*n] = 2*l+5;
  }

  int lo = 0, hi = l, mid;
  while (lo != hi){
    mid = (lo+hi)/2;
    if (check(mid)) hi = mid;
    else lo = mid+1;
  }

  cout << lo << endl;

  return 0;
}