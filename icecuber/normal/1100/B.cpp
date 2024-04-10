#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<int, int> count;
  int n, m;
  cin >> n >> m;
  while (m--) {
    int d;
    cin >> d;
    count[d]++;
    if (count.size() == n) {
      for (int i = 1; i <= n; i++)
	if (!--count[i]) count.erase(i);
      cout << 1;
    } else cout << 0;
  }
  cout << endl;
}