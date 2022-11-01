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

int gr[10005];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
void join(int x, int y){
  gr[un(x)] = un(y);
}

int main(){
  ios_base::sync_with_stdio(false);

  REP(i,10005) gr[i] = i;

  int n;
  cin >> n;
  FOR(i,1,n+1){int x; cin >> x; join(i, x);}
  int sol = 0;
  FOR(i,1,n+1) if (gr[i] == i) ++sol;
  cout << sol << endl;
  
  return 0;
}