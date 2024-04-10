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
    for (int&v : a) cin >> v;
    int last = -1;
    int state = 0;
    int i;
    for (i = n-1; i >= 0; i--) {
      if (state == 0) {
	if (a[i] < last) state = 1;
      } else if (state == 1) {
	if (a[i] > last) break;
      }
      last = a[i];
    }
    cout << i+1 << endl;
  }
}