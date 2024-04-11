//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1007;
char plansza[MAXN][MAXN];
int bombac[MAXN], bombar[MAXN];

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> plansza[i];
  int bomby = 0;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(plansza[i][j] == '*')
      {
        bombac[i]++;
        bombar[j]++;
        bomby++;
      }
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(bombac[i] + bombar[j] - (plansza[i][j] == '*') == bomby)
      {
        cout << "YES\n" << i+1 << " " << j+1 << "\n";
        return 0;
      }
  cout << "NO\n";
  return 0;
}