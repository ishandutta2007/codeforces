#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int has[1<<21];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n*2);
  for (int i = 0; i < n*2; i++) {
    cin >> x[i];
    has[x[i]] = 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (has[x[i]^x[j]]) ans++;
  cout << (ans%2 ? "Koyomi" : "Karen") << endl;
}