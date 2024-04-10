#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
int par[nax], dp[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> prev;
  int ma = -1, mai;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dp[i] = 1;
    par[i] = -1;
    if (prev.count(a-1)) {
      par[i] = prev[a-1];
      dp[i] = dp[prev[a-1]]+1;
    }
    if (dp[i] > ma) {
      ma = dp[i];
      mai = i;
    }
    prev[a] = i;
  }
  cout << ma << endl;
  int p = mai;
  vector<int> path;
  while (p != -1) {
    path.push_back(p);
    p = par[p];
  }
  reverse(path.begin(), path.end());
  for (int i : path)
    cout << i+1 << ' ';
  cout << endl;
}