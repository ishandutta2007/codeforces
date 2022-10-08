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

int main()
{
  ios_base::sync_with_stdio(0);
  int n, pos, l, r;
  cin >> n >> pos >> l >> r;
  int ile = 0;
  if(not(l <= pos and pos <= r)) {
    if(pos > r) {
      ile += pos - r;
      pos = r;
    }
    if(pos < l) {
      ile += l - pos;
      pos = l;
    }
  }
  if(l != 1 and r != n) {
    ile += (r-l);
    ile += 2 + min((r-pos), (pos-l));
  }
  if(l == 1 and r != n) {
    ile += (r-pos) + 1;
  }
  if(l != 1 and r == n) {
    ile += (pos-l) + 1;
  }
  cout << ile << "\n";
  return 0;
}