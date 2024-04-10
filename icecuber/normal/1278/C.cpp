#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n*2);
    for (int&v : a) {cin >> v; v = v == 2 ? 1 : -1;}
    map<int,int> ma;
    ma[0] = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
      acc += a[i];
      ma[acc] = i+1;
    }

    int ans = ma[0];
    acc = 0;
    for (int i = n*2-1; i >= n; i--) {
      acc -= a[i];
      if (ma.count(acc))
	ans = max(ans, ma[acc]+(n*2-i));
    }
    cout << n*2-ans << endl;
  }
}