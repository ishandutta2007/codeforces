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
  int n, m;
  cin >> n >> m;
  if(n >= 30) cout << m << "\n";
  else cout << m % (1<<n) << "\n";
  return 0;
}