//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int ile0[MAXN], ile1[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  string a, b;
  cin >> a >> b;
  int sa = (int)a.size();
  long long res = 0;
  for(int i=0; i<sa; i++)
  {
    if(a[i] == '0')
      ile0[i]++;
    else
      ile1[i]++;
  }
  int sb = (int)b.size();
  int wsk2 = sb;
  for(int i=sa-1; i>=0; i--)
  {
    if(a[i] == '0')
      ile0[wsk2]--;
    else
      ile1[wsk2]--;
    wsk2--;
  }
  for(int i=1; i<sb; i++)
  {
    ile0[i] += ile0[i-1];
    ile1[i] += ile1[i-1];
  }
  for(int i=0; i<sb; i++)
  {
    if(b[i] == '0')
      res += ile1[i];
    else
      res += ile0[i];
  }
  cout << res << "\n";
  return 0;
}