#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, v;
  cin >> n >> v;
  if (n <= v) cout << n-1 << endl;
  else cout << v+(n-v+2)*(n-v-1)/2 << endl;
}