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
    int l = 0, r = n-1;
    int suml = 0, sumr = 0, prev = -1, cur = 0, moves = 0;
    int turn = 0;
    while (r >= l) {
      if (cur == 0) moves++;
      if (turn == 0) {
	int v = a[l++];
	suml += v;
	cur += v;
      } else {
	int v = a[r--];
	sumr += v;
	cur += v;
      }
      if (cur > prev) {
	prev = cur;
	cur = 0;
	turn ^= 1;
      }
    }
    cout << moves << ' ' << suml << ' ' << sumr << endl;
  }
}