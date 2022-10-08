#include "bits/stdc++.h"

using namespace std;

int ile(int y)
{
  for(int i=1; i<100000; i++)
  {
    long long x = 1LL*i*(i-1)/2;
    if(x == y)
      return i;
  }
  return -1;
}

bool check2(int l0, int l1, int a01, int a10)
{
  long long oc = l0 * l1;
  if(a01 + a10 != oc)
    return false;
  if(l0 + l1 <= 0)
    return false;
  vector <int> kubelki(l0+1, 0);
  int e = 0;
  if(l0 != 0)
  {
    e = a01 / (l0);
    kubelki.back() = e;
    int f = a01 % (l0);
    kubelki[f]++;
  }
  else
    l1++;
  int g = l1 - e - 1;
  kubelki[0] += g;
  //cerr << l0 << " " << l1 << " " << e << " " << g << "\n";
  for(int i=0; i<=l0; i++)
  {
    while(kubelki[i]--)
      cout << "1";
    if(i != l0)
      cout << "0";
  }
  cout << "\n";
  return true;
}

bool check(int a00, int a01, int a10, int a11)
{
  int l0 = ile(a00);
  int l1 = ile(a11);
  //cerr << l0 << " " << l1 << "\n";
  if(min(l0,l1) == -1)
    return false;
  if(l0 == 1)
  {
    if(check2(0, l1, a01, a10))
      return true;
    if(check2(1, l1, a01, a10))
      return true;
  }
  if(l1 == 1)
  {
    if(check2(l0, 0, a01, a10))
      return true;
    if(check2(l0, 1, a01, a10))
      return true;
  }
  return check2(l0, l1, a01, a10);
}

int main()
{
  int a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  if(check(a00,a01,a10,a11) == false)
    cout << "Impossible\n";
  return 0;
}