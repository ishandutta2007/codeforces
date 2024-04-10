#include <bits/stdc++.h>

using namespace std;

map<char, char> g;
set<char> present;
map<char, bool> used;
string top;
int n;


void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s)
      present.insert(c);
    for (int i = 0; i + 1 < (int) s.length(); ++i) {
      g[s[i]] = s[i + 1];
      used[s[i + 1]] = true;
    }
  }
}

void kill() {
  for (char c : present)
    if (!used[c]) {
      while (c != 0) {
        top.push_back(c);
        c = g[c];
      }
    }

  cout << top << endl;
}

int main() {
  read();
  kill();
  return 0;
}