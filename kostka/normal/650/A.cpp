//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

#define x first
#define y second

using namespace std;

unordered_map <int, int> X, Y;
map <pair <int, int>, int > M;

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int x, y;
    cin >> x >> y;
    X[x]++;
    Y[y]++;
    M[make_pair(x,y)]++;
  }
  long long res = 0;
  for(auto ele : X)
    res += 1LL*ele.y*(ele.y-1);
  for(auto ele : Y)
    res += 1LL*ele.y*(ele.y-1);
  for(auto ele : M)
    res -= 1LL*ele.y*(ele.y-1);
  cout << res/2 << "\n";
  return 0;
}