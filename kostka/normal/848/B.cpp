//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
pair <int, int> res[MAXN];
int ori[MAXN], wy[MAXN], wstart[MAXN], odp[MAXN];
vector <int> X[2][2*MAXN];

bool cmp(const int& a, const int& b)
{
  return wstart[a] < wstart[b];
}

int main()
{
  ios_base::sync_with_stdio(0);
  int x, y, n;
  cin >> n >> x >> y;
  for(int i=0; i<n; i++)
  {
    int wx;
    cin >> wx >> wy[i] >> wstart[i];
    if(wx == 1)
      res[i] = make_pair(wy[i], y);
    else
      res[i] = make_pair(x, wy[i]);
    //cerr << 2-wx << " " << wstart - wy + 100000 << "\n";
    X[2-wx][wstart[i] - wy[i] + 100000].push_back(i);
    odp[i] = i;
  }
  for(int i=0; i<200000; i++)
  {
    if(X[0][i].empty() or X[1][i].empty())
      continue;
    sort(X[0][i].begin(), X[0][i].end(), cmp);
    sort(X[1][i].begin(), X[1][i].end(), cmp);
    reverse(X[1][i].begin(), X[1][i].end());
    vector <int> W;
    for(auto e : X[0][i])
      W.push_back(e);
    for(auto e : X[1][i])
      W.push_back(e);
    int nr = 0;
    for(auto k : X[1][i])
      odp[k] = W[nr++];
    for(auto k : X[0][i])
      odp[k] = W[nr++];
  }
  for(int i=0; i<n; i++)
    cout << res[odp[i]].first << " " << res[odp[i]].second << "\n";
  return 0;
}