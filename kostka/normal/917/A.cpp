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
  cin.tie(0); cout.tie(0);
  string x;
  cin >> x;
  int res = 0;
  for(int i=0; i<SZ(x); i++) {
    pii range = {0, 0};
    for(int j=i; j<SZ(x); j++) {
      if(x[j] == '(') {
        range.x++;
        range.y++;
      } else if(x[j] == ')') {
        range.x--;
        range.y--;
      } else {
        range.x--;
        range.y++;
      }
      if(range.x < 0) range.x += 2;
      if(range.y < 0) break;
      if(range.x == 0) res++;
    }
  }
  cout << res << "\n";
  return 0;
}