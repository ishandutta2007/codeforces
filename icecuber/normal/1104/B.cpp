#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int moves = 0;
  stack<char> past;
  for (char c : s) {
    if (past.size() && past.top() == c) {
      moves++;
      past.pop();
    } else past.push(c);
  }
  cout << (moves%2 ? "Yes" : "No") << endl;
}