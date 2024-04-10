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

void imp(){cout << -1 << endl; exit(0);}

int n;
ll a[100005];

int pcnt[50];
int lim[50];

int value(){
  vector<int> A(50), tmp(pcnt, pcnt+50);
  int sol = 0;
  for (int i = 48; i >= 0; --i){
    int mini = 1e9;
    REP(j,i+1) mini = min(mini, tmp[j]);
    A[i+1] = mini;
    sol += mini;
    REP(j,i+1) tmp[j] -= mini;
  }

  REP(i,50) tmp[i] += lim[i];

  // REP(i,5) cout << tmp[i] << " "; cout << endl;

  REP(i,50){
    int bla = tmp[i];
    int j = i;
    while (j < 50 && bla){
      if (bla <= A[j]){A[j] -= bla; bla = 0; break;}
      bla -= A[j]; A[j] = 0;
      ++j;
    }
    if (bla) return -1;
  } return sol;
}

int lowvalue(){
  vector<int> A(50), tmp(pcnt, pcnt+50), rest(pcnt, pcnt+50), rest2(lim, lim+50);
  for (int i = 48; i >= 0; --i){
    int mini = 1e9;
    REP(j,i+1) mini = min(mini, tmp[j]);
    A[i+1] = mini;
    REP(j,i+1) tmp[j] -= mini;
  }

  // int sol = 0;
  REP(i,50){
    // TRACE(i _ A[i]);
    int lo = 0, hi = A[i], mid;
    while (lo != hi){
      mid = (lo+hi+1)/2;
      REP(j,i) pcnt[j] -= mid, lim[j] += mid;
      if (value() != -1) lo = mid;
      else hi = mid-1;
      REP(j,i) pcnt[j] += mid, lim[j] -= mid;
    }
    // TRACE(lo);
    // sol += lo;
    REP(j,i) pcnt[j] -= lo, lim[j] += lo;
    if (lo != A[i]) break;
  }

  int sol = value();
  assert(sol != -1);
  REP(i,50) pcnt[i] = rest[i];
  REP(i,50) lim[i] = rest2[i];

  // TRACE(sol);

  return sol;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  // const int A = 10;
  // n = 1e5;
  // REP(i,A) REP(j,n/A) a[i*n/A+j] = (1LL << i);

  REP(i,n)
    if (a[i] & (a[i]-1)){
      int k = 0;
      while (a[i] > (1LL << k)) ++k;
      ++lim[k];
    } else {
      int cnt = 0;
      ll tmp = a[i];
      while (tmp != 1) ++cnt, tmp /= 2;
      ++pcnt[cnt];
    }

  if (value() == -1){cout << -1 << endl; return 0;}

  int lo = lowvalue();

  // TRACE(lo);

  int hi = value(); /*{

    for (int i = 45; i >= 0; --i){
      int blo = 0, bhi = pcnt[i]/2, mid;
      while (blo != bhi){
	mid = (blo+bhi+1)/2;
	REP(j,i) pcnt[j] -= mid;
	pcnt[i] -= 2*mid;
	if (value() != -1) blo = mid;
	else bhi = mid-1;
	REP(j,i) pcnt[j] += mid;
	pcnt[i] += 2*mid;
      }

      TRACE(i _ blo);

      hi += blo;

      REP(j,i) pcnt[j] -= blo;
      pcnt[i] -= 2*blo;

      // TRACE(i _ blo);
    }

    // TRACE(value());

    hi += value();
    }*/

  // TRACE(lo _ hi);

  FOR(i,lo,hi+1) cout << i << " "; cout << endl;

  return 0;
}