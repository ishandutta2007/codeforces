//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  string x;
  cin >> x;
  vector <int> ile(4);
  map <char, int> M;
  for(int i=0; i<(int)x.size(); i++)
  {
    if(x[i] == '!')
      ile[i%4]++;
    else
      M[x[i]] = i%4;
  }
  cout << ile[M['R']] << " " << ile[M['B']] << " " << ile[M['Y']] << " " << ile[M['G']] << "\n";
  return 0;
}