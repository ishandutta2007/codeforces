#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a, b;

void factor(vector <int> &vec, int x) {
  int tmp = sqrt(x);
  for (int i = 1; i <= tmp; i++) {
    if (x % i == 0) {
      vec.push_back(i);
      if (i * i != x) vec.push_back(x / i);
    }
  }
}

int main() {
  scanf("%d %d", &a, &b);
  if (a == b) return puts("0"), 0;
  if (a > b) swap(a, b);
  int k = 0;
  ll ans = 1ll * a * b / __gcd(a, b);
  vector <int> fac;
  factor(fac, b - a);
  for (int x : fac) {
    int t = x - a % x;
    int g = __gcd(a + t, b - a);
    ll v = 1ll * (a + t) * (b + t);
    if (v % g != 0) continue;
    v /= g;
    if (ans > v || (ans == v && k > t)) {
      ans = v, k = t;
    }
  }
  printf("%d", k);
  return 0;
}