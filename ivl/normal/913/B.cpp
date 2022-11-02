#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int p[1005];

vector<int> E[1005];

bool leaf(int x){return E[x].empty();}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  FOR(i,2,n+1) cin >> p[i];

  FOR(i,2,n+1) E[p[i]].pb(i);

  bool check = true;
  FOR(i,1,n+1)
    if (!leaf(i)){
      int cnt = 0;
      for (auto t : E[i])
	if (leaf(t))
	  ++cnt;
      if (cnt < 3) check = false;
    }

  if (check) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}