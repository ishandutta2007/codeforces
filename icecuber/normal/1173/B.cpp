#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int m = n/2+1;
  cout << m << endl;
  for (int i = 0; i < n; i++) {
    cout << i/2+1 << ' ' << i/2+1+i%2 << endl;
  }
}