//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int mapgen = 0;
int war[2][3007];
int www[3007];
unordered_map <int, int> M;

void opp(int x)
{
  int nr = 0;
  for(int i=0; i<mapgen; i++)
    war[1][i] = 0;
  for(int i=0; i<mapgen; i++)
  {
    int y = www[i];
    int ilo = war[0][i];
    war[1][M[y^x]] += ilo/2;
    war[1][M[y]] += ilo/2;
    if(ilo % 2)
      war[1][M[(nr % 2 == 0) ? (y^x) : y]]++;
    nr += ilo;
  }
  for(int i=0; i<mapgen; i++)
    war[0][i] = war[1][i];
}

int main()
{
  int n, k, x;
  cin >> n >> k >> x;
  if(k)
  {
    k %= 64;
    //k += 4096;
  }
  vector <int> V(n);
  for(int i=0; i<n; i++)
    cin >> V[i];
  set <int> S;
  for(int i=0; i<n; i++)
  {
    S.insert(V[i]);
    S.insert(V[i]^x);
  }
  for(auto ele : S)
  {
    www[mapgen] = ele;
    M[ele] = mapgen++;
  }
  for(int i=0; i<n; i++)
    war[0][M[V[i]]]++;
  for(int i=0; i<k; i++)
    opp(x);
  vector <int> B;
  for(int i=0; i<mapgen; i++)
    if(war[0][i])
      B.push_back(www[i]);
  cout << B.back() << " " << B[0] << "\n";
  return 0;
}