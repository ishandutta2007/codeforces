//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool pal(int a)
{
  string w = "";
  while(a != 0)
  {
    w += ((a%10)+'0');
    a /= 10;
  }
  string x = w;
  reverse(w.begin(), w.end());
  return x==w;
}

const int ST = 2000*1000;
bool pri[ST+7];

void sito(int n)
{
  pri[1] = true;
  for(long long i=2; i*i<=n; i++)
    if(pri[i] == false)
      for(long long j=i*i; j<=n; j+=i)
        pri[j] = true;
}

int main()
{
  long long p, q, e = 0, f = 0;
  sito(ST);
  cin >> p >> q;
  int res = -1;
  for(int i=1; i<=ST; i++)
  {
    if(pal(i))
      e++;
    if(pri[i] == false)
      f++;
    if(q*f <= p*e)
      res = max(res, i);
  }
  if(res != -1)
    cout << res << "\n";
  else
    puts("Palindromic tree is better than splay tree");
  return 0;
}