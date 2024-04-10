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
  vector<ll> s(n);
  REP(i,n) cin >> s[i];
  sort(s.begin(), s.end());

  vector<pii> sweep;
  REP(i,n-1) sweep.pb({s[i+1]-s[i], 0});

  int q;
  cin >> q;
  REP(i,q){
    ll l, r;
    cin >> l >> r;
    sweep.pb({r-l, i+1});
  }

  sort(sweep.begin(), sweep.end());
  vector<ll> outs(q);

  ll current = n;
  ll delta = n;
  ll ptr = 0;
  for (auto t : sweep){
    current += delta * (t.x - ptr);
    ptr = t.x;

    if (t.y == 0){--delta; --current; continue;}
    int id = t.y - 1;
    outs[id] = current;
  }

  REP(i,q) cout << outs[i] << " ";
  cout << endl;

  return 0;
}