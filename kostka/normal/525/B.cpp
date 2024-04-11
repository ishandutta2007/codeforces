//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int ch[200007];

int main()
{
  string s;
  cin >> s;
  int m;
  cin >> m;
  while(m--)
  {
    int a;
    cin >> a;
    ch[a]++;
  }
  int ss = s.size();
  for(int i=1; i<ss; i++)
    ch[i] += ch[i-1];
  for(int i=0; i<ss; i++)
  {
    if(ch[min(i+1,ss-i)]%2 == 0)
      cout << s[i];
    else
      cout << s[ss-i-1];
  }
  cout << "\n";
  return 0;
}