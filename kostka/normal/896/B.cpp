//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())

int wczytaj(int c) {
  int x = rand()%c + 1;
  cin >> x;
  return x;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m, c;
  cin >> n >> m >> c;
  vector <int> tab(n+2);
  tab[0] = 0;
  for(int i=1; i<=n; i++) tab[i] = -1;
  tab[n+1] = c+7;
  while(m--) {
    int x = wczytaj(c);
    if(x <= c/2) {
      for(int i=1; i<=n; i++) {
        if(x < tab[i] or tab[i] == -1) {
          tab[i] = x;
          cout << i << endl;
          break;
        }
      }
    }
    else {
      for(int i=n; i>=1; i--) {
        if(x > tab[i] or tab[i] == -1) {
          tab[i] = x;
          cout << i << endl;
          break;
        }
      }
    }
    bool ok = true;
    for(int i=1; i<=n; i++) {
      if(not(tab[i] != -1 and tab[i-1] <= tab[i] and tab[i] <= tab[i+1]))
        ok = false;
    }
    if(ok)
      break;
  }
  for(int i=1; i<=n; i++) {
    assert(tab[i] != -1 and tab[i-1] <= tab[i] and tab[i] <= tab[i+1]);
  }
  return 0;
}