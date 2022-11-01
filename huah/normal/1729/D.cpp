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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
      cin >> x[i];
    for (int i = 0; i < n; ++i)
      cin >> y[i], y[i] -= x[i];
    multiset<int> s;
    vector<int> vc;
    for (int i = 0; i < n; ++i)
      if (y[i] < 0)
        vc.push_back(y[i]);
      else
        s.insert(y[i]);
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    int ans = 0;
    for (int val : vc)
    {
      val = abs(val);
      auto it = s.lower_bound(val);
      if (it != s.end())
      {
        ++ans;
        s.erase(s.find(*it));
      }
    }
    ans += s.size() / 2;
    cout << ans << '\n';
  }
}