#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  ll out = 0;
  int helpers = 0;
  REP(i,n){
    int x = min(helpers, a[i]/2);
    helpers -= x;
    a[i] -= x*2;
    out += x;
    out += a[i]/3;
    a[i] %= 3;
    helpers += a[i];
  }

  cout << out << endl;

  return 0;
}