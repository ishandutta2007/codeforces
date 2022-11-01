#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll ans = 3;
  for (int u = 2; u <= 26; ++u)
  {
    cout << "? 1 " << u << '\n';
    cout.flush();
    ll dis1, dis2;
    cin >> dis1;
    if (dis1 == -1)
    {
      ans = u - 1;
      break;
    }
    cout << "? " << u << " 1" << '\n';
    cout.flush();
    cin >> dis2;
    if (dis1 != dis2)
    {
      ans = dis1 + dis2;
      break;
    }
  }
  cout << "! " << ans << '\n';
  cout.flush();
}