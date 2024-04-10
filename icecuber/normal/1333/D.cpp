#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> steps;

  int ma = 0;
  while (1) {
    vector<int> step;
    for (int i = 0; i+1 < n; i++) {
      if (s[i] == 'R' && s[i+1] == 'L') {
	step.push_back(i);
	swap(s[i],s[i+1]);
	i++;
	ma++;
      }
    }
    if (step.empty()) break;
    steps.push_back(step);
  }
  if (k < steps.size() || k > ma) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < steps.size(); i++) {
    auto step = steps[i];
    int pieces = min((int)step.size(), k-((int)steps.size()-i-1));
    assert(pieces >= 1);

    for (int j = 0; j < pieces-1; j++) {
      cout << 1 << ' ' << step[j]+1 << '\n';
    }
    cout << (int)step.size()+1-pieces;
    for (int j = pieces-1; j < step.size(); j++) {
      cout << ' ' << step[j]+1 << '\n';
    }
    k -= pieces;
  }
  assert(k == 0);
}