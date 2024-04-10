#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> acc = {0};
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    acc.push_back(d+acc.back());
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << (acc[r]-acc[l])/10 << '\n';
  }
}