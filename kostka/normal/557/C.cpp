//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int l[MAXN], w[MAXN], ile[207];
vector <int> wys[MAXN];

bool cmp(int a, int b)
{
  return w[a] < w[b];
}

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> l[i];
    wys[l[i]].push_back(i);
  }
  for(int i=0; i<n; i++)
  {
    cin >> w[i];
    ile[w[i]]++;
  }
  int wyc = 0;
  long long pra = 0;
  long long res = 1LL<<60;
  for(int i=100000; i>=1; i--)
  {
    sort(wys[i].begin(), wys[i].end(), cmp);
    int ww = wys[i].size();
    //cerr << i << ": " << wyc << "\n";
    int e = max(0,n-wyc-(2*ww-1));
    //cerr << e << "\n";
    int alr = 0;
    long long tmp = 0;
    for(auto ele : wys[i])
      ile[w[ele]]--;
    for(int j=1; j<=200; j++)
    {
      int mozna = min(ile[j], e-alr);
      //cerr << "m: " << mozna << " " << ile[j] << " " << e << " " << alr << "\n";
      alr += mozna;
      tmp += mozna*j;
      if(alr == e)
        break;
    }
    if(alr == e)
    {
      //cerr << i << " " << pra << " " << tmp << "\n";
      res = min(res, pra+tmp);
    }
    for(auto ele : wys[i])
    {
      wyc++;
      pra += w[ele];
    }
  }
  cout << res << "\n";
  return 0;
}