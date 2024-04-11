//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int N = 500;

struct matrix
{
  bitset<N> m[N];
  matrix()
  {

  }
};

matrix operator * ( const matrix& m1, const matrix& m2 )
{
  int n = N;
  matrix r = matrix();
  matrix tmp = matrix();
  for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
                  tmp.m[j].set(i, m2.m[i].test(j));
          }
  }
  for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
                  r.m[i].set(j, (m1.m[i] & tmp.m[j]).any());
          }
  }
  return r;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector <matrix> M[2];
  M[0].push_back(matrix());
  M[1].push_back(matrix());
  for(int i=0; i<m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    M[c][0].m[a-1][b-1] = 1;
  }
  for(int i=1; i<=60; i++)
  {
    M[0].push_back(M[0][i-1] * M[1][i-1]);
    M[1].push_back(M[1][i-1] * M[0][i-1]);
  }
  matrix C = matrix();
  for(int i=0; i<n; i++)
    C.m[i][i] = 1;
  int str = 0;
  long long res = 0;
  for(int i=60; i>=0; i--)
  {
    matrix E = C * M[str][i];
    bool ok = false;
    for(int t=0; t<n; t++)
      if(E.m[0][t])
        ok = true;
    if(ok)
    {
      C = E;
      str = 1-str;
      res |= (1LL << i);
    }
  }
  if(res > 1LL*1000*1000*1000*1000*1000*1000)
    res = -1;
  cout << res << "\n";
  return 0;
}