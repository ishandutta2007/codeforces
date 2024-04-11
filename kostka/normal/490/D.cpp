#include "bits/stdc++.h"

using namespace std;

map <pair <int, int>, int> M, M2;
map <long long, int> O, O2;
map <long long, pair <int, int> > R, R2;

long long www = 1LL<<60, roz = 1LL<<60;

void go(int p, int q)
{
  queue <pair <int, int>> Q;
  Q.push({p,q});
  M[{p,q}] = 0;
  while(!Q.empty())
  {
    int a = Q.front().first, b = Q.front().second, k = M[Q.front()];
    //cerr << "X" << a << " " << b << "\n";
    long long res = 1LL*a*b;
    if(O.find(res) != O.end())
    {
      O[res] = min(O[res], k);
      R[res] = Q.front();
    }
    else
    {
      O[res] = k;
      R[res] = Q.front();
    }
    if(a%2==0)
    {
      if(M.find({a/2,b})==M.end())
      {
        Q.push({a/2,b});
        M[{a/2,b}] = k+1;
      }
    }
    if(b%2==0)
    {
      if(M.find({a,b/2})==M.end())
      {
        Q.push({a,b/2});
        M[{a,b/2}] = k+1;
      }
    }
    if(a%3==0)
    {
      if(M.find({2*a/3,b})==M.end())
      {
        Q.push({2*a/3,b});
        M[{2*a/3,b}] = k+1;
      }
    }
    if(b%3==0)
    {
      if(M.find({a,2*b/3})==M.end())
      {
        Q.push({a,2*b/3});
        M[{a,2*b/3}] = k+1;
      }
    }
    Q.pop();
  }
}

void secondgo(int p, int q)
{
  queue <pair <int, int>> Q;
  Q.push({p,q});
  M[{p,q}] = 0;
  while(!Q.empty())
    {
      int a = Q.front().first, b = Q.front().second, k = M2[Q.front()];
      long long res = 1LL*a*b;
      if(O2.find(res) != O2.end())
        {
          O2[res] = min(O2[res], k);
          R2[res] = Q.front();
        }
        else
          {
            O2[res] = k;
            R2[res] = Q.front();
          }
          if(O.find(res) != O.end())
          {
            if(www > O[res] + O2[res])
            {
              www = O[res] + O2[res];
              roz = res;
            }
          }
          if(a%2==0)
            {
              if(M2.find({a/2,b})==M2.end())
                {
                  Q.push({a/2,b});
                  M2[{a/2,b}] = k+1;
                }
              }
              if(b%2==0)
                {
                  if(M2.find({a,b/2})==M2.end())
                    {
                      Q.push({a,b/2});
                      M2[{a,b/2}] = k+1;
                    }
                  }
                  if(a%3==0)
                    {
                      if(M2.find({2*a/3,b})==M2.end())
                        {
                          Q.push({2*a/3,b});
                          M2[{2*a/3,b}] = k+1;
                        }
                      }
                      if(b%3==0)
                        {
                          if(M2.find({a,2*b/3})==M2.end())
                            {
                              Q.push({a,2*b/3});
                              M2[{a,2*b/3}] = k+1;
                            }
                          }
                          Q.pop();
                        }
                      }

int main()
{
  ios_base::sync_with_stdio(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  go(a,b);
  secondgo(c,d);


  if(www==1LL<<60)
    puts("-1");
  else
  {
    cout << www << "\n";
    cout << R[roz].first << " " << R[roz].second << "\n";
    cout << R2[roz].first << " " << R2[roz].second << "\n";
  }
}