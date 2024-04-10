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

void fin(ll x){cout << x << endl; exit(0);}

int n, k, m;
int a[100005];

void reduce(vector<pii> &v){
  vector<pii> out;
  for (auto t : v){
    if (!out.empty() && out.back().x == t.x)
      t.y += out.back().y, out.pop_back();
    t.y %= k;
    if (t.y) out.pb(t);
  }
  v = out;
}

ll len(const vector<pii> &v){
  ll out = 0;
  for (auto t : v) out += t.y;
  return out;
}

template<class T>
vector<T> operator+(const vector<T> &x, const vector<T> &y){
  vector<T> out = x;
  out.insert(out.end(), y.begin(), y.end());
  return out;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k >> m;
  REP(i,n) cin >> a[i];

  int x = a[0], y = a[0];
  REP(i,n)
    x = max(x, a[i]), y = min(y, a[i]);
  if (x == y) fin((ll)n*m % k);
  if (k >= n) fin((ll)n*m);
  
  vector<pii> v;
  REP(i,n) v.pb({a[i], 1});
  reduce(v);
  if (v.empty()) fin(0);
  if (v.front().x != v.back().x || v.front().y + v.back().y < k) fin(m*len(v));

  vector<pii> vv = v+v;
  reduce(vv);
  if (len(vv) == 0) fin((m%2)*len(v));

  /*
    k = 4
    1: 112232211
    2: 1122332211
    3: 11223332211
    4: empty :O

    k = 4
    1: 1122211
    2: 112211, shorter than (1) :O
   */

  // f(1) = len(v), f(2) = len(vv), linear function
  if (vv.size() > v.size()) fin((len(vv)-len(v)) * (m-1) + len(v));

  if (vv == v) fin(len(v));

  assert(vv.size() == v.size());
  int p = 0;
  while (vv[p] == v[p]) ++p;
  int clen = (int)((ll)v[p].y * m % k);
  if (clen == 0) fin(0);
  else fin(len(v) - v[p].y + clen);

  return 0;
}