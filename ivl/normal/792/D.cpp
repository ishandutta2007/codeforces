#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll n;
int q;

ll f(ll x, char c){
  assert(1 <= x && x <= n);
  ll sz = 0;
  while (((x>>sz)&1) == 0) ++sz;
  sz = (1LL<<sz);
  if (c == 'L') return x-sz/2;
  if (c == 'R') return x+sz/2;
  if (c == 'U') return x*2-1 == n ? x : ((x|(2*sz))&~sz);
  assert(false);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> q;
  REP(i,q){
    ll v;
    string s;
    cin >> v >> s;
    for (auto t : s)
      v = f(v, t);
    cout << v << "\n";
  }

  return 0;
}