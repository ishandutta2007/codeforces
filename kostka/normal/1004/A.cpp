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
  int n, d;
  cin >> n >> d;
  vi X(n);
  for(int i=0; i<n; i++) cin >> X[i];
  int ret = 2;
  for(int i=1; i<n; i++) {
    if(X[i] - X[i-1] >= 2*d) ret += (X[i] - X[i-1] == 2*d) ? 1 : 2;
  }
  cout << ret << "\n";
  return 0;
}