//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define pii pair <int, int>

const int MAXN = 1007;

int tab[MAXN][MAXN];
int ile[MAXN][MAXN];
pii rep[MAXN][MAXN];

vector <pii> X;

pii find(pii a)
{
  if(rep[a.first][a.second] == a)
    return a;
  return rep[a.first][a.second] = find(rep[a.first][a.second]);
}

void unia(pii a, pii b)
{
  pii fa = find(a);
  pii fb = find(b);
  if(fa == fb)
    return;
  if(ile[fa.first][fa.second] > ile[fb.first][fb.second])
    swap(fa, fb);
  ile[fb.first][fb.second] += ile[fa.first][fa.second];
  rep[fa.first][fa.second] = fb;
}

int n, m;
int dx[] = {-1,1,0,0},
    dy[] = {0,0,-1,1};

bool onboard(int a, int b)
{
  return 0 <= a and a < n and 0 <= b and b < m;
}

void merge(pii x)
{
  int a = x.first, b = x.second;
  for(int i=0; i<4; i++)
  {
    int na = a+dx[i], nb = b+dy[i];
    if(onboard(na,nb) and tab[na][nb] >= tab[a][b])
      unia(x, make_pair(na,nb));
  }
}

int gk, gv;

bool odw[MAXN][MAXN];

void dfs(int a, int b)
{
  gk--;
  odw[a][b] = true;
  if(gk == 0)
    return;
  for(int i=0; i<4; i++)
  {
    int na = a+dx[i], nb = b+dy[i];
    if(onboard(na,nb) and tab[na][nb] >= gv and odw[na][nb] == false and gk)
      dfs(na,nb);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  long long k;
  cin >> k;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> tab[i][j];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      X.emplace_back(i,j);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      rep[i][j] = make_pair(i,j);
      ile[i][j] = 1;
    }
  sort(X.begin(), X.end(), [](pair <int, int> a, pair <int, int> b){ return tab[a.first][a.second] < tab[b.first][b.second]; });
  reverse(X.begin(), X.end());
  for(int i=0; i<(int)X.size(); i++)
  {
    int val = tab[X[i].first][X[i].second];
    merge(X[i]);
    int j = i;
    while(j+1 < (int)X.size() and tab[X[j+1].first][X[j+1].second] == val)
      merge(X[++j]);
    if(not(k % val))
    {
      long long ocz = k/val;
      for(int q=i; q<=j; q++)
      {
        pii fx = find(X[q]);
        //cerr << val << " " << ocz << "\n";
        //cerr << ile[fx.first][fx.second] << "\n";
        if(ile[fx.first][fx.second] >= ocz)
        {
          cout << "YES\n";
          gk = ocz;
          gv = val;
          dfs(X[q].first,X[q].second);
          for(int e=0; e<n; e++)
          {
            for(int f=0; f<m; f++)
              cout << (odw[e][f] ? val : 0) << " ";
            cout << "\n";
          }
          return 0;
        }

      }
    }
    i = j;
  }
  cout << "NO\n";
  return 0;
}