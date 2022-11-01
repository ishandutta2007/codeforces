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

typedef set<pii> Magic;

bool intersect(pii a, pii b){return a.x <= b.y && b.x <= a.y;}

auto relevant(pii a, const Magic &m){
  auto it = m.lower_bound(a);
  while (it != m.begin()){
    --it;
    if (!intersect(a, *it)) break;
  }
  if (it != m.begin()) --it;
  return make_pair(it, m.upper_bound({a.y+5, 0}));
}

void join(pii a, Magic &m){
  auto tmp = relevant(a, m);
  vector<pii> del;
  for (auto it = tmp.x; it != tmp.y; ++it)
    if (intersect(a, {it->x-1, it->y+1})){
      a.x = min(a.x, it->x);
      a.y = max(a.y, it->y);
      del.pb(*it);
    }
  for (auto b : del) m.erase(b);
  m.insert(a);
}

Magic intersection(pii a, const Magic &m){
  Magic output;
  auto tmp = relevant(a, m);
  for (auto it = tmp.x; it != tmp.y; ++it)
    if (intersect(a, *it))
      output.insert({max(a.x, it->x), min(a.y, it->y)});
  return output;
}

bool valid(pii a){return a.x <= a.y;}

Magic difference(pii a, const Magic &m){
  Magic output;
  auto tmp = relevant(a, m);
  for (auto it = tmp.x; it != tmp.y && valid(a); ++it){
    if (!intersect(a, *it)) continue;
    if (a.x < it->x) output.insert({a.x, it->x-1});
    a.x = it->y+1;
  }
  if (valid(a)) output.insert(a);
  return output;
}

const int Mod = 998244353;
int add(int a, int b){a += b; return a < Mod ? a : a-Mod;}
int mul(int a, int b){return (int)((ll)a*b%Mod);}


pii twice = {0, 2};
pii inc   = {1, 1};
pii iden  = {0, 1};

int apply(pii f, int num, int sum){
  return add(mul(num, f.x),
	     mul(f.y, sum));
}
pii compose(pii f, pii g){return {add(f.x, mul(f.y, g.x)), mul(f.y, g.y)};}

const int offset = (1 << 18);
int T[offset*2];
pii P[offset*2];

void propagate(int id, int num){
  for (auto nid : {2*id, 2*id+1}){
    T[nid] = apply(P[id], num/2, T[nid]);
    P[nid] = compose(P[id], P[nid]);
  }
  P[id] = iden;
}

void apply(int id, int lo, int hi, int slo, int shi, pii f){
  if (lo > shi || hi < slo) return;
  if (lo >= slo && hi <= shi){
    T[id] = apply(f, hi-lo+1, T[id]);
    P[id] = compose(f, P[id]);
    return;
  }

  propagate(id, hi-lo+1);
  int mid = (lo+hi)/2;
  apply(id*2, lo, mid, slo, shi, f);
  apply(id*2+1, mid+1, hi, slo, shi, f);
  T[id] = add(T[id*2], T[id*2+1]);
}

int sum(int id, int lo, int hi, int slo, int shi){
  if (lo > shi || hi < slo) return 0;
  if (lo >= slo && hi <= shi) return T[id];
  propagate(id, hi-lo+1);
  int mid = (lo+hi)/2;
  return add(sum(id*2, lo, mid, slo, shi), sum(id*2+1, mid+1, hi, slo, shi));
}

// void check(const Magic &m){
//   pii prev = {-1, -1};
//   for (auto t : m){
//     assert(!intersect(prev, {t.x-1, t.y+1}));
//     prev = t;
//   }
// }

int main(){
  ios_base::sync_with_stdio(false);

  REP(i,offset*2) P[i] = iden;

  int n, q;
  cin >> n >> q;

  map<int, Magic> M;
  
  REP(blatruc,q){
    int t;
    cin >> t;
    if (t == 1){
      int l, r, x;
      cin >> l >> r >> x;
      pii seg = {l, r};
      Magic &curr = M[x];
      // check(curr);
      for (auto a : difference(seg, curr))
	apply(1, 0, offset-1, a.x, a.y, inc);
      for (auto a : intersection(seg, curr))
	apply(1, 0, offset-1, a.x, a.y, twice);
      join(seg, curr);
    } else {
      int l, r;
      cin >> l >> r;
      cout << sum(1, 0, offset-1, l, r) << endl;
    }
  }

  return 0;
}