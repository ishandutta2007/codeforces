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

const int offset = 1<<19;

int n;
int a[offset];

void seek(int val, int &loc){
  while (loc > 0 && a[loc-1] <= val) --loc;
}

ll T[offset*2];
ll P[offset*2];
void init(){
  vector<ll> pref(offset+1);
  REP(i,offset) pref[i+1] = pref[i] + a[i];
  auto sum = [&pref](int lo, int hi){return pref[hi+1] - pref[lo];};

  REP(k,offset) T[k+offset] = (ll)k * (k-1);
  REP(k,offset) T[k+offset] -= sum(1, k);

  int loc = offset-1;
  REP(k,offset){
    seek(k, loc);
    if (loc <= k){
      T[k+offset] += sum(k+1, offset-1);
    } else {
      T[k+offset] += sum(loc, offset-1) + (ll)k * (loc-k-1);
    }
  }
  
  for (int id = offset-1; id >= 1; --id)
    T[id] = min(T[id*2], T[id*2+1]);
}

void propagate(int id){
  if (!P[id]) return;
  for (auto t : {id*2, id*2+1})
    T[t] += P[id], P[t] += P[id];
  P[id] = 0;
}

void add(int id, int lo, int hi, int slo, int shi, int val){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){T[id] += val; P[id] += val; return;}
  propagate(id);
  int mid = (lo+hi)/2;
  add(id*2, lo, mid, slo, shi, val);
  add(id*2+1, mid+1, hi, slo, shi, val);
  T[id] = min(T[id*2], T[id*2+1]);
}

void increment(int pos){
  add(1, 0, offset-1, pos, offset-1, -1);
  add(1, 0, offset-1, a[pos]+1, pos-1, +1);
  ++a[pos];
}

ll query(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return 1e9;
  if (lo >= slo && hi <= shi) return T[id];
  propagate(id);
  int mid = (lo+hi)/2;
  return min(query(id*2, lo, mid, slo, shi),
	     query(id*2+1, mid+1, hi, slo, shi));
}

bool valid(){
  return query(1, 0, offset-1, 1, n+1) >= 0;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> a[i+1]; a[0] = 1e9;

  int parity = 0;
  REP(i,n) if (a[i+1]%2 == 1) parity = 1-parity;
  a[n+1] = parity;
  sort(a, a+n+2, greater<int>());
  init();

  vector<int> output;
  int loc = n+3;
  for (int curr = parity; curr <= n; curr += 2){
    if (valid()) output.pb(curr);

    seek(curr, loc);
    increment(loc);
    seek(curr+1, loc);
    increment(loc);
  }

  if (output.empty()) output.pb(-1);
  for (auto t : output) cout << t << " "; cout << endl;
  
  return 0;
}