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
    vector<int> a(n);
    int cnt[2] = {};
    for (int&v : a) {
      cin >> v;
      cnt[v%2]++;
    }
    sort(a.begin(), a.end());
    int cons = 0;
    for (int i = 0; i+1 < n; i++) {
      if (a[i+1]-a[i] == 1)
	cons = 1;
    }
    cout << (cnt[0]%2 == 0 || cons ? "YES" : "NO") << endl;
  }
}