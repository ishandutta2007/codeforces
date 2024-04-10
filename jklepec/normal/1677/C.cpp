#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

int veza[MAXN];

int e(int x, int p) {
  return veza[x] - p;
}

int a[MAXN];
int b[MAXN];

int bio[MAXN];

int dfs(int x, int p) {
  if (bio[x]) return 0;
  bio[x] = 1;
  return dfs(e(x, p), x) + 1;
}

void solve(){
  int n; cin >> n;

  REP(i, n) {
    veza[i] = 0;
    cin >> a[i];
    a[i] --;
  }
  REP(i, n) {
    cin >> b[i];
    b[i] --;
  }
  REP(i, n) {
    veza[a[i]] += b[i];
    veza[b[i]] += a[i];
    bio[i] = 0;
  }

  vector<int> cyc;

  REP(i, n) {
    if (!bio[a[i]]) cyc.push_back(dfs(a[i], b[i]));
  }

  sort(cyc.begin(), cyc.end());
  reverse(cyc.begin(), cyc.end());

  int add = 0;
  int N = n;
  ll sol = 0;

  for (auto c: cyc) if (c % 2) add ++;

  N -= add;

  for (auto c: cyc) {
    c -= c % 2;
    if (!c) continue;

    ll kolko = c - 2;
    kolko /= 2;

    sol += kolko * (kolko + 1) * 2;
    sol += (ll) c * (N + 1 - c + add);
    N -= c;
  }

  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int t; cin >> t;
  while (t --) solve();
}