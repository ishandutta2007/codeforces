#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define left leftmrs
#define right rightmrs

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void fin(int x){cout << x << endl; exit(0);}

int n;
ll w[200005];
ll h[200005];
ll c[200005];

set<ll> left;
set<ll> right;

int func(vector<vector<ll>> all){
  vector<ll> divs;
  for (ll d = 1; d*d <= all[0][0]; ++d)
    if (all[0][0]%d == 0){
      divs.pb(d);
      if (d*d != all[0][0]) divs.pb(all[0][0]/d);
    }

  int cnt = 0;
  for (auto d : divs){
    bool check = true;
    vector<ll> lv(left.size()), rv(right.size());
    ll dd = all[0][0] / d;
    REP(i,left.size())
      if (all[i][0]%dd == 0) lv[i] = all[i][0] / dd;
      else check = false;
    REP(i,right.size())
      if (all[0][i]%d == 0) rv[i] = all[0][i] / d;
      else check = false;
    if (!check) continue;
    REP(i,left.size()) REP(j,right.size())
      if (all[i][j] != lv[i] * rv[j]){
	check = false;
	break;
      }
    if (check) ++cnt;
  }

  return cnt;
}

vector<vector<ll>> extract(vector<vector<ll>> &all, ll p){
  auto output = all;
  REP(i,all.size()) REP(j,all[0].size()){
    output[i][j] = 1;
    while (all[i][j]%p == 0) all[i][j] /= p, output[i][j] *= p;
  } return output;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(i,n) cin >> w[i] >> h[i] >> c[i];

  REP(i,n) left.insert(w[i]);
  REP(i,n) right.insert(h[i]);
  if ((ll)left.size() * (ll)right.size() > (ll)n) fin(0);

  map<ll, int> leftM;
  map<ll, int> rightM;
  int tmp = 0;
  for (auto t : left) leftM[t] = tmp++;
  tmp = 0;
  for (auto t : right) rightM[t] = tmp++;
  
  vector<ll> leftV(left.begin(), left.end());
  vector<ll> rightV(right.begin(), right.end());

  vector<vector<ll>> all(left.size(), vector<ll>(right.size()));
  REP(i,n) all[leftM[w[i]]][rightM[h[i]]] = c[i];

  vector<ll> primes = {2, 3, 5, 7, 11};
  int cnt = 1;
  for (auto p : primes)
    cnt *= func(extract(all, p));

  cout << cnt * func(all) << endl;

  return 0;
}