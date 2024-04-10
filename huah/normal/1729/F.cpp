#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  const int mod = 1e9 + 7;
  int q;
  cin >> q;
  while (q--)
  {
    string s;
    cin >> s;
    int w, m;
    cin >> w >> m;
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i)
      a[i + 1] = (a[i] + (s[i] - '0')) % 9;
    vector<vector<int>> vc(9);
    for (int i = 1; i + w - 1 <= n; ++i)
      vc[(a[i + w - 1] - a[i - 1] + 9) % 9].push_back(i);
    for (int i = 0; i < 9; ++i)
      while (vc[i].size() > 2)
        vc[i].pop_back();
    while (m--)
    {
      int l, r, k;
      cin >> l >> r >> k;
      int t = (a[r] - a[l - 1] + 9) % 9;
      int l1 = inf, l2 = inf;
      for (int x = 0; x < 9; ++x)
        for (int y = 0; y < 9; ++y)
          if ((x * t + y) % 9 == k)
          {
            for (int a : vc[x])
              for (int b : vc[y])
                if (a != b)
                {
                  if (a < l1 || a == l1 && b < l2)
                    l1 = a, l2 = b;
                }
          }
      if (l1 == inf)
        l1 = l2 = -1;
      cout << l1 << ' ' << l2 << '\n';
    }
  }
}