#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
#define data hgeohgr
const ll M = 1<<18;
ll data[M];
ll sum(int i) {
  ll r = 0;
  for (i += 10; i; i -= i&-i) r += data[i];
  return r;
}

void myset(int i, ll v) {
  v -= sum(i)-sum(i-1);
  for (i += 10; i < M; i += i&-i) data[i] += v;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  map<int,int> xi, yi;
  for (auto&v : p) {
    cin >> v.x >> v.y;
    v.y *= -1;
    xi[v.x], yi[v.y];
  }
  int cx = 1;
  for (auto&p : xi) p.y = cx++;
  int cy = 1;
  for (auto&p : yi) p.y = cy++;
  vector<vector<int>> q(cy);
  for (auto&v : p)
    q[yi[v.y]].push_back(xi[v.x]);

  ll ans = 0;
  for (auto&v : q) {
    sort(v.begin(), v.end());
    for (int i : v) myset(i,1);
    ll n = sum(cx);
    ans += n*(n+1)/2;
    int last = 0;
    v.push_back(cx);
    for (int i : v) {
      ll a = sum(i-1)-sum(last);
      ans -= a*(a+1)/2;
      last = i;
    }
  }
  cout << ans << endl;
}