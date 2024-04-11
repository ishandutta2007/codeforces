//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int e;

vector <vector <int> > tab;

const int MAXN = 1000007;
int rep[MAXN];
int ile[MAXN];
int sto[MAXN];
int res[MAXN];
vector <int> G[MAXN];

bool cmpx(int a, int b)
{
  return tab[e][a] < tab[e][b];
}

bool cmpy(int a, int b)
{
  return tab[a][e] < tab[b][e];
}

int find(int x)
{
  if(rep[x] == x)
    return x;
  return rep[x] = find(rep[x]);
}

void unia(int a, int b)
{
  int fa = find(a);
  int fb = find(b);
  if(ile[fa] < ile[fb])
    swap(fa, fb);
  ile[fa] += ile[fb];
  rep[fb] = fa;
}

void krawedz(int a, int b)
{
  //cerr << "KRA " << a << " " << b << "\n";
  int fa = find(a);
  int fb = find(b);
  G[fa].push_back(fb);
  sto[fb]++;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      rep[i*m+j] = i*m+j;
      ile[i*m+j] = 1;
    }
  vector <vector <int> > X(n);
  vector <vector <int> > Y(m);
  tab.resize(n);
  for(int i=0; i<n; i++)
    tab[i].resize(m);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
      cin >> tab[i][j];
      X[i].push_back(j);
      Y[j].push_back(i);
    }
  for(int i=0; i<n; i++)
  {
    e = i;
    sort(X[i].begin(), X[i].end(), cmpx);
    for(int j=1; j<(int)X[i].size(); j++)
      if(tab[i][X[i][j]] == tab[i][X[i][j-1]])
        unia(i*m + X[i][j], i*m + X[i][j-1]);
  }
  for(int i=0; i<m; i++)
  {
    e = i;
    sort(Y[i].begin(), Y[i].end(), cmpy);
    for(int j=1; j<(int)Y[i].size(); j++)
      if(tab[Y[i][j]][i] == tab[Y[i][j-1]][i])
        unia(Y[i][j]*m + i, Y[i][j-1]*m + i);
  }
  //cerr << "DONE\n";
  for(int i=0; i<n; i++)
  {
    for(int j=1; j<(int)X[i].size(); j++)
      if(tab[i][X[i][j]] != tab[i][X[i][j-1]])
        krawedz(i*m + X[i][j-1], i*m + X[i][j]);
  }
  //cerr << "??\n";
  for(int i=0; i<m; i++)
  {
    for(int j=1; j<(int)Y[i].size(); j++)
      if(tab[Y[i][j-1]][i] != tab[Y[i][j]][i])
        krawedz(Y[i][j-1]*m + i, Y[i][j]*m + i);
  }
  queue <int> Q;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(sto[i*m+j] == 0)
        Q.push(i*m+j);

  while(!Q.empty())
  {
    int v = Q.front();
    Q.pop();

    for(auto ele : G[v])
    {
      res[ele] = max(res[ele], res[v]+1);
      sto[ele]--;
      if(sto[ele] == 0)
        Q.push(ele);
    }
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<m; j++)
      cout << res[find(i*m+j)]+1 << " ";
    cout << "\n";
  }
  return 0;
}