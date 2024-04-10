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
int a[55];
int suff[55];

int dp(int pos){
  if (pos == n) return 0;
  static map<int, int> memo;
  if (memo.count(pos)) return memo[pos];
  else return memo[pos] = max(dp(pos+1), suff[pos]-dp(pos+1));
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  suff[n] = 0;
  for (int i = n-1; i >= 0; --i)
    suff[i] = a[i] + suff[i+1];

  cout << suff[0]-dp(0) << " " << dp(0) << endl;
  
  return 0;
}