#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string n;
    cin >> n;
    cout << *max_element(n.begin(), n.end())-'0' << endl;
  }
}