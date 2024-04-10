#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> par[500][5001];
int pard[500][5001];
int done[500][5001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int d, s;
  cin >> d >> s;
  queue<pair<int,int>> q;
  par[0][0] = {-1,-1};
  q.push({0,0});
  done[0][0] = 1;
  while (q.size()) {
    int pd = q.front().first;
    int ps = q.front().second;
    q.pop();
    if (pd == 0 && ps == s) break;
    for (int i = 0; i < 10; i++) {
      int nd = (pd*10+i)%d;
      int ns = ps+i;
      if (ns <= s && !done[nd][ns]++) {
	par[nd][ns] = {pd,ps};
	pard[nd][ns] = i;
	q.push({nd,ns});
      }
    }
  }
  int pd = 0, ps = s;
  if (!done[pd][ps]) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  while (pd != -1) {
    ans.push_back(pard[pd][ps]);
    int pd_ = par[pd][ps].first;
    ps = par[pd][ps].second;
    pd = pd_;
  }
  ans.pop_back();
  reverse(ans.begin(), ans.end());
  for (int i : ans) cout << i;
  cout << endl;
}