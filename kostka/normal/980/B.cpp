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
  int n, k;
  cin >> n >> k;
  string tab[4];
  for(int i=0; i<4; i++) {
    for(int _=0; _<n; _++) tab[i] += '.';
  }
  for(int i=1; i<3; i++) {
    for(int j=1; j<n/2; j++) {
      if(k > 1) {
        tab[i][j] = tab[i][n-j-1] = '#';
        k -= 2;
      }
    }
  }
  if(k) {
    tab[1][n/2] = '#';
    k--;
  }
  if(k) {
    tab[2][n/2] = '#';
    k--;
  }
  assert(k==0);
  cout << "YES\n";
  for(int i=0; i<4; i++) cout << tab[i] << "\n";
  return 0;
}