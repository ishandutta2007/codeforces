//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int Z = 5;
const int MAXN = 120;

int czas[MAXN][Z];
int solvedby[Z];
int n;

vector <int> T;
vector <int> V = {500, 1000, 1500, 2000, 2500, 3000};
vector <double> F = {1, 1./2, 1./4, 1./8, 1./16, 1./32, -1};

const long long INF = 1e9+8;
long long res = INF;

bool check(long long m)
{
  for(int i=0; i<Z; i++)
  {
    if(not((solvedby[i]) <= F[T[i]] * (m+n) and (solvedby[i] + m > F[T[i]+1] * (m+n))))
      return false;
  }
  return true;
}

long long need()
{
  long long a = -1, b = 1e9;
  while(b - a > 1)
  {
    long long m = (a+b)/2;
    if(check(m))
      b = m;
    else
      a = m;
  }
  for(int i=0; i<Z; i++)
    if(czas[0][i] == -1)
      if(not((solvedby[i]) <= F[T[i]] * (b+n) and (solvedby[i] > F[T[i]+1] * (b+n))))
        return INF;
  return b;
}

int score(int timer, int value)
{
  if(timer == -1)
    return 0;
  return V[value] - V[value] * timer / 250;
}

void check()
{
  int scorea = 0, scoreb = 0;
  for(int i=0; i<Z; i++)
  {
    scorea += score(czas[0][i], T[i]);
    scoreb += score(czas[1][i], T[i]);
    //if(czas[0][i] == -1 and 1.0*solvedby[i]/n < F[T[i]+1])
    //  return;
  }
  //cerr << scorea << " " << scoreb << "\n";
  if(scorea > scoreb)
  {
    res = min(res, need());
    //if(need() < 3)
    //{
    //  for(int i=0; i<Z; i++)
    //    cerr << "Z" << i << ": " << T[i] <<" " <<  1.0*solvedby[i]/n << " " << F[T[i]+1] << "\n";
    //  cerr << "\n";
    //}
  }
  //for(int i=0; i<5; i++)
  //  cerr << i << ": " << check(i) << "\n";
  //cerr << "R" << res << "\n";
}

void go(int a)
{
  if(a == Z)
  {
    check();
    return;
  }
  for(int i=0; i<6; i++)
  {
    T.push_back(i);
    go(a+1);
    T.pop_back();
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<Z; j++)
    {
      cin >> czas[i][j];
      if(czas[i][j] != -1)
        solvedby[j]++;
    }
  }
  //T = {0, 2, 1, 2, 5};
  //check();
  //return 0;
  go(0);
  if(res == INF)
    res = -1;
  cout << res << "\n";
  return 0;
}