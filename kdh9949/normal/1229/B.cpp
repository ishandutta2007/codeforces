#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define x first
#define y second

const int N = 100005;
const ll M = ll(1e9)+7;

int n;
ll a[N], r;
vector<int> e[N];
vector<pll> v;

void f(int x, int y){
  vector<pll> pv = v;
  v.emplace_back(a[x], 1LL);
  for(pll &i : v) i.x = gcd(i.x, a[x]);
  vector<pll> w;
  for(pll &i : v){
    if(w.empty() || w.back().x != i.x) w.push_back(i);
    else w.back().y += i.y;
  }
  v = w;
  for(pll &i : v) (r += i.x * i.y) %= M;
  for(int i : e[x]) if(i != y) f(i, x);
  v = pv;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 0, x, y; i < n-1; i++){
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  f(1, 0);
  cout << r << '\n';
}