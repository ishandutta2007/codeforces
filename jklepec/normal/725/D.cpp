#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<ll, ll> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

multiset<ll> da, ne;

vector<point> v2;
vector<ll> v1;

ll n, sol, habet;
ll a, b;

void solve() {
   int i = 0;
   int m = v2.size();
   while(i < m - 1) {
      ll st = v2[i].second - v2[i].first + 1;
      if(da.size() && *(da.rbegin()) > st) {
         ll val = *(da.rbegin());
         da.insert(st);
         habet += val - st;
         da.erase(da.lower_bound(val));
         ne.insert(val);
      }
      else {
         ne.insert(st);
      }
      ll nxt = v2[i + 1].first;
      habet += a - nxt;
      a = nxt;
      while(ne.size() && habet >= *(ne.begin())) {
         ll val = *(ne.begin());
         habet -= val;
         ne.erase(ne.lower_bound(val));
         da.insert(val);
      }
      sol = min(sol, (ll) ne.size() + 1);
      ++i;
   }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n; --n;
	cin >> a >> b;

   rep(i, n) {
      ll x, y; cin >> x >> y;
      if(x > a) {
         ne.insert(y - x + 1);
      }
      else {
         v2.emplace_back(x, y);
      }
   }
   v2.emplace_back(0, 0);
   sort(v2.begin(), v2.end());
   reverse(v2.begin(), v2.end());

   habet = a - v2[0].first;
   a = v2[0].first;
   while(ne.size() && *(ne.begin()) <= habet) {
      ll val = *(ne.begin());
      habet -= val;
      da.insert(val);
      ne.erase(ne.begin());
   }

   sol = ne.size() + 1;

   solve();

   cout << sol;
}