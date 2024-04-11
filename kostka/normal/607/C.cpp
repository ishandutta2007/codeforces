#include "bits/stdc++.h"

using namespace std;

vector <int> knp(const string &x)
{
  vector <int> kn((int)x.size()+1, -1);
  for(int i=1; i<=(int)x.size(); i++)
  {
      int j = kn[i-1];
      while(j != -1 and x[j] != x[i-1])
        j=kn[j];
      kn[i] = j+1;
   }
   return kn;
}

map <char, char> M;

void backwards(string &x)
{
  for(int i=0; i<(int)x.size(); i++)
    x[i] = M[x[i]];
}

int main()
{
  ios_base::sync_with_stdio();

  M['N'] = 'S';
  M['S'] = 'N';
  M['W'] = 'E';
  M['E'] = 'W';

  int n;
  cin >> n;
  string x, y;
  cin >> x >> y;
  backwards(y);
  reverse(x.begin(), x.end());
  string fin = x+"#"+y;
  vector <int> kn = knp(fin);
  //cout << fin << "\n";
  //cout << kn.back() << "\n";
  puts(kn.back() ? "NO" : "YES");
}