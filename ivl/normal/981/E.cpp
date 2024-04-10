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

int n, q;
int l[10005];
int r[10005];
int x[10005];

int num[10005];
bool good[10005];

const int offset = 1<<14;
vector<int> T[offset*2];

void add(int id, int lo, int hi, int slo, int shi, int val){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){T[id].pb(val); return;}
  int mid = (lo+hi)/2;
  add(id*2, lo, mid, slo, shi, val);
  add(id*2+1, mid+1, hi, slo, shi, val);
}

void rec(int id, int lo, int hi){
  for (auto val : T[id])
    for (int i = n-val; i >= 0; --i)
      if (num[i])
	++num[i+val], good[i+val] = true;
  if (lo != hi){
    int mid = (lo+hi)/2;
    rec(id*2, lo, mid);
    rec(id*2+1, mid+1, hi);
  }
  reverse(T[id].begin(), T[id].end());
  for (auto val : T[id])
    for (int i = 0; i <= n-val; ++i)
      if (num[i])
	--num[i+val];
}

int main(){
  ios_base::sync_with_stdio(false);
  num[0] = 1;

  cin >> n >> q;
  REP(i,q) cin >> l[i] >> r[i] >> x[i];
  REP(i,q) add(1, 0, offset-1, l[i], r[i], x[i]);
  rec(1, 0, offset-1);

  int cnt = 0;
  REP(i,n+1) cnt += good[i];
  cout << cnt << endl;
  REP(i,n+1) if (good[i]) cout << i << " ";
  cout << endl;

  return 0;
}