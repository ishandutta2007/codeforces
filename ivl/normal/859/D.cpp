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

const int MAX = 1<<6;

int n;
int mat[MAX][MAX];

double memo2[MAX][MAX][MAX];
double win(int lo, int hi, int w){
  assert(lo <= w && w <= hi);
  if (lo == hi) return 1;
  double &r = memo2[lo][hi][w];
  if (r >= 0) return r;

  int mid = (lo+hi) / 2;
  if (w <= mid){
    double p = win(lo, mid, w);
    double q = 0;
    FOR(x,mid+1,hi+1) q += win(mid+1, hi, x) * mat[w][x] / 100.;
    r = p * q;
  } else {
    double p = win(mid+1, hi, w);
    double q = 0;
    FOR(x,lo,mid+1) q += win(lo, mid, x) * mat[w][x] / 100.;
    r = p * q;    
  }

  return r;
}

double memo[MAX][MAX];
double dp(int lo, int hi){
  if (lo == hi) return 0;
  assert(lo < hi);
  double &r = memo[lo][hi];
  if (r >= 0) return r;
  r = 0;

  FOR(w,lo,hi+1){
    double cr = 0;
    int a = lo, b = hi, m;
    while (a != b){
      cr += (b-a+1) * win(a, b, w) / 2.;
      m = (a+b)/2;
      if (w <= m){
	cr += dp(m+1, b);
	b = m;
      } else {
	cr += dp(a, m);
	a = m+1;
      }
    } r = max(r, cr);
  }

  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,1<<n) REP(j,1<<n) cin >> mat[i][j];

  REP(i,1<<n) REP(j,1<<n) memo[i][j] = -1;
  REP(i,1<<n) REP(j,1<<n) REP(k,1<<n) memo2[i][j][k] = -1;

  cout << setprecision(20) << fixed << dp(0, (1<<n)-1) << endl;
  
  return 0;
}