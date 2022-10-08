//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

vi F = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341, 390, 439, 488, 537, 586, 635, 684, 733, 782, 831, 880, 929, 978, 1027, 1076, 1125, 1174, 1223, 1272, 1321, 1370, 1419, 1468, 1517, 1566, 1615, 1664, 1713, 1762, 1811, 1860, 1909, 1958, 2007, 2056, 2105, 2154, 2203, 2252, 2301, 2350, 2399, 2448, 2497, 2546, 2595, 2644};

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int fs = SZ(F);
  if(n < fs) cout << F[n] << "\n";
  else cout << 49LL * (n-fs+1) + F.back() << "\n";
  return 0;
}