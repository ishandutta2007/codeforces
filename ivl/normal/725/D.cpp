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
typedef pair < ll, ll > pll;

int n;
pll in[300005];

template < class T >
ostream& operator<<(ostream& out, multiset < T > s){
  out << "{";
  for (auto t : s) out << t << ", ";
  out << "}";
  return out;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> in[i].x >> in[i].y;
  pll curr = in[0];
  sort(in+1, in+n);
  reverse(in+1, in+n);

  multiset < ll > ahead;
  int pos = 1;
  int sol = 1e9;
  while (pos < n){
    // TRACE(in[pos].x _ in[pos].y);
    // TRACE(curr.x _ curr.y);
    if (in[pos].x > curr.x){ahead.insert(1+in[pos].y-in[pos].x); ++pos; continue;}
    // TRACE(ahead);
    sol = min(sol, (int)ahead.size());
    if (ahead.empty()) break;
    ll tmp = *ahead.begin();
    if (tmp > curr.x) break;
    ahead.erase(ahead.begin());
    curr.x -= tmp;
  }

  while (!ahead.empty() && *ahead.begin() <= curr.x)
    curr.x -= *ahead.begin(), ahead.erase(ahead.begin());
  sol = min(sol, (int)ahead.size());
  cout << sol+1 << endl;

  return 0;
}