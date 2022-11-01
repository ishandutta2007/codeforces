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

int n, m;
vector<int> E[300005];
vector<int> s[300005];
int clr[300005];

void rek(int id, int p){
  set<int> all;
  vector<int> rem;
  for (auto t : s[id])
    if (clr[t] != 0) all.insert(clr[t]);
    else rem.pb(t);
  int poin = 1;
  for (auto t : rem){
    while (all.count(poin)) ++poin;
    clr[t] = poin;
    ++poin;
  }
  for (auto t : E[id])
    if (t != p)
      rek(t, id);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  FOR(i,1,n+1){
    int x;
    cin >> x;
    s[i].resize(x);
    REP(j,x) cin >> s[i][j];
  }
  REP(i,n-1){int u, v; cin >> u >> v; E[u].pb(v); E[v].pb(u);}

  int id = 1;
  FOR(i,1,n+1) if (s[i].size() > s[id].size()) id = i;
  cout << (s[id].size() ? s[id].size() : 1) << endl;

  rek(id, id);
  FOR(i,1,m+1) cout << (clr[i] ? clr[i] : 1) << " "; cout << endl;

  return 0;
}