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
  int n;
  cin >> n;
  string x;
  cin >> x;
  int ile = 0;
  for(int i=2; i<SZ(x); i++) {
    if(x[i] == 'x' and x[i-1] == 'x' and x[i-2] == 'x') ile++;
  }
  cout << ile << "\n";
  return 0;
}