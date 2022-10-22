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

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 1 << 15;

int dp[MAXN];

unordered_map<int, int> ima;

ll sum[16];
vector<int> v[16];

vector<pair<int, pii>> sol[MAXN];

int cookie;
int bio[16];
pii ispis[16];
vector<pair<int, pii>> temp;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int k; cin >> k;
  ll uk = 0;
  REP(i, k) {
    int n; cin >> n;
    REP(j, n) {
      int x; cin >> x;
      v[i].pb(x);
      sum[i] += x;
      ima[x] = i + 1;
    }
    uk += sum[i];
  }

  ll svak = uk / k;
  if(svak * k != uk) {
    cout << "No\n";
    return 0;
  }

  REP(i, k) {
    for(auto x: v[i]) {
      ll treba = svak - sum[i] + x;
      if(treba > 1e9) continue;

      bool ok = true;
      int msk = (1 << i);

      int X = x, j = i;
      cookie ++;
      temp.clear();
      while(1) {
        if(!ima[treba] || treba > 1e9) {
          ok = false;
          break;
        }
        temp.pb({j, {X, ima[treba] - 1}});
        X = treba;
        j = ima[treba] - 1;
        msk |= (1 << j);
        if(i == j) break;
        if(bio[j] == cookie) {
          ok = false;
          break;
        }
        bio[j] = cookie;
        treba = svak - sum[j] + treba;
      }
      if(ok && X == x) {
        dp[msk] = 1;
        sol[msk] = temp;
        REP(ii, sol[msk].size()) {
          sol[msk][ii].se.se = sol[msk][(ii - 1 + sol[msk].size()) % sol[msk].size()].fi;
        }
      }
    }
  }
  REP(mask, (1 << k)) {
    if(dp[mask]) continue;
    for(int submask = mask; submask; submask = (submask - 1) & mask) {
      if(dp[submask] && dp[mask ^ submask]) {
        dp[mask] = 1;
        for(auto p: sol[submask]) {
          sol[mask].pb(p);
        }
        for(auto p: sol[mask ^ submask]) {
          sol[mask].pb(p);
        }
        break;
      }
    }
  }

  if(dp[(1 << k) - 1]) {
    cout << "Yes\n";
    REP(i, k) {
      ispis[i] = pii(v[i].front(), i);
    }
    for(auto p: sol[(1 << k) - 1]) {
      ispis[p.fi] = p.se;
    }
    REP(i, k) {
      cout << ispis[i].fi _ ispis[i].se + 1 << endl;
    }
  }
  else {
    cout << "No\n";
  }
}