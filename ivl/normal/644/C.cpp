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

int main(){
  ios_base::sync_with_stdio(false);

  map < string, set < string > > M;
  int n;
  cin >> n;
  REP(i,n){
    string s;
    cin >> s;
    int p = 7;
    while (p < (int)s.size() && s[p] != '/') ++p;
    M[string(s.begin(), s.begin()+p)].insert(string(s.begin()+p, s.end()));
  }

  map < set < string >, set < string > > M2;
  for (auto bla : M) M2[bla.y].insert(bla.x);
  set < set < string > > S;
  for (auto bla : M2) if (bla.y.size() > 1) S.insert(bla.y);
  cout << S.size() << endl;
  for (auto t : S){for (auto tt : t) cout << tt << " "; cout << endl;}

  return 0;
}