#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    cout << (b.substr(1) == a.substr(n-m+1) && count(a.begin(), a.begin()+n-m+1, b[0]) ? "YES" : "NO") << endl;
  }
}