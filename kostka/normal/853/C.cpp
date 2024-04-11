//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

#define ft first
#define sd second

using namespace std;

const int INF = 1e9+7;

bool cross(int x1, int x2, int x3, int x4)
{
  if(x3 > x2 and x3 > x1 and x4 > x2 and x4 > x1)
    return false;
  if(x3 < x2 and x3 < x1 and x4 < x2 and x4 < x1)
    return false;
  return true;
}

bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  return cross(x1, x2, x3, x4) and cross(y1, y2, y3, y4);
}

const int DRZ = 1<<18;
int drz[DRZ<<1];

void change(int k, int w)
{
  int g = DRZ + k;
  while(g)
  {
    drz[g] += w;
    g /= 2;
  }
}

int sum(int a, int b)
{
  a += DRZ;
  b += DRZ;
  int wynik = 0;
  while(b>a)
  {
    if(a%2)
      wynik += drz[a++];
    if(!(b%2))
      wynik += drz[b--];
    a /= 2;
    b /= 2;
  }
  if(a==b)
    wynik += drz[a];
  return wynik;
}

long long suma(long long x)
{
	return 1LL*x*(x-1)/2;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector <int> tab(n+1);
  vector <pair <int, int> > EVE, yy(q+1);
  vector <long long> ans(q+1);
  for(int i=1; i<=n; i++)
  {
    cin >> tab[i];
    EVE.emplace_back(i, INF);
  }
  for(int i=1; i<=q; i++)
  {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ans[i] = suma(n) - suma(x1-1) - suma(y1-1) - suma(n-x2) - suma(n-y2);
    EVE.emplace_back(x1, i);
    EVE.emplace_back(x2+1, -i);
    yy[i] = {y1, y2};
  }
  sort(EVE.begin(), EVE.end());
  for(auto& e : EVE)
  {
    int miejsce, rodzaj;
    tie(miejsce, rodzaj) = e;
    if(rodzaj == INF)
    {
      change(tab[miejsce], 1);
    }
    else
    {
      int lt, rt;
      tie(lt, rt) = yy[abs(rodzaj)];
      long long ltfra = sum(1, lt-1);
      long long rtfra = sum(rt+1, n);
      if(rodzaj > 0)
        ans[abs(rodzaj)] += suma(ltfra) + suma(rtfra);
      else
        ans[abs(rodzaj)] += suma(lt-1-ltfra) + suma(n-rt-rtfra);
    }
  }
  for(int i=1; i<=q; i++)
    cout << ans[i] << "\n";
  return 0;
}