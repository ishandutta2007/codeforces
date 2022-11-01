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

int n, k;
pii lohi[50005][11];

int gr[50005];
int sz[50005];
int un(int x){if (x == gr[x]) return x; return gr[x] = un(gr[x]);}
int join(int x, int y){
  x = un(x), y = un(y);
  assert(x != y);
  if (rand()%2) swap(x, y);
  REP(i,k){
    lohi[x][i].x = min(lohi[x][i].x, lohi[y][i].x);
    lohi[x][i].y = max(lohi[x][i].y, lohi[y][i].y);
  }
  gr[y] = x;
  sz[x] += sz[y];
  return x;
}

set<pii> S[11];

bool Equivalent(int a, int b){
  bool l = false, r = false;
  REP(i,k){
    if (lohi[a][i].x <= lohi[b][i].y) l = true;
    if (lohi[a][i].y >= lohi[b][i].x) r = true;
  } return l && r;
}

void Erase(int id){
  REP(i,k) S[i].erase({lohi[id][i].y, id});
}

void Insert(int id){
  REP(i,k) S[i].insert({lohi[id][i].y, id});
}

void Update(int id){
  bool repeat = true;
  while (repeat){
    repeat = false;
    REP(i,k){
      auto it = S[i].lower_bound({lohi[id][i].x, -1});
      if (it == S[i].end()) continue;
      if (it->y == id) ++it;
      if (it == S[i].end()) continue;
      int id2 = it->y;
      if (Equivalent(id, id2)){
	Erase(id);
	Erase(id2);
	id = join(id, id2);
	Insert(id);
	repeat = true;
	break;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  int opt = 0;
  REP(i,n){
    gr[i] = i;
    sz[i] = 1;
    REP(j,k){
      cin >> lohi[i][j].x;
      lohi[i][j].y = lohi[i][j].x;
    }
    Insert(i);
    Update(i);
    int nopt = un(i);
    opt = un(opt);
    if (lohi[nopt][0].y > lohi[opt][0].x) opt = nopt;
    cout << sz[opt] << endl;
  }

  return 0;
}