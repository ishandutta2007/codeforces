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
typedef pair<ll, ll> pll;

int n;
int a[300005];

int pref[300005];
int sum(int lo, int hi){
  if (hi < lo) return 0;
  return pref[hi+1] - pref[lo];
}

int gsol = 1e9;

// O(1)
void attempt(int a, int b, int c){
  int x = sum(0, a);
  int y = sum(a+1, b);
  int z = sum(b+1, c);
  int w = sum(c+1, n-1);
  int sol = x+z;
  x /= 10, z /= 10;
  if (x >= y) x -= y, y = 0;
  else sol += y-x, x = y = 0;
  z += x;
  if (z < w) sol += w-z;
  gsol = min(gsol, sol);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];

  pref[0] = 0;
  REP(i,n) pref[i+1] = pref[i] + a[i];

  gsol = sum(0, n-1);

  REP(i,n) attempt(i, n-1, n-1);

  REP(i,n)
    if (a[i] == 1000){
      for (int j = i+1; j < n && a[j] == 2000; ++j)
	attempt(i-1, i, j);
      for (int j = i-1; j >= 0 && a[j] == 2000; --j)
	attempt(j-1, i-1, i);
    }
  
  cout << gsol << endl;
  
  return 0;
}