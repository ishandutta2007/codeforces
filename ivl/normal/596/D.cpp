#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define x first
#define y second
#define ll long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, h;
double p;
int x[2005];

#define left left2
#define right right2
int left[2005];
int right[2005];

int notinside(int a, int b, int c, int d){
  a = max(a, c);
  b = min(b, d);
  if (a > b) return 0;
  return b-a;
}

double dp(int lo, bool b1, int hi, bool b2){
  static double memo[2005][2][2005][2];
  static bool bio[2005][2][2005][2];
  if (lo > hi) return 0;
  double &r = memo[lo][b1][hi][b2];
  if (bio[lo][b1][hi][b2]++) return r;
  r = 0;

  int xlo = (b1 ? x[lo-1]+h : (lo !=   0 ? x[lo-1] : -1000000000));
  int xhi = (b2 ? x[hi+1]-h : (hi != n-1 ? x[hi+1] : +1000000000));
  int a, b;

  a = x[lo]-h, b = x[lo];
  r += (dp(lo+1, false, hi, b2) + notinside(a,b,xlo,xhi)) * p;

  a = x[lo], b = x[right[lo]]+h;
  r += (dp(right[lo]+1, true, hi, b2) + notinside(a,b,xlo,xhi)) * (1-p);

  a = x[hi], b = x[hi]+h;
  r += (dp(lo, b1, hi-1, false) + notinside(a,b,xlo,xhi)) * (1-p);

  a = x[left[hi]]-h, b = x[hi];
  r += (dp(lo, b1, left[hi]-1, true) + notinside(a,b,xlo,xhi)) * p;
  
  r /= 2;
  return r;
}

int main(){
  cin >> n >> h >> p;
  REP(i,n) cin >> x[i];
  sort(x,x+n);

  left[0] = 0;
  FOR(i,1,n){
    if (x[i]-x[i-1] < h) left[i] = left[i-1];
    else left[i] = i;
  }

  right[n-1] = n-1;
  for (int i = n-2; i >= 0; --i){
    if (x[i+1]-x[i] < h) right[i] = right[i+1];
    else right[i] = i;
  }

  //REP(i,n) TRACE(i _ x[i] _ left[i] _ right[i]);
  
  printf("%.15lf\n", dp(0, false, n-1, false));
  return 0;
}