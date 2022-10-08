//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define ft first
#define sd second

const int MAXN = 1e5 + 7;
const int MAXD = 1e6 + 7;
const int INF = 1e9;
const long long INFLL = 1LL<<60;

vector <pair <int, pair <int, int> > > A, D;
int koszt[MAXN];
long long przylot[MAXD], odlot[MAXD];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=0; i<m; i++)
  {
    int d, f, t, c;
    cin >> d >> f >> t >> c;
    if(t == 0)
      A.push_back(make_pair(d, make_pair(f,c)));
    else
      D.push_back(make_pair(d, make_pair(t,c)));
  }
  sort(A.begin(), A.end());
  sort(D.begin(), D.end());
  reverse(D.begin(), D.end());
  for(int i=1; i<=n; i++)
    koszt[i] = -1;
  int it = 0, ok = 0;
  long long suma = 0;
  for(int i=1; i<MAXD; i++)
  {
    while(it < (int)A.size() and A[it].ft == i)
    {
      if(koszt[A[it].sd.ft] == -1)
      {
        koszt[A[it].sd.ft] = A[it].sd.sd;
        suma += koszt[A[it].sd.ft];
        ok++;
      }
      if(koszt[A[it].sd.ft] > A[it].sd.sd)
      {
        suma -= koszt[A[it].sd.ft];
        koszt[A[it].sd.ft] = A[it].sd.sd;
        suma += koszt[A[it].sd.ft];
      }
      it++;
    }
    przylot[i] = (ok == n) ? suma : INFLL;
  }
  it = 0;
  ok = 0;
  suma = 0;
  for(int i=1; i<=n; i++)
    koszt[i] = -1;
  for(int i=MAXD-1; i>=1; i--)
  {
    while(it < (int)D.size() and D[it].ft == i)
    {
      if(koszt[D[it].sd.ft] == -1)
      {
        koszt[D[it].sd.ft] = D[it].sd.sd;
        suma += koszt[D[it].sd.ft];
        ok++;
      }
      if(koszt[D[it].sd.ft] > D[it].sd.sd)
      {
        suma -= koszt[D[it].sd.ft];
        koszt[D[it].sd.ft] = D[it].sd.sd;
        suma += koszt[D[it].sd.ft];
      }
      it++;
    }
    odlot[i] = (ok == n) ? suma : INFLL;
  }
  for(int i=MAXD-2; i>=1; i--)
    odlot[i] = min(odlot[i], odlot[i+1]);
  for(int i=2; i<MAXD; i++)
    przylot[i] = min(przylot[i], przylot[i-1]);
  long long res = INFLL;
  for(int i=1; i<MAXD-k-2; i++)
    res = min(res, przylot[i] + odlot[i+k+1]);
  if(res >= INFLL)
    res = -1;
  cout << res << "\n";
  return 0;
}