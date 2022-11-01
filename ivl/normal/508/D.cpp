#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define real realreal

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

void no(){cout << "NO\n"; exit(0);}

int n;
vector < string > in;

set < string > V;
map < string, vector < string > > E;
map < string, vector < string > > Einv;
void add(string a, string b){V.insert(a); V.insert(b); E[a].pb(b); Einv[b].pb(a);}

vector < string > sol;
map < string, int > poin;
void dfs(string id){
  while (poin[id] < (int)E[id].size()){
    string tmp = E[id][poin[id]++];
    dfs(tmp);
    sol.pb(tmp);
  }
}

int main(){

  // E["a"] = {"b"};
  // E["b"] = {"c"};
  // E["c"] = {"a", "d"};
  // E["d"] = {"e"};
  // E["e"] = {"c"};
  // dfs("a"); reverse(sol.begin(), sol.end());
  // for (auto t : sol) cout << t << " "; cout << endl; exit(0);

  cin >> n; in.resize(n);
  REP(i,n) cin >> in[i];
  for (auto s : in) add(s.substr(0, 2), s.substr(1, 2));

  int cnt = 0;
  bool valid = true;
  string id = "";
  for (auto s : V){
    if (E[s].size() > Einv[s].size()) id = s;
    if (E[s].size() == Einv[s].size()) continue;
    if (abs((int)E[s].size()-(int)Einv[s].size()) > 1) valid = false;
    if (abs((int)E[s].size()-(int)Einv[s].size()) == 1) ++cnt;
  } TRACE(cnt _ valid);
  if (cnt > 2 || !valid) no();
  if (id == "") id = *V.begin();
  dfs(id); sol.pb(id);
  if ((int)sol.size() != n+1) no();
  reverse(sol.begin(), sol.end());
  cout << "YES\n";
  for (auto s : sol) cout << s[0]; cout << sol.back().back() << endl;
  
  return 0;
}