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
    string s;
    cin >> s;
    string ans;
    for (int i = n - 1; i >= 0; --i)
      if (s[i] == '0')
      {
        int val = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
        ans += (char)(val - 1 + 'a');
        i -= 2;
      }
      else
        ans += (char)(s[i] - '0' - 1 + 'a');
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
  }
}