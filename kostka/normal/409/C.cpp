#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  c /= 2;
  d /= 7;
  e /= 4;
  cout << min(e,min(min(a,b),min(c,d)));
  return 0;
}