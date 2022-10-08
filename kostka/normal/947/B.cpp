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
  vector <int> V(n+7), T(n+7), pelne(n+7);
  vector <ll> ST(n+7), resztki(n+7);
  for(int i=1; i<=n; i++) {
    cin >> V[i];
  }
  for(int i=1; i<=n; i++) {
    cin >> T[i];
  }
  T[n+1] = 1e9;
  for(int i=1; i<=n+1; i++) {
    ST[i] = ST[i-1] + T[i];
  }
  for(int i=1; i<=n; i++) {
    int a = i-1, b = n+1;
    while(b - a > 1) {
      int m = (a+b)/2;
      if(ST[m] - ST[i-1] <= V[i]) a = m;
      else b = m;
    }
    // cerr << i << " " << a << "\n";
    pelne[i]++;
    pelne[a+1]--;
    resztki[a+1] += V[i] - (ST[a] - ST[i-1]);
    // cerr << "R" << resztki[a+1] << "\n";
  }
  for(int i=1; i<=n; i++) pelne[i] += pelne[i-1];
  for(int i=1; i<=n; i++) cout << 1LL * pelne[i] * T[i] + resztki[i] << " ";
  cout << "\n";
  return 0;
}