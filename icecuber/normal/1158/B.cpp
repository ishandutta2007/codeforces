#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a = (n-k)/2;
  string ans;
  for (int i = 0; i < n; i++)
    ans += (i%(a+1)==a) + '0';
  cout << ans << endl;
}