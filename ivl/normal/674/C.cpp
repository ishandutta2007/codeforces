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
typedef pair < int, int > pii;
#define double long double

const double eps = 1e-11;

int t[200005];

double pr1[200005], pr2[200005];
double om[200005];

double omega(int lo, int hi){
  return om[hi] - om[lo] - pr1[lo] * (pr2[hi] - pr2[lo]);
}

double calc[55][200005];
void dp(int k, int lo, int hi, int slo, int shi){
  if (lo > hi) return;
  int mid = (lo+hi)/2;
  int opt = -1;
  double best = 1e20;
  FOR(i,max(slo,0),min(mid,shi+1)){
    double cb = calc[k-1][i] + omega(i, mid);
    if (cb+eps < best) best = cb, opt = i;
  } calc[k][mid] = best;
  //TRACE(k _ mid _ opt _ best);
  //TRACE(lo _ hi _ slo _ shi);
  dp(k, lo, mid-1, slo, opt);
  dp(k, mid+1, hi, opt, shi);
}

int main(){
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  REP(i,n) cin >> t[i];
  REP(i,n) pr1[i+1] = t[i], pr2[i+1] = 1./t[i];
  REP(i,n+2) pr1[i+1] += pr1[i], pr2[i+1] += pr2[i];
  REP(i,n) om[i+1] = om[i] + pr1[i+1] / t[i];
  REP(i,n+1) calc[0][i] = 1e20;
  calc[0][0] = 0;

  FOR(T,1,k+1) dp(T, 0, n, 0, n);
  cout << setprecision(30) << calc[k][n] << endl;
  
  return 0;
}