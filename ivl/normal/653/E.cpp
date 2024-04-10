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

void imp(){cout << "impossible\n"; exit(0);}

int gr[1<<20];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
void join(int a, int b){gr[un(a)] = un(b);}

int n, m, k;
vector < int > E[1<<20];
int pref[1<<20];

set < pii > S;

int main(){
  ios_base::sync_with_stdio(false);

  REP(i,1<<20) gr[i] = i;

  cin >> n >> m >> k;
  REP(i,m){
    int a, b;
    cin >> a >> b, --a, --b;
    E[a].pb(b);
    E[b].pb(a);
    S.insert({a, b});
    S.insert({b, a});
  }

  if (k+(int)E[0].size() >= n) imp();

  FOR(i,1,n){
    sort(E[i].begin(), E[i].end());
    int prev = 1;
    for (auto t : E[i]) if (t != 0){
      if (prev <= t-1){
	join(i, prev);
	++pref[prev];
	--pref[t-1];
      } prev = t+1;
    } if (prev <= n-1){
      join(i, n-1);
      ++pref[prev];
      --pref[n-1];
    }
  }

  FOR(i,1,1<<20) pref[i] += pref[i-1];
  FOR(i,1,n) if (pref[i]) join(i, i+1);

  vector < int > v;
  FOR(i,1,n) if (gr[i] == i) v.pb(i);
  //TRACE(v.size());
  if ((int)v.size() > k) imp();

  map < int, vector < int > > M;
  FOR(i,1,n) M[un(i)].pb(i);

  for (auto t : v){
    vector < int > &v2 = M[t];
    bool ch = false;
    for (auto x : v2) if (!S.count({0, x})) ch = true;
    if (!ch) imp();
  } cout << "possible\n";

  return 0;
}