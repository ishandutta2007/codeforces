#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int min_dist = 2e9, minx;
    for (int i = 0; i+k < n; i++) {
      int dist = (a[i+k]-a[i]+1)/2;
      if (dist < min_dist) {
	min_dist = dist;
	minx = a[i+k]+a[i]>>1;
      }
    }
    cout << minx << endl;
  }
}