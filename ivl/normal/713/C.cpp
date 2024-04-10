#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define left lazoleft
#define right lazoright

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int oo = 1e9;
const ll ool = (ll)oo * oo;

int n;
int a[3005];

ll left[3005][3005];
ll right[3005][3005];
ll dist[3005][3005];

ll dp(int pos){
  static ll memo[3005];
  static bool bio[3005];
  if (pos >= n-1) return 0;
  ll &r = memo[pos];
  if (bio[pos]++) return r;
  r = left[pos][n-1];
  FOR(x,pos+1,n) if (a[x] >= a[pos]+x-pos) r = min(r, dp(x)+dist[pos][x]);
  return r;
}

ostream& operator<<(ostream& out, vector < int > v){
  // for (auto t : v) out << t << " "; out << endl;
  return out;
}

int main(){

  cin >> n;
  REP(i,n) cin >> a[i+1];
  a[0] = -oo;
  ++n;

  REP(i,n) FOR(j,i+1,n) left[i][j] = left[i][j-1] + abs(a[i]+j-i-a[j]);
  REP(i,n) for (int j = i-1; j >= 0; --j) right[j][i] = right[j+1][i] + abs(a[i]+j-i-a[j]);

  // REP(i,n){REP(j,n) cout << left[i][j] << " "; cout << endl;} cout << endl;

  REP(i,n){
    vector < int > v(n, 0);
    FOR(j,i,n) if (a[j] <= a[i]+j-i) v[j] = -1; else v[j] = +1;
    cout << v;
    FOR(j,1,n) v[j] += v[j-1];
    cout << v;
    vector < int > opt(n, 0);
    FOR(j,1,n) if (v[j] < v[opt[j-1]]) opt[j] = j; else opt[j] = opt[j-1];
    cout << opt;
    FOR(j,i,n) dist[i][j] = left[i][opt[j]] + right[opt[j]+1][j];
    // REP(j,n) cout << dist[i][j] << " "; cout << endl << endl;
  }

  // REP(i,n){REP(j,n) cout << dist[i][j] << " "; cout << endl;} cout << endl;

  cout << dp(0) << endl;
  
  return 0;
}