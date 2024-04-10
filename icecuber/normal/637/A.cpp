#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int best = -1, besta;
  map<int, int> m;
  while (n--) {
    int a;
    cin >> a;
    if (++m[a] > best) {
      best = m[a];
      besta = a;
    }
  }
  cout << besta << endl;
}