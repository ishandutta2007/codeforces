#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define next nextmrs
#define prev prevmrs

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int offset = 1<<18;

int n, m, q;
int p[200005];
int a[200005];

int follower[200005];
int next[200005];
int lca[20][200005];
int tvals[offset];
int T[2*offset];

int eval(int pos, int dist){
  REP(i,20)
    if (dist >> i & 1)
      pos = ((pos == -1) ? -1 : lca[i][pos]);
  return pos;
}

void init(int id, int lo, int hi){
  if (lo == hi){T[id] = tvals[lo]; return;}
  int mid = (lo+hi)/2;
  init(id*2, lo, mid);
  init(id*2+1, mid+1, hi);
  T[id] = min(T[2*id], T[2*id+1]);
}

int query(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return 1e9;
  if (lo >= slo && hi <= shi) return T[id];
  int mid = (lo+hi)/2;
  return min(query(id*2, lo, mid, slo, shi),
	     query(id*2+1, mid+1, hi, slo, shi));
}

int tmp[200005];
int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> q;
  REP(i,n) cin >> p[i], --p[i];
  REP(i,m) cin >> a[i], --a[i];

  REP(i,n) follower[p[i]] = p[(i+1)%n];
  memset(tmp, -1, sizeof tmp);
  for (int i = m-1; i >= 0; --i){
    next[i] = tmp[follower[a[i]]];
    tmp[a[i]] = i;
  }

  REP(i,m) lca[0][i] = next[i];
  REP(j,20-1) REP(i,m) lca[j+1][i] = ((lca[j][i] == -1) ? -1 : lca[j][lca[j][i]]);

  REP(i,m){
    int bla = eval(i, n-1);
    if (bla == -1) bla = 1e9;
    tvals[i] = bla;
  }
  init(1, 0, offset-1);
  
  REP(i,q){
    int l, r;
    cin >> l >> r;
    --l, --r;
    int qval = query(1, 0, offset-1, l, r);
    if (qval > r) cout << 0; else cout << 1;
  } cout << endl;
  
  return 0;
}