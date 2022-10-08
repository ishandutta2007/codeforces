#include "bits/stdc++.h"

using namespace std;

const int MAXN = 107;
int x[MAXN];

int main()
{
  int n;
  cin >> n;
  vector <int> X;
  for(int i=1; i<=n; i++)
  {
    cin >> x[i];
    X.push_back(i);
  }
  sort(X.begin(), X.end(), [&](int a, int b)
  {
    return x[a] < x[b];
  });
  for(int i=0; i<n/2; i++)
    cout << X[i] << " " << X[n-i-1] << "\n";
  return 0;
}