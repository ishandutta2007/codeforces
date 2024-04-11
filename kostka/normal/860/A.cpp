//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

bool vowel(char x)
{
  return x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x==' ';
}

bool bad(string x)
{
  return !vowel(x[0]) and !vowel(x[1]) and !vowel(x[2]) and
    (x[0] != x[1] or x[0] != x[2] or x[1] != x[2]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  string x;
  cin >> x;
  string res = x.substr(0, 2);
  for(int i=0; i<=(int)x.size()-3; i++)
  {
    if(bad(res.substr(res.size()-2, 2)+x[i+2]))
      res += " ";
    res += x[i+2];
  }
  cout << res << "\n";
  return 0;
}