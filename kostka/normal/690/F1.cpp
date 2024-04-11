#include "bits/stdc++.h"

using namespace std;

const int MAXN = 10007;
vector <int> G[MAXN];

int main()
{
  int n;
  cin >> n;
  for(int i=1; i<n; i++)
  {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  long long res = 0;
  for(int i=1; i<=n; i++)
    res += 1LL * (G[i].size()) * (G[i].size()-1);
  cout << res / 2 << "\n";
}