#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main(){
  ios_base::sync_with_stdio(false);

  int lo = -1e9, hi = +1e9;
  int n; cin >> n;
  int tmp = 0;
  REP(ttt,n){
    int del; cin >> del;
    int div; cin >> div;
    if (div == 1) lo = max(lo, 1900-tmp);
    else hi = min(hi, 1899-tmp);
    tmp += del;
  }

  if (hi < lo){cout << "Impossible" << endl; return 0;}
  if (hi > 1e8){cout << "Infinity" << endl; return 0;}
  cout << hi+tmp << endl;

  return 0;
}