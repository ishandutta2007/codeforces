#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mem[2][1<<20];
int a[300000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int cum = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    mem[i%2][cum]++;
    cin >> a[i];
    cum ^= a[i];
    ans += mem[1-i%2][cum];
  }
  cout << ans << endl;
}