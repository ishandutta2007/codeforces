//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int main()
{
  ios_base::sync_with_stdio(0);
  string x;
  cin >> x;
  int i = 0;
  while(i<SZ(x) and x[i] == 'a') i++;
  int nra = i;
  while(i<SZ(x) and x[i] == 'b') i++;
  int nrb = i-nra;
  while(i<SZ(x) and x[i] == 'c') i++;
  int nrc = i-nrb-nra;
  cerr << nra << " " << nrb << " " << nrc << "\n";
  if(i != SZ(x) or (nrc != nra and nrc != nrb) or (nra == 0) or (nrb == 0)) cout << "NO\n";
  else cout << "YES\n";
  return 0;
}