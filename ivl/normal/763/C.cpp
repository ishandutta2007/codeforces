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

int m, n;
int a[100005];

int add(int x, int y){x += y; if (x >= m) return x-m; return x;}
int mul(int x, int y){return (int)((ll)x*y%m);}
int pot(int x, int y){
  int r = 1;
  while (y){
    if (y&1) r = mul(r, x);
    x = mul(x, x), y >>= 1;
  } return r;
}
int inv(int x){return pot(x, m-2);}
int neg(int x){if (x) return m-x; return 0;}
int sub(int x, int y){x -= y; if (x < 0) return x+m; return x;}

// void check(int d){
//   int id = inv(d);
//   static int aa[100005];
//   REP(i,n) aa[i] = mul(a[i], id);
//   sort(aa, aa+n);
//   int pref = 0;
//   while (pref < n && aa[pref] == pref+aa[0]) ++pref;
//   if (pref == n){
//     cout << mul(aa[0], d) << " " << d << endl;
//     exit(0);
//   }
//   if (aa[0] != 0) return;
//   if (aa[n-1] != m-1) return;
//   int suff = 0;
//   while (suff < n && aa[n-1-suff] == m-1-suff) ++suff;
//   if (pref + suff != n) return;
//   cout << mul(m-suff, d) << " " << d << endl;
//   exit(0);
// }

void check(int x, int d){
  vector<int> v;
  REP(i,n) v.pb(add(x, mul(d, i)));
  sort(v.begin(), v.end());
  if (v != vector<int>(a, a+n)) return;
  cout << x << " " << d << endl;
  exit(0);
}

int main(){
  ios_base::sync_with_stdio(false);

  srand(2349081);

  cin >> m >> n;
  REP(i,n) cin >> a[i];
  sort(a, a+n);

  if (n == 1 || n == m){cout << a[0] << " " << 1 << endl; return 0;}
  if (n == m-1){
    int s = 0;
    REP(i,m) s = add(s, i);
    REP(i,n) s = sub(s, a[i]);
    s = add(s, 1);
    cout << s << " " << 1 << endl;
    return 0;
  }

  // REP(i,1e7){
  //   int x = rand()%n;
  //   int y = rand()%n;
  //   if (x == y){--i; continue;}
  //   all[i] = sub(a[x], a[y]);
  // } sort(all, all+SZ);

  // vector<pii> all2;
  // for (int i = 0, j = 0; i < SZ; i = j){
  //   while (j < SZ && all[i] == all[j]) ++j;
  //   all2.pb({j-i, all[i]});
  //   if ((int)all2.size() > 2*n-2){cout << -1 << endl; return 0;}
  // } sort(all2.begin(), all2.end(), greater<pii>());

  // REP(i,all2.size()) if (all2[i].y == m-1) TRACE(i); exit(0);

  // REP(i,min((int)all2.size(), 1000)) check(all2[i].y);
  // cout << -1 << endl;

  int bla = 0;
  REP(i,n) bla = add(bla, a[i]);
  bla = mul(bla, inv(n));
  // bla = x + d * (n-1)/2

  int bla2 = 0;
  REP(i,n) bla2 = add(bla2, mul(a[i], a[i]));
  bla2 = mul(bla2, inv(n));

  int tmp = sub(bla2, mul(bla, bla));
  int ntmp = sub(mul(mul(n-1, 2*n-1), inv(6)), mul(mul(n-1, n-1), inv(4)));
  int dd = mul(tmp, inv(ntmp));

  REP(i,n){
    int x = a[i];
    int d = mul(sub(bla, x), mul(2, inv(n-1)));
    if (mul(d, d) == dd) check(x, d);
  }

  cout << -1 << endl;
  
  return 0;
}