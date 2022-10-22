#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int c[2] = {};
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a%2]++;
  }
  cout << min(c[0],c[1]) << endl;
}