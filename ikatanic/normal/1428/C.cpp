#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    stack<char> S;
    for (char c : s) {
      if (c == 'B' && !S.empty()) {
        S.pop();
      } else {
        S.push(c);
      }
    }

    cout << S.size() << '\n';
  }

  return 0;
}