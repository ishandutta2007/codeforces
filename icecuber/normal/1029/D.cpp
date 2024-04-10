#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<int, int> m[11];
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int len = 0;
    int rem = a%k;
    while (a) len++, a /= 10;
    m[len][rem]++;
  }
  /*for (int i = 1; i <= 10; i++) {
    for (auto p : m[i]) {
      cout << i << ' ' << p.first << ' ' << p.second << endl;
    }
  }
  cout << endl;*/
  ll ans = 0;
  for (int i = 1; i <= 10; i++) {
    for (auto p : m[i]) {
      ll mul = 10;
      for (int j = 1; j <= 10; j++) {
	int need = (-p.first*mul%k+k)%k;
	if (m[j].count(need)) {
	  //cout << i << ' ' << j << ' ' << p.first << ' ' << need << ' ' << p.second*(m[j][need]-(i==j && need==p.first)) << endl;
	  ans += 1ll*p.second*(m[j][need]-(i==j && need==p.first));
	}
	mul = (mul*10)%k;
      }
    }
  }
  cout << ans << endl;
}