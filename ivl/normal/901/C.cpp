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

const int MAX = 3e5+5;

int n, m;
vector<int> E[MAX];

int dep[MAX];
vector<int> st;
vector<pii> intervals;

void dfs(int id, int p){
  st.pb(id);
  dep[id] = dep[p]+1;
  for (auto t : E[id])
    if (t != p){
      if (dep[t]){
	if (dep[t] > dep[id]) continue;
	int lo = t, hi = t;
	for (int i = (int)st.size()-1; st[i] != t; --i)
	  lo = min(lo, st[i]), hi = max(hi, st[i]);
	intervals.pb({lo, hi});
      } else dfs(t, id);
    }
  st.pop_back();
}

int limit[MAX];
int back[MAX];

const int offset = 1<<19;
ll T[offset*2];
ll P[offset*2];

void propagiraj(int id, int lo, int hi){
  for (auto t : {id*2, id*2+1})
    P[t] += P[id], T[t] += P[id] * (hi-lo+1) / 2;
  P[id] = 0;
}

void inc(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){++P[id]; T[id] += hi-lo+1; return;}
  propagiraj(id, lo, hi);
  int mid = (lo+hi)/2;
  inc(id*2, lo, mid, slo, shi);
  inc(id*2+1, mid+1, hi, slo, shi);
  T[id] = T[id*2] + T[id*2+1];
}

ll sum(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return 0;
  if (lo >= slo && hi <= shi) return T[id];
  propagiraj(id, lo, hi);
  int mid = (lo+hi)/2;
  return sum(id*2, lo, mid, slo, shi) + sum(id*2+1, mid+1, hi, slo, shi);
}

ll output[MAX];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,m){int a, b; cin >> a >> b; E[a].pb(b); E[b].pb(a);}

  FOR(i,1,n+1) if (!dep[i]) dfs(i, i);

  memset(limit, 0, sizeof limit);
  for (auto t : intervals)
    limit[t.y] = max(limit[t.y], t.x);

  FOR(i,1,n+1) back[i] = max(back[i-1], limit[i]+1);

  vector<pair<pii, int>> queries;
  int q;
  cin >> q;
  REP(i,q){
    int a, b;
    cin >> a >> b;
    queries.pb({{a, b}, i});
  }

  sort(queries.begin(), queries.end(), [](pair<pii, int> a, pair<pii, int> b){
      return a.x.y < b.x.y;
    });

  int next = 1;
  for (auto query : queries){
    int x = query.x.x, y = query.x.y, id = query.y;
    for (; next <= y; ++next)
      inc(1, 0, offset-1, back[next], next);
    output[id] = sum(1, 0, offset-1, x, y);
  }

  REP(i,q) cout << output[i] << endl;
  
  return 0;
}