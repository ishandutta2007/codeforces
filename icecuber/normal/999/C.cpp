#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char,deque<int>> pos;
  for (int i = 0; i < n; i++) {
    pos[s[i]].push_back(i);
  }
  vector<int> rem(n);
  for (int i = 0; i < k; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      if (pos[c].size()) {
	rem[pos[c].front()] = 1;
	pos[c].pop_front();
	break;
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (!rem[i]) cout << s[i];
  cout << endl;
}