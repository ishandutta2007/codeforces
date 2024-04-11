#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1000007;
int a[MAXN], prefxor[MAXN], prv[MAXN], res[MAXN];

const int DRZ = 1<<20;
int drz[2*DRZ];

#define ft first
#define sd second

void point(int v, int x)
{
  v += DRZ;
  while(v)
  {
    drz[v] ^= x;
    v /= 2;
  }
}

int segment(int a, int b)
{
  a += DRZ;
  b += DRZ;
  int res = 0;
  while(a < b)
  {
    if(a%2)
      res ^= drz[a++];
    if(!(b%2))
      res ^= drz[b--];
    a /= 2;
    b /= 2;
  }
  if(a == b)
    res ^= drz[a];
  return res;
}

vector <int> X[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++)
    cin >> a[i];
  for(int i=1; i<=n; i++)
    prefxor[i] = prefxor[i-1] ^ a[i];
  unordered_map <int, int> M;
  int mapgen = 0;
  for(int i=1; i<=n; i++)
  {
    if(M.find(a[i]) == M.end())
      M[a[i]] = mapgen++;
    X[M[a[i]]].push_back(i);
  }
  for(int i=0; i<mapgen; i++)
  {
    for(int j=1; j<(int)X[i].size(); j++)
      prv[X[i][j]] = X[i][j-1];
    prv[X[i][0]] = 0;
  }
  int q;
  cin >> q;
  vector <pair <int, int> > Q;
  vector <int> QN;
  for(int i=0; i<q; i++)
  {
    int a, b;
    cin >> a >> b;
    res[i] = prefxor[b] ^ prefxor[a-1];
    Q.emplace_back(a,b);
    QN.emplace_back(i);
  }
  auto cmp = [&Q](int a, int b)
  {
    if(Q[a].sd == Q[b].sd)
      return a < b;
    return Q[a].sd < Q[b].sd;
  };
  sort(QN.begin(), QN.end(), cmp);
  int ptr = 0;
  for(int i=1; i<=n; i++)
  {
    point(i, a[i]);
    point(prv[i], a[i]);
    while(ptr < (int)QN.size() and Q[QN[ptr]].sd == i)
    {
      int nr = QN[ptr];
      int p, k;
      tie(p,k) = Q[nr];
      res[nr] ^= segment(p,k);
      ptr++;
    }
  }
  for(int i=0; i<q; i++)
    cout << res[i] << "\n";
}