#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (string&s : a) {
      cin >> s;
    }
    vector<string> sorted = a;
    sort(sorted.begin(), sorted.end());
    for (string s : a) {
      int found = 0;
      for (int w = 1; w < (int)s.size(); w++) {
        if (binary_search(sorted.begin(), sorted.end(), s.substr(0,w)) && 
            binary_search(sorted.begin(), sorted.end(), s.substr(w))) {
          found = 1;
          break;
        }
      }
      cout << found;
    }
    cout << endl;
  }
}