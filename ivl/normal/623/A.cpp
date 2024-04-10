#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int n, m;
vector < int > E[505];

vector < int > dva;
bool done[505];

char out[505];

bool mat[505][505];

bool f(vector < int > v){
  REP(i,v.size()) REP(j,i) if (!mat[v[i]][v[j]]) return false;
  return true;
}

int main(){
  cin >> n >> m;
  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a, --b;
    mat[a][b] = mat[b][a] = true;
    E[a].pb(b);
    E[b].pb(a);
  }

  REP(i,n) if ((int)E[i].size() == n-1) dva.pb(i), done[i] = true, out[i] = 'b';
  REP(i,n){
    vector < int > v;
    for (auto t : E[i]) if (!done[t]) v.pb(t);
    E[i] = v;
  }
  int cnt = 0;
  REP(i,n) cnt += !done[i];
  vector < int > all;
  REP(i,n) if (!done[i]) all.pb(i);

  // dva klika

  if (cnt == 0){
    cout << "Yes\n";
    REP(i,n) cout << out[i]; cout << endl;
    return 0;
  }

  vector < int > a, c;
  a = E[all[0]];
  a.pb(all[0]);

  for (auto t : a) done[t] = true;
  REP(i,n) if (!done[i]) c.pb(i);

  for (auto x : a) for (auto y : c) if (mat[x][y]){cout << "No\n"; return 0;}

  if (f(a) && f(c)){
    cout << "Yes\n";
    for (auto x : a) out[x] = 'a';
    for (auto x : c) out[x] = 'c';
    REP(i,n) cout << out[i]; cout << endl;
    return 0;
  } else cout << "No\n";
  
  return 0;
}