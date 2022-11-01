#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

int gr[1<<20];
int un(int x){if (gr[x] == x) return x; return gr[x] = un(gr[x]);}
void join(int a, int b, int *d){
  a = un(a), b = un(b);
  if (d[a] < d[b]) swap(a, b);
  gr[a] = b;
}

int n, m;
vector < pii > E[1<<20];
int st, en;

int dep[1<<20];
int bio[1<<20];
void bcc(int id, int p){
  bio[id] = 1;
  for (auto t : E[id]) if (t.x != p){
      if (bio[un(t.x)] == 1){join(id, t.x, dep); continue;}
      assert(bio[un(t.x)] != 2);
      dep[t.x] = dep[id]+1;
      bcc(t.x, id);
      if (dep[un(t.x)] <= dep[id]) join(t.x, id, dep);
    }
  bio[id] = 2;
}

bool has[1<<20];
vector < pii > E2[1<<20];

pair < bool, bool > dfs(int id, int p){
  if (bio[id]++) return {false, false};
  if (id == un(en)) return {true, has[id]};
  for (auto t : E2[id]) if (t.x != p){
      auto x = dfs(t.x, id);
      if (x.x) return {true, x.y | t.y | has[id]};
    } return {false, false};
}

int main(){
  ios_base::sync_with_stdio(false);

  REP(i,1<<20) gr[i] = i;

  cin >> n >> m;
  REP(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    E[a].pb({b, c});
    E[b].pb({a, c});
  } cin >> st >> en;

  bcc(1, 1);
  memset(bio, 0, sizeof bio);
  
  FOR(i,1,n+1) for (auto t : E[i]){
    int a = un(i), b = un(t.x), c = t.y;
    if (a == b) has[a] |= c;
    else E2[a].pb({b, c});
  }

  REP(i,1<<20) sort(E2[i].begin(), E2[i].end(), [](pii x, pii y){return x.y > y.y;});

  auto R = dfs(un(st), un(st));
  if (R.y) cout << "YES\n";
  else cout << "NO\n";
  
  return 0;
}