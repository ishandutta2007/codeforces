#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

string s;
int n;

bool valid(int id, int prl){
  if (id > n) return false;
  if (id == n) return true;
  static bool bio[10005][5];
  static bool memo[10005][5];
  bool &r = memo[id][prl];
  if (bio[id][prl]++) return r;

  for (int l : {2, 3}) if (string(s.begin()+id-prl, s.begin()+id) != string(s.begin()+id, s.begin()+id+l)) r |= valid(id+l, l);
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> s;
  set < string > S;
  n = (int)s.size();
  REP(i,100) s.pb('\0');

  REP(i,n-1){
    if (i <= 4) continue;
    if (n-i == 3) continue;
    if (!valid(i+2, 2)) continue;
    S.insert(string(s.begin()+i, s.begin()+i+2));
  }

  REP(i,n-2){
    if (i <= 4) continue;
    if (n-i == 4) continue;
    if (!valid(i+3, 3)) continue;
    S.insert(string(s.begin()+i, s.begin()+i+3));
  }

  cout << S.size() << endl;
  for (auto t : S) cout << t << endl;
  
  return 0;
}