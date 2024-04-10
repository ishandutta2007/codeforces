#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> A(N+1);
  for (int i = 0; i < N; ++i) {
    cin >> A[i+1];
  }

  vector<int> ans;
  for (int k = 1; k <= N; ++k) {
    bool ok = true;
    for (int i = k + 1; i <= N; ++i) {
      if (A[i] - A[i-1] != A[i-k] - A[i-1-k]) {
        ok = false;
        break;
      }
    }

    if (ok) ans.push_back(k);
  }

  cout << ans.size() << "\n";
  for (int k: ans) {
    cout << k << " ";
  }
  cout << "\n";
  return 0;
}