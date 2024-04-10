#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> pos(26);
    for (int i = 1; i < n - 1; ++i)
      pos[s[i] - 'a'].push_back(i + 1);
    int dis = abs(s[0] - s[n - 1]);
    int x = s[0] - 'a', y = s[n - 1] - 'a';
    int ret = 2;
    for (int i = min(x, y); i <= max(x, y); ++i)
      ret += pos[i].size();
    cout << dis << ' ' << ret << '\n';
    if (x <= y)
    {
      cout << 1 << ' ';
      for (int i = x; i <= y; ++i)
        for (int val : pos[i])
          cout << val << ' ';
      cout << n << '\n';
    }
    else
    {
      cout << 1 << ' ';
      for (int i = x; i >= y; --i)
        for (int val : pos[i])
          cout << val << ' ';
      cout << n << '\n';
    }
  }
}