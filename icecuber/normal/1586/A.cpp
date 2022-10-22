#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int isprime(int n) {
  for (int i = 2; i*i <= n; i++) 
    if (n%i == 0) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int&v : a) cin >> v, sum += v;
    int skip = -1;
    if (isprime(sum)) {
      for (int i = 0; i < n; i++) {
        if (!isprime(sum-a[i])) skip = i;
      }
    }
    cout << n-(skip != -1) << endl;
    for (int i = 0; i < n; i++) {
      if (i == skip) continue;
      cout << i+1 << ' ';
    }
    cout << endl;
  }
}