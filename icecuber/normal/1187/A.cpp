#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s, t;
    cin >> n >> s >> t;
    int both = s+t-n;
    cout << max(s-both,t-both)+1 << endl;
  }
}