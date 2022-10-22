#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 1e6 + 5;

int pref[MAXN], suff[MAXN];

vector<int> indi[MAXN];
int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, x; cin >> n >> x;
  REP(i, n) {
    cin >> a[i];
    indi[a[i]].pb(i);
  }
  pref[0] = -1;
  suff[x + 1] = n;

  FOR(i, 1, x + 1) {
    if(indi[i].size() == 0) {
      pref[i] = pref[i - 1];
      continue;
    }
    pref[i] = n;
    if(pref[i - 1] > indi[i].front()) continue;
    pref[i] = indi[i].back();
  }
  for(int i = x; i; --i) {
    if(indi[i].size() == 0) {
      suff[i] = suff[i + 1];
      continue;
    }
    suff[i] = -1;
    if(suff[i + 1] < indi[i].back()) continue;
    suff[i] = indi[i].front();
  }

  ll sol = 0;
  int j = 1;
  FOR(i, 1, x + 1) {
    if(pref[i - 1] >= n) break;
    j = max(j, i);
    while(j <= x && suff[j + 1] <= pref[i - 1]) j ++;
    sol += x - j + 1;
  }

  cout << sol << endl;

}