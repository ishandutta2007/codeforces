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
    int a, b, c;
    cin >> a >> b >> c;
    b = b <= c ? c - b + c : b;
    if (a < b)
      cout << 1 << '\n';
    else if (b < a)
      cout << 2 << '\n';
    else
      cout << 3 << '\n';
  }
}