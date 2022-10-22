#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  cin >> x;
  vector<int> ans;
  int ops = 0;
  while (x&(x+1)) {
    int log2 = 0;
    while (x>>log2) log2++;
    ans.push_back(log2);
    x = (1<<log2)-1-x;
    ops++;
    if (x&(x+1)) {
      x++;
      ops++;
    } else break;
  }
  cout << ops << endl;
  for (int i : ans)
    cout << i << ' ';
  cout << endl;
}