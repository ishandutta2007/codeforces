#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<int> a(1<<n);
  ll sum = 0;
  for (int&v : a) {
    cin >> v;
    sum += v;
  }
  cout << setprecision(20);
  cout << sum * 1. / (1<<n) << endl;
  while (r--) {
    int z, g;
    cin >> z >> g;
    sum -= a[z];
    a[z] = g;
    sum += a[z];
    cout << sum * 1. / (1<<n) << endl;
  }
}