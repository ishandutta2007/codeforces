#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int&v : a) cin >> v;
    sort(a.begin(), a.end());
    vector<int> d;
    for (int i = 0; i < m; i++) {
      d.push_back((a[(i+1)%m]+n-a[i]-1)%n);
    }
    sort(d.rbegin(), d.rend());
    int save = 0;
    for (int i = 0; i < m; i++) {
      int left = d[i]-i*4;
      save += max(int(left>0), left-1);
    }
    cout << n-save << endl;
  }
}