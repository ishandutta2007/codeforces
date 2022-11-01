#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair < int, int > pii;
typedef long long ll;

int n;
ll a[200005];
vector < pair < int, ll > > ch[200005];

ll dist[200005];
pii seg[200005];
int cnt = 0;
void InitDfs(int id){
  seg[id].x = cnt++;
  for (auto t : ch[id])
    dist[t.x] = dist[id] + t.y, InitDfs(t.x);
  seg[id].y = cnt-1;
}

const int offset = 1<<18;
vector < ll > T[offset*2];
ll Ta[offset*2];

void init(int id, int lo, int hi){
  if (lo == hi){
    T[id] = {Ta[lo]};
    return;
  }
  int mid = (lo+hi)/2;
  init(id*2, lo, mid);
  init(id*2+1, mid+1, hi);
  for (auto t : T[id*2]) T[id].pb(t);
  for (auto t : T[id*2+1]) T[id].pb(t);
  sort(T[id].begin(), T[id].end());
}

int query(int id, int lo, int hi, int slo, int shi, ll val){
  if (lo > shi || hi < slo) return 0;
  if (lo >= slo && hi <= shi){
    return (int)(upper_bound(T[id].begin(), T[id].end(), val) - T[id].begin());
  }
  int mid = (lo+hi)/2;
  return query(id*2, lo, mid, slo, shi, val)
    +query(id*2+1, mid+1, hi, slo, shi, val);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i];
  REP(i,n-1){int p, w; cin >> p >> w, --p; ch[p].pb({i+1, w});}

  InitDfs(0);

  REP(i,n) a[i] = dist[i] - a[i];
  REP(i,n) Ta[seg[i].x] = a[i];
  init(1, 0, offset-1);

  REP(i,n) cout << query(1, 0, offset-1, seg[i].x+1, seg[i].y, dist[i]) << " "; cout << endl;

  return 0;
}