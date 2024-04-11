//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <vector <int> > rows;

void preprocessing()
{
  vector <int> pos;
  for(int i=0; i<4; i++)
  {
    pos = {4*i,4*i+1,4*i+2,4*i+3};
    rows.push_back(pos);
    pos = {i,i+4,i+8,i+12};
    rows.push_back(pos);
  }
  pos = {0, 5, 10, 15};
  rows.push_back(pos);
  pos = {3, 6, 9, 12};
  rows.push_back(pos);
  pos = {1, 6, 11};
  rows.push_back(pos);
  pos = {4, 9, 14};
  rows.push_back(pos);
  pos = {2, 5, 8};
  rows.push_back(pos);
  pos = {7, 10, 13};
  rows.push_back(pos);
}

string x[4];

bool check()
{
  for(auto row : rows)
  {
    int ile = 0;
    for(auto pos : row)
    {
      if(x[pos/4][pos%4] == 'x')
        ile++;
      else
        ile = 0;
      if(ile == 3)
        return true;
    }
  }
  return false;
}

int main()
{
  preprocessing();
  for(int i=0; i<4; i++)
    cin >> x[i];
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
      if(x[i][j] == '.')
      {
        x[i][j] = 'x';
        if(check())
        {
          puts("YES");
          return 0;
        }
        x[i][j] = '.';
      }
  puts("NO");
  return 0;
}