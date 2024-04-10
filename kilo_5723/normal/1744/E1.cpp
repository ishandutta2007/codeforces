#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const pll nil(-1, -1);
map<ll, ll> rep;
void split(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    while (!(n % i)) {
      n /= i;
      rep[i]++;
    }
  }
  if (n > 1) rep[n]++;
}
vector<pll> arr;
bool flg;
ll a, b, c, d;
ll qpow(ll a, ll b) { return b ? (b & 1 ? a : 1) * qpow(a * a, b >> 1) : 1; }
pll solve(vector<pll>::iterator it, vector<pll>::iterator end, ll x, ll y) {
  // printf("%lld %lld\n",x,y);
  if (x > c || y > d) return nil;
  if (it == end) {
    ll p = a / x + 1, q = b / y + 1;
    if (p * x <= c && q * y <= d)
      return {p * x, q * y};
    else
      return nil;
  }
  ll p = it->first, r = it->second;
  ll t = qpow(p, r);
  for (ll i = t; i; i /= p) {
    auto res = solve(it + 1, end, x * i, y * t / i);
    if (res != nil) return res;
  }
  return nil;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    rep.clear();
    split(a);
    split(b);
    flg = false;
    arr.clear();
    for (auto pr : rep) arr.push_back(pr);
    // for (auto pr : arr) printf("%lld %lld; ", pr.first, pr.second);
    reverse(arr.begin(), arr.end());
    pll res = solve(arr.begin(), arr.end(), 1, 1);
    printf("%lld %lld\n", res.first, res.second);
  }
  return 0;
}