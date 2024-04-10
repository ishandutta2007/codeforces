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

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector < int > v(n);
  REP(i,n) cin >> v[i];
  sort(v.begin(), v.end());
  cout << v[(n-1)/2] << endl;
  
  return 0;
}