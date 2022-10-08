#include "bits/stdc++.h"

using namespace std;

const int MAXN = 57;
char tab[MAXN][MAXN];

bool srodek(int x, int y, int px, int kx, int py, int ky)
{
  int e1 = abs(px - x);
  int e2 = abs(kx - x);
  int f1 = abs(py - y);
  int f2 = abs(ky - y);
  if(e1 >= 1 and e2 >= 1 and f1 >= 1 and f2 >= 1)
    return true;
  return false;
}

bool bok(int x, int y, int px, int kx, int py, int ky)
{
  if((x == px or x == kx) xor (y == py or y == ky))
    return true;
  return false;
}

bool rog(int x, int y, int px, int kx, int py, int ky)
{
  if((x == px or x == kx) and (y == py or y == ky))
    return true;
  return false;
}

bool check()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> tab[i];
  int px = n+7, kx = -1,
    py = n+7, ky = -1;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(tab[i][j] != '0')
      {
        px = min(px, i);
        kx = max(kx, i);
        py = min(py, j);
        ky = max(ky, j);
      }
  cerr << px << " " << kx << " " << py << " " << ky << "\n";
  if(kx == -1)
    return false;
  for(int i=px; i<=kx; i++)
    for(int j=py; j<=ky; j++)
    {
      cerr << i << " " << j << " " << tab[i][j] << "\n";
      switch(tab[i][j])
      {
        case '4':
          if(not(srodek(i,j,px,kx,py,ky)))
            return false;
          continue;
        case '2':
          if(not(bok(i,j,px,kx,py,ky)))
            return false;
          continue;
        case '1':
          if(not(rog(i,j,px,kx,py,ky)))
            return false;
          continue;
        default:
          return false;
      }
    }
  return true;
}

int main()
{
  puts(check() ? "Yes" : "No");
}