//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <pair <int, string> > G[10007];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++)
  {
    string a;
    int b, c;
    cin >> a >> b >> c;
    G[b-1].push_back(make_pair(c,a));
  }
  for(int i=0; i<m; i++)
  {
    sort(G[i].begin(), G[i].end());
    reverse(G[i].begin(), G[i].end());
    if((int)G[i].size() > 2 and G[i][2].first == G[i][1].first)
    {
      cout << "?\n";
      continue;
    }
    cout << G[i][0].second << " " << G[i][1].second << "\n";
  }
  return 0;
}