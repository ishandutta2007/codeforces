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
    int found = 0;
    int ok = (n==1), prev = -100;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      found |= (a[i] == k);
      if (a[i] >= k) {
	if (i-prev <= 2) ok = 1;
	prev = i;
      }
    }
    cout << (ok && found ? "yes" : "no") << endl;
  }
}