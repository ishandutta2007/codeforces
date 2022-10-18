#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

void solve(int n, string& s, vector<int>& ans) {
  if (n == 0) return;

  int mini = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] < s[mini]) mini = i;
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == s[mini]) {
      if (i > mini) ans[i-1] ^= 1, cnt++;
      ans[i] ^= 1;
      cnt++;
    }
  }

  solve(mini, s, ans);

  if (mini > 0 && cnt % 2) {
    ans[mini - 1] ^= 1;
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);

  string S;
  cin >> S;

  vector<int> ans(S.size());
  solve((int)S.size(), S, ans);;

  for (int x: ans) cout << x << " ";
  cout << "\n";

  return 0;
}