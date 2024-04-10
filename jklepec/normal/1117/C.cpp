#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pii;

const ll inf = 3e14 + 5;

ll n;
string s;
ll xs, ys;
ll xf, yf;

map<char, ll> dx = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
map<char, ll> dy = {{'U', 1}, {'D', -1}, {'R', 0}, {'L', 0}};

pair<ll, ll> simulate(ll k) {
  ll X = 0, Y = 0;
  REP(i, n) {
    X += dx[s[i]];
    Y += dy[s[i]];
  }

  X = X * (k / n);
  Y = Y * (k / n);
  REP(i, k % n) {
    X += dx[s[i]];
    Y += dy[s[i]];
  }

  return {X, Y};
}

ll mabs(ll x) {
  if(x < 0) return -x;
  return x;
}

int main() {
  cin >> xs >> ys;
  cin >> xf >> yf;
  cin >> n >> s;

  ll lo = 1, hi = inf;
  while(lo < hi) {
    ll mi = (lo + hi) / 2;

    auto get = simulate(mi);
    ll X = xs + get.fi;
    ll Y = ys + get.se;

    ll dist = mabs(X - xf) + mabs(Y - yf);
    if(dist <= mi) {
      hi = mi;
    }
    else {
      lo = mi + 1;
    }
  }

  if(lo == inf) {
    cout << -1;
  }
  else {
    cout << lo;
  }
}