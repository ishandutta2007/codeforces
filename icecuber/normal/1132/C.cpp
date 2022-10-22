#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> did[5000];
int creds[5000][5000];
int cred[5000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<pair<int,int>> painter(q);
  int pi = 0;
  for (auto&p : painter) {
    cin >> p.first >> p.second;
    p.first--;
    for (int i = p.first; i < p.second; i++) {
      if (did[i].size() < 3)
	did[i].push_back(pi);
    }
    pi++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (did[i].size() == 1) cred[did[i][0]]++;
    else if (did[i].size() == 2) {
      creds[did[i][0]][did[i][1]]++;
      creds[did[i][1]][did[i][0]]++;
    }
    ans += !did[i].empty();
  }
  int best = 1e9;
  for (int i = 0; i < q; i++)
    for (int j = 0; j < i; j++)
      best = min(best, creds[i][j]+cred[i]+cred[j]);
  cout << ans-best << endl;
}