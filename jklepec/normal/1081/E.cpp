#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const ll MAX = 1e13;

ll next_square(ll x) {
  ll y = sqrt(x);
  return (y + 1) * (y + 1);
}

bool is_square(ll x) {
  ll y = sqrt(x);
  return y * y == x;
}

vector<ll> sol;

void fail() {
  cout << "No\n";
  exit(0);
}

const int MAXN = 3e5 + 5;

int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  int i = 0; ll tmp = 0;
  for(; i < n / 2; ++i) {
    ll diff; cin >> diff;

    a[i] = (int) diff;

    ll scale = next_square(tmp);
    while(scale - tmp <= MAX && !is_square(scale + diff)) {
      scale = next_square(scale);
    }

    if(scale - tmp <= MAX) {
      sol.pb(scale - tmp);
    }
    else {
      fail();
    }
    tmp = scale + diff;
  }

  cout << "Yes\n";

  i = 0;
  for(auto x: sol) {
    cout << x _ a[i] << " ";
    ++ i;
  }

}