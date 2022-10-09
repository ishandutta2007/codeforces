//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const ll INF = 1e18 + 7;

int n, k;
vector <int> p, q[2];
vector <ll> Q[2];

ll ile(ll x) {
  long long ret = 0;
  for(auto a : Q[0]) {
    auto it = upper_bound(Q[1].begin(), Q[1].end(), x/a);
    ret += distance(Q[1].begin(), it);
  }
  return ret;
}

void gen(int x, int i = 0, ll e = 1) {
  if(i == SZ(q[x])) {
    Q[x].push_back(e);
    return;
  }
  gen(x, i+1, e);
  if(log(e) + log(q[x][i]) <= log(2e18)) {
    gen(x, i, e*q[x][i]);
  }
}

void fix(int x) {
  sort(Q[x].begin(), Q[x].end());
  Q[x].resize(distance(Q[x].begin(), lower_bound(Q[x].begin(), Q[x].end(), 1e18)));
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    p.push_back(x);
  }
  sort(p.begin(), p.end());
  for(int i=0; i<SZ(p); i++) {
    q[i%2].push_back(p[i]);
  }
  gen(0); gen(1);
  fix(0); fix(1);
  cin >> k;
  long long a = 0, b = 1e18+7;
  while(b-a > 1) {
    ll m = (a+b)/2;
    //cerr << a << " " << b << " " << m << "\n";
    if(ile(m) < k) a = m;
    else b = m;
  }
  cout << b << "\n";
  return 0;
}