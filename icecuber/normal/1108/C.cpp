#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string c[6] = {"RGB","RBG","GRB","GBR","BRG","BGR"};
  string best;
  int bestdiffs = 1e9;
  for (int i = 0; i < 6; i++) {
    string r;
    int diffs = 0;
    for (int j = 0; j < n; j++) {
      r += c[i][j%3];
      diffs += s[j] != c[i][j%3];
    }
    if (diffs < bestdiffs) {
      bestdiffs = diffs;
      best = r;
    }
  }
  cout << bestdiffs << endl;
  cout << best << endl;
}