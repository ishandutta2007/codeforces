#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int moves = min(count(s.begin(), s.end(), '0'),
		    count(s.begin(), s.end(), '1'));
    cout << (moves%2 ? "DA" : "NET") << endl;
  }
}