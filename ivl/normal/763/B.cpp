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
pair<pii, pii> rect[500005];

int f(int x){
  x %= 2;
  if (x < 0) return 1;
  return x;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> rect[i].x.x >> rect[i].x.y >> rect[i].y.x >> rect[i].y.y;

  cout << "YES" << endl;
  REP(i,n) cout << 2 * f(rect[i].x.x) + f(rect[i].x.y) + 1 << endl;
  
  return 0;
}