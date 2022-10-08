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
  string x;
  cin >> x;
  int pearls = 0, lines = 0;
  for(int i=0; i<SZ(x); i++) {
    if(x[i] == 'o') pearls++;
    else lines++;
  }
  if(pearls == 0) cout << "YES\n";
  else {
    if(lines % pearls == 0) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}