#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

bool check_ok(vector<vector<int>>& pref, int l, int r, int f) {
    for (int i = 0; i < 100; i++) {
        if (pref[i][r] - pref[i][l] > f) {
            return false;
        }
    }
    return true;
}

tuple<int, int, int> find_max_for_char(vector<int>& pos, vector<vector<int>>& pref, int m, int c) {
    int n = pos.size();
    vector<int> block_pref(n + 1, 0);
    for (int i = 1; i < n; i++) {
        block_pref[i] = i - pref[c][pos[i]];
    }

    vector<int> minInd(2 * n, pos[n - 1] + 3);
    vector<int> maxInd(2 * n, -1);

    for (int i = 0; i < n; i++) {
        maxInd[block_pref[i] + n] = pos[i];
        minInd[block_pref[i] + n] = min(minInd[block_pref[i] + n], pos[i]);
    }

    int leftEnd = -1;
    int rightEnd = -1;
    int maxLength = -1;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (minInd[i] < maxInd[i + 1]) {
            if (maxInd[i + 1] - minInd[i] > maxLength) {
                maxLength = maxInd[i + 1] - minInd[i];
                rightEnd = maxInd[i + 1];
                leftEnd = minInd[i];
            }
        }
    }

    return { leftEnd + 1, rightEnd, pref[m][rightEnd] - pref[m][leftEnd + 1] };
}

int solve(vector<int>& a, int c) {
  int n = a.size();
  vector<int> pos;
  vector<vector<int>> pref(100, vector<int>(n + 1, 0));
  pos.push_back(-1);
  for (int i = 0; i < n; i++) {
    if (a[i] == c) {
      pos.push_back(i);
    }
    for (int j = 0; j < 100; j++) {
      pref[j][i + 1] = pref[j][i];
    }
    pref[a[i]][i + 1]++;
  }
  pos.push_back(n);
  
  int result = 2;
  for (int i = 0; i < 100; i++) {
    if (i == c) continue;
    auto [l, r, f] = find_max_for_char(pos, pref, c, i);
    if (check_ok(pref, l, r, f)) {
        result = max(result, r - l);
    }
  }

  return result;
}
 
int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a[i]--;
  
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  
  vector<int> count(100, 0);
  for (auto x : a) count[x]++;
  int maxCount = -1;
  for (auto c : count) {
    maxCount = max(maxCount, c);
  }
 
  if (maxCount == n) {
    cout << "0\n";
    return 0;
  }
 
  int numCount = 0;
  int maxEl = -1;
  for (int i = 0; i < 100; i++) {
    if (count[i] == maxCount) {
      numCount++;
      maxEl = i;
    }
  }
 
  if (numCount > 1) {
    cout << n << "\n";
    return 0;
  }
 
  cout << solve(a, maxEl) << "\n";
}