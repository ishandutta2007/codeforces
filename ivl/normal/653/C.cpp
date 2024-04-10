#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n;
int t[1<<20];

bool good(int id){
  if (id < 0 || id >= n) return true;
  if (id%2 == 0){
    if (id == 0) return t[id]<t[id+1];
    if (id == n-1) return t[id]<t[id-1];
    return t[id]<t[id+1] && t[id]<t[id-1];
  } else {
    if (id == 0) return t[id]>t[id+1];
    if (id == n-1) return t[id]>t[id-1];
    return t[id]>t[id+1] && t[id]>t[id-1];
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> t[i];

  vector < int > pot;
  REP(i,n) if (!good(i)) pot.pb(i);
  if (pot.size() >= 10){cout << 0 << endl; return 0;}

  set < pii > r;

  for (auto x : pot) REP(i,n) if (i != x){
      bool ch = true;
      swap(t[x], t[i]);
      for (auto y : pot) if (!good(y)) ch = false;
      for (auto y : {i, i-1, i+1}) if (!good(y)) ch = false;
      for (auto y : {x, x-1, x+1}) if (!good(y)) ch = false;
      swap(t[i], t[x]);
      if (ch) r.insert({min(i,x), max(i,x)});
    } cout << r.size() << endl;

  return 0;
}