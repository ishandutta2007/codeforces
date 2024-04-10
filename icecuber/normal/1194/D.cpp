#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int win;
    if (k%3) win = n%3;
    else win = (n-(n+1)/(k+1))%3;
    cout << (win ? "Alice" : "Bob") << endl;
  }
}