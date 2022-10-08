#include "bits/stdc++.h"

using namespace std;

multiset <int> S;

int main()
{
  int tab[6];
  for(int i=0; i<6; i++)
    scanf("%d", &tab[i]);
  for(int i=0; i<6; i++)
    S.insert(tab[i]);
  for(int i=0; i<6; i++)
  {
    if(S.count(tab[i])>=4)
    {
      S.erase(S.find(tab[i]));
      S.erase(S.find(tab[i]));
      S.erase(S.find(tab[i]));
      S.erase(S.find(tab[i]));      
      if(*S.begin() != *S.rbegin())
        puts("Bear");
      else
        puts("Elephant");
      return 0;
    }
  }
  puts("Alien");
  return 0;
}