#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> stack;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == 1) stack.push_back(a);
      else {
        while (stack.back()+1 != a) stack.pop_back();
        stack.back()++;
      }

      for (int j = 0; j < (int)stack.size(); j++) {
        if (j) cout << '.';
        cout << stack[j];
      }
      cout << endl;
    }
  }
}