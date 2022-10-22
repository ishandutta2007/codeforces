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
    vector<int> p[2];
    for (int i = 0; i < n*2; i++) {
      cin >> a[i];
      p[a[i]%2].push_back(i+1);
    }
    for (int i = 0; i < n-1; i++) {
      if (p[0].size() >= 2) {
	cout << p[0].back() << ' ' << p[0].end()[-2] << endl;
	p[0].pop_back(), p[0].pop_back();
      } else if (p[1].size() >= 2) {
	cout << p[1].back() << ' ' << p[1].end()[-2] << endl;
	p[1].pop_back(), p[1].pop_back();
      } else assert(0);
    }
  }
}