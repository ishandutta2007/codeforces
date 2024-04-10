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

void imp(){cout << "NO" << endl; exit(0);}

int n;
string a[1005];
string b[1005];

bool bio[1005];

string out[1005];

#define kill jebise
bool kill[1005][2];
bool proc[1005];

void solve(vector<int> v){
  if (v.size() > 26) imp();

  for (auto x : v)
    for (auto y : v)
      if (x != y)
	if (a[x].back() == a[y].back())
	  kill[x][0] = kill[y][0] = true;

  while (true){
    int id = -1;
    for (auto t : v) if (!proc[t]){
	if (kill[t][0] && kill[t][1]) imp();
	if (kill[t][0] || kill[t][1]){id = t; break;}
      }
    if (id == -1){
      for (auto t : v) if (!proc[t]) out[t] = a[t];
      break;
    }
    proc[id] = true;
    out[id] = kill[id][0] ? b[id] : a[id];
    for (auto t : v){
      if (a[t].back() == out[id].back()) kill[t][0] = true;
      if (b[t].back() == out[id].back()) kill[t][1] = true;
    }
  }

}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n){
    string x, y;
    cin >> x >> y;
    a[i] = x.substr(0, 3);
    b[i] = x.substr(0, 2) + y[0];
  }

  REP(i,n) if (!bio[i]){
    vector<int> v;
    REP(j,n)
      if (!bio[j] && a[i].substr(0, 2) == a[j].substr(0, 2))
	bio[j] = true, v.pb(j);
    solve(v);
  }

  cout << "YES" << endl;
  REP(i,n) cout << out[i] << endl;

  return 0;
}