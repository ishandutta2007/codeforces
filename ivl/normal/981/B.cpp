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
int a[100005];
int x[100005];

int m;
int b[100005];
int y[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i] >> x[i];

  cin >> m;
  REP(i,m) cin >> b[i] >> y[i];

  map<int, int> M;
  REP(i,n) M[a[i]] = max(M[a[i]], x[i]);
  REP(i,m) M[b[i]] = max(M[b[i]], y[i]);

  ll sol = 0;
  for (auto t : M)
    sol += t.y;

  cout << sol << endl;

  return 0;
}