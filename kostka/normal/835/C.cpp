//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int pref[17][107][107];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, q, c;
  cin >> n >> q >> c;
  c++;
  for(int i=0; i<n; i++)
  {
    int x, y, s;
    cin >> x >> y >> s;
    for(int ci=0; ci<c; ci++)
      pref[ci][x][y] += (s+ci)%c;
  }
  for(int ci=0; ci<c; ci++)
  {
    for(int xi=1; xi<107; xi++)
      for(int yi=1; yi<107; yi++)
      {
        pref[ci][xi][yi] += pref[ci][xi-1][yi];
        pref[ci][xi][yi] += pref[ci][xi][yi-1];
        pref[ci][xi][yi] -= pref[ci][xi-1][yi-1];
      }
  }
  while(q--)
  {
    int ti, x1, x2, y1, y2;
    cin >> ti >> x1 >> y1 >> x2 >> y2;
    ti %= c;
    cout << pref[ti][x2][y2] - pref[ti][x1-1][y2] - pref[ti][x2][y1-1] +
            pref[ti][x1-1][y1-1] << "\n";
  }
  return 0;
}