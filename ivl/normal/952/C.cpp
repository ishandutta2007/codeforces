#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " = " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void no(){cout << "NO" << endl; exit(0);}

int main(){

  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &t : v) cin >> t;
  while (!v.empty()){
    REP(i,v.size()-1) if (abs(v[i] - v[i+1]) >= 2) no();
    int id = 0;
    REP(i,v.size()) if (v[i] > v[id]) id = i;
    v.erase(v.begin() + id);
  }

  cout << "YES" << endl;

  return 0;
}