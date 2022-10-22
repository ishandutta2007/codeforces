#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(int i) {
  return (i+1)/2*(i%2?-1:1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << f(r)-f(l-1) << endl;
  }
}