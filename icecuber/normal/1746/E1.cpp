#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> cands;
  for (int i = 1; i <= n; i++) cands.push_back(i);
  while (cands.size() > 2) {
    int k = cands.size();
    int A = ceil(k*0.26367);
    int sep[4] = {0,A,(A+k)/2,k};
    auto query = [&](int part) {
      cout << "? " << sep[part+1]-sep[part];
      for (int i = sep[part]; i < sep[part+1]; i++) 
        cout << ' ' << cands[i];
      cout << endl;
      string ans;
      cin >> ans;
      assert(ans == "YES" || ans == "NO");
      return ans == "YES";
    };
    auto remove = [&](int part) {
      vector<int> ncands;
      for (int i = 0; i < k; i++) {
        if (i >= sep[part] && i < sep[part+1]) continue;
        ncands.push_back(cands[i]);
      }
      cands = ncands;
    };
    if (query(0) == 0) {
      if (query(0) == 0) {
        remove(0);
        continue;
      }
    }
    if (query(1)) remove(2);
    else remove(1);
  }
  for (int k : {0,1}) {
    cout << "! " << cands[k] << endl;
    string verdict;
    cin >> verdict;
    if (verdict == ":)") break;
  }
}