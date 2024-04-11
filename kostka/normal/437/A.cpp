#include "bits/stdc++.h"

using namespace std;

string a[4];
int len[4];

bool male(int a)
{
  for(int i=0; i<4; i++)
    if(i!=a)
      if(len[a] > len[i]/2)
        return false;
  return true;
}

bool duze(int a)
{
  for(int i=0; i<4; i++)
    if(i!=a)
      if(len[a]/2 < len[i])
        return false;
  return true;
}

int main()
{       
  for(int i=0; i<4; i++)
    cin >> a[i];
  for(int i=0; i<4; i++)
    len[i] = a[i].size()-2;
  vector <char> X;
  for(int i=0; i<4; i++)
  {
    if(male(i) || duze(i))
      X.push_back(char('A'+i));
  }
  if(X.size() != 1)
    cout << "C";
  else
    cout << X[0];
}