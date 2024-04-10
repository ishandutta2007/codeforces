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

int n;
int x[1005];
int y[1005];
int a[1005];
int b[1005];

void attempt(int tx, int ty){
  multiset<pii> ms1, ms2;
  REP(i,n) ms1.insert({a[i], b[i]});
  REP(i,n) ms2.insert({tx-x[i], ty-y[i]});
  if (ms1 != ms2) return;
  cout << tx << " " << ty << endl;
  exit(0);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> x[i] >> y[i];
  REP(i,n) cin >> a[i] >> b[i];

  REP(i,n) attempt(x[0] + a[i], y[0] + b[i]);
  assert(false);
  return 0;
}