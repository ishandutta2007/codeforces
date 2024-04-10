#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[2000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a]++;
  }
  int odds = 0;
  for (int i = 0; i <= k; i++)
    odds += c[i]%2;
  cout << n-odds/2 << endl;
}