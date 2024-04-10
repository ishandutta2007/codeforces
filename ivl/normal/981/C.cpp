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

int n;
vector<int> E[100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n-1){int a, b; cin >> a >> b; E[a].pb(b); E[b].pb(a);}

  map<int, int> M;
  FOR(i,1,n+1) ++M[(int)E[i].size()];

  if (M[1] + M[2] <= n-2){cout << "No" << endl; return 0;}
  cout << "Yes" << endl;

  if (M[1] == 2){
    cout << 1 << endl;
    int a = -1, b = -1;
    FOR(i,1,n+1) if (E[i].size() == 1) a = b, b = i;
    cout << a << " " << b << endl;
  } else {
    cout << M[1] << endl;
    int id = -1;
    FOR(i,1,n+1) if (E[i].size() > 2) id = i;
    FOR(i,1,n+1) if (E[i].size() == 1) cout << id << " " << i << endl;
  }

  return 0;
}