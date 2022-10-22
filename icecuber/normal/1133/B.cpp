#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int,int> c;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    c[d%k]++;
  }
  ll ans = 0;
  for (auto&p : c) {
    int a = p.first, b = (k-a)%k;
    if (a > b) break;
    ans += min(c[a],c[b])/((a==b)+1);
  }
  cout << ans*2 << endl;
}