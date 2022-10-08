#include "bits/stdc++.h"

using namespace std;

unordered_set<int> X, Y;

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++)
  {
    X.insert(i);
    Y.insert(i);
  }
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    X.erase(a);
    Y.erase(b);
    long long missing = 1LL * (long long)X.size() * (long long)Y.size();
    cout << missing << "\n";
  }
}