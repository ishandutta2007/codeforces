#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int oo = 1e9;
const ll ool = (ll)oo * oo;

ll n, x, y;

ll dp(int c);
ll dp2(int c);

ll dp2(int c){
  static ll memo[10000005];
  static bool bio[10000005];

  if (c < 0) return ool;
  if (c > n+1) return ool;
  if (c == n) return 0;
  ll &r = memo[c];
  if (bio[c]++) return r;
  return r = y+dp(2*c);
}

ll dp(int c){
  static ll memo[10000005];
  static bool bio[10000005];

  if (c < 0) return ool;
  if (c > n+1) return ool;
  if (c == n) return 0;
  ll &r = memo[c];
  if (bio[c]++) return r;
  r = ool;

  if (c == 0){
    FOR(i,1,n+1) r = min(r, x*i + dp2(i));
    return r;
  }

  r = min(r, dp2(c));
  r = min(r, x+dp2(c+1));
  if (c > 2) r = min(r, x+dp2(c-1));
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> x >> y;
  cout << dp(0) << endl;
    
  return 0;
}