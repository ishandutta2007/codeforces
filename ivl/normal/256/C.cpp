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
typedef pair < int, int > pii;

const int offset = 1<<20;

int n;
ll a[100005];

int merge(int x, int y, int l){
  if (l == 2){
    if (x) return 1+!!y;
    else return !!x;
  }
  if (x == l/2) return x+y;
  else return x;
}

int T[2*offset];
void add(int id, int lo, int hi, int p, int v){
  if (lo > p || hi < p) return;
  if (lo == hi){T[id] += v; return;}
  int mid = (lo+hi)/2;
  add(id*2, lo, mid, p, v);
  add(id*2+1, mid+1, hi, p, v);
  T[id] = merge(T[id*2], T[id*2+1], hi-lo+1);
}

int pret[1000005];

int f(ll x){
  static ll lo = 2, hi = 1;
  while ((hi+1)*(hi+1) <= x) ++hi, add(1, 0, offset-1, pret[hi], 1);
  while (lo*lo*lo*lo < x) add(1, 0, offset-1, pret[lo], -1), ++lo;
  return T[1];
}

int main(){
  ios_base::sync_with_stdio(false);

  pret[0] = pret[1] = pret[2] = pret[3] = 0;
  int lo = 2, hi = 1;
  FOR(i,4,1000000){
    while ((hi+1)*(hi+1) <= i) ++hi, add(1, 0, offset-1, pret[hi], 1);
    while (lo*lo*lo*lo < i) add(1, 0, offset-1, pret[lo], -1), ++lo;
    pret[i] = T[1];
  }

  memset(T, 0, sizeof T);

  cin >> n;
  ll r = 0;
  REP(i,n) cin >> a[i];
  sort(a, a+n);
  REP(i,n){
    ll x = a[i];
    if (x < 1000000) r ^= pret[x];
    else r ^= f(x);
  }
  
  if (r == 0) cout << "Rublo\n"; else cout << "Furlo\n";

  return 0;
}