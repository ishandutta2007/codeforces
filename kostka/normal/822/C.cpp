//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
vector <pair <int, int> > X[MAXN];

const int INF = 2e9+7;
int res = INF;

void check(int a, int b)
{
  if(X[a].empty() or X[b].empty())
    return;
  map <int, int> L, R;
  for(auto aa : X[a])
  {
    int li, ci;
    tie(li, ci) = aa;
    int ri = li + a - 1;
    ri++;
    li--;
    if(L.find(ri) == L.end())
      L[ri] = ci;
    else
      L[ri] = min(L[ri], ci);
    if(R.find(li) == R.end())
      R[li] = ci;
    else
      R[li] = min(R[li], ci);
  }
  int value = -1;
  for(auto ele : L)
  {
    if(value == -1)
      value = ele.second;
    else
      value = min(ele.second, value);
    L[ele.first] = value;
  }
  value = -1;
  for(auto it = R.rbegin(); it != R.rend(); it++)
  {
    auto ele = (*it);
    if(value == -1)
      value = ele.second;
    else
      value = min(ele.second, value);
    R[ele.first] = value;
  }
  // cerr << a << "\n";
  // for(auto ele : L)
  //   cerr << "L" << ele.first << " " << ele.second << "\n";
  // for(auto ele : R)
  //   cerr << "R" << ele.first << " " << ele.second << "\n";
  for(auto bb : X[b])
  {
    int li, ci;
    tie(li, ci) = bb;
    int ri = li + b - 1;
    auto it = R.lower_bound(ri);
    if(it != R.end())
      res = min(res, ci + (*it).second);
    auto jt = L.upper_bound(li);
    if(jt != L.begin())
    {
      jt--;
      res = min(res, ci + (*jt).second);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  for(int i=0; i<n; i++)
  {
    int li, ri, ci;
    cin >> li >> ri >> ci;
    X[ri-li+1].push_back(make_pair(li, ci));
  }
  for(int i=1; i<=x/2; i++)
    check(i, x-i);
  if(res == INF)
    res = -1;
  cout << res << "\n";
  return 0;
}