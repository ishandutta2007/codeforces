//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

unordered_map <string, int> M;
vector <string> WHAT;
vector <int> LEFT, RIGHT;

int check(int v, int place)
{
  vector <int> V = {v};
  for(int i=0; i<(int)WHAT.size(); i++)
  {
    if(WHAT[i][0] == '0' or WHAT[i][0] == '1')
        V.push_back(WHAT[i][place]-'0');
    else
    {
      int left = V[LEFT[i]], right = V[RIGHT[i]];
      if(WHAT[i] == "AND")
        V.push_back(left & right);
      if(WHAT[i] == "OR")
        V.push_back(left | right);
      if(WHAT[i] == "XOR")
        V.push_back(left ^ right);
    }
  }
  int sum = 0;
  for(int i=1; i<(int)V.size(); i++)
    sum += V[i];
  return sum;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  LEFT.resize(n);
  RIGHT.resize(n);
  for(int i=0; i<n; i++)
  {
    string var, bs, left, op, right;
    cin >> var >> bs >> left;
    M[var] = i+1;
    if(not(left[0] == '0' or left[0] == '1'))
    {
      cin >> op >> right;
      int noleft = (left == "?") ? 0 : M[left];
      int noright = (right == "?") ? 0 : M[right];
      WHAT.push_back(op);
      LEFT[i] = noleft;
      RIGHT[i] = noright;
    }
    else
    {
      WHAT.push_back(left);
    }
  }

  string resmin = "";
  string resmax = "";
  for(int i=0; i<m; i++)
  {
      int w0 = check(0, i);
      int w1 = check(1, i);
      if(w1 > w0)
          resmax += "1";
      else
          resmax += "0";
      if(w1 < w0)
          resmin += "1";
      else
          resmin += "0";
  }
  cout << resmin << "\n" << resmax << "\n";
  return 0;
}