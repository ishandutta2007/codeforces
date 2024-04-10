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

ll d, k, a, b, t;

ll f(ll D){
  if (D == 0) return 0;
  return a*D + t*((D-1)/k);
}

ll g(ll D){if (D > d) D = d; return f(D) + (d-D)*b;}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> d >> k >> a >> b >> t;
  cout << min(min(g(0), g(d)), min(g(k), g(d/k*k))) << endl;

  return 0;
}