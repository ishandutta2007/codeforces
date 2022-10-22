#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int back_gcd[100001];
int ans[100000];

mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  auto start = chrono::steady_clock::now();
  while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-start).count() < 200) {
    shuffle(a.begin(), a.end(), mrand);
    for (int i = n-1; i >= 0; i--) {
      back_gcd[i] = __gcd(back_gcd[i+1], a[i].first);
    }

    int g = 0, g2 = 0, lcm = 1;
    for (int i = 0; i < n; i++) {
      if (__gcd(back_gcd[i+1],g) == 1) {
	ans[a[i].second] = 2;
	g2 = __gcd(g2, a[i].first);
      } else {
	ans[a[i].second] = 1;
	g = __gcd(g, a[i].first);
      }
    }
    if (g2 != 1) continue;
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
  }
  cout << "NO" << endl;
}