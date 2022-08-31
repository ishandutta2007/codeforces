#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MaxN = 140;

int a[MaxN][MaxN], b[MaxN][MaxN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main (void)
{
  int n, t; 
  //scanf ("%d %d", &n, &t);
  while (scanf ("%d %d", &n, &t) != EOF)
  {
    int i, j, d, f = 1, x, y, mn = MaxN / 2, mx = MaxN / 2;
    memset (a, 0, sizeof(a));
    memset (b, 0, sizeof(b));
    a[MaxN / 2][MaxN/ 2] = n;
    b[MaxN / 2][MaxN/ 2] = n;
    while (f)
    {
      f = 0;
//      for (i = mn - 1; i <= mx + 1; i++, printf ("\n"))
//        for (j = mn - 1; j <= mx + 1; j++)
//          printf ("%d ", a[i][j]);
      
      for (i = mn; i <= mx; i++)
        for (j = mn; j <= mx; j++)
          if (a[i][j] >= 4)
          {
            b[i][j] -= 4;
            for (d = 0; d < 4; d++)
              b[i+dy[d]][j + dx[d]] += 1;
          }
        
      for (i = mn - 1; i <= mx + 1; i++)
        for (j = mn - 1; j <= mx + 1; j++)
        {
          a[i][j] = b[i][j];
          if (a[i][j] >= 4)
          {
            f = 1;
            if (j > mx)
              mx = j;
          }
        }
      
      for (i = mn; i <= mx; i++)
        for (j = mn; j <= mx; j++)
          if (b[i][j] >= 4)
          {
            a[i][j] -= 4;
            for (d = 0; d < 4; d++)
              a[i+dy[d]][j + dx[d]] += 1;
          }
        
      for (i = mn - 1; i <= mx + 1; i++)
        for (j = mn - 1; j <= mx + 1; j++)
        {
          b[i][j] = a[i][j];
          if (b[i][j] >= 4)
          {
            f = 1;
            if (j > mx)
              mx = j;
          }
        }
     mn = MaxN / 2 - (mx - MaxN / 2);     
    }
      for (i = mn; i <= mx; i++)
        for (j = mn; j <= mx; j++)
          if (a[i][j] >= 4)
          {
            b[i][j] -= 4;
            for (d = 0; d < 4; d++)
              b[i+dy[d]][j + dx[d]] += 1;
          }
        
      for (i = mn - 1; i <= mx + 1; i++)
        for (j = mn - 1; j <= mx + 1; j++)
        {
          a[i][j] = b[i][j];
          if (a[i][j] >= 4)
          {
            f = 1;
            if (j > mx)
              mx = j;
          }
        }
    for (i = 0; i < t; i++)
    {
      scanf ("%d %d", &x, &y);
      if (abs (x) > MaxN / 2 - 2 || abs (y) > MaxN / 2 - 2)
         printf ("%d\n", 0);
      else
         printf ("%d\n", a[x + MaxN / 2][y + MaxN / 2]);
    }
  }
}