//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <int> VA;
int n;
vector <int> a, b, s;

long long feed(long long bpieces, long long bonus)
{
  long long happiness = 0;
  for(auto i : VA)
  {
    long long ileb = min(bpieces - (a[i] > b[i] ? bonus : 0), (long long)s[i]);
    ileb = max(0LL, ileb);
    happiness += 1LL * ileb * (b[i] - a[i]);
    bpieces -= ileb;
  }
  return happiness;
}


int main()
{
  ios_base::sync_with_stdio(0);
  int S;
  cin >> n >> S;
  a.resize(n+1);
  b.resize(n+1);
  s.resize(n+1);
  for(int i=1; i<=n; i++)
    cin >> s[i] >> a[i] >> b[i];
  for(int i=1; i<=n; i++)
    VA.push_back(i);
  sort(VA.begin(), VA.end(),
       [&](int p, int q) { return b[p] - a[p] > b[q] - a[q]; });
  long long pieces = 0, pref = 0, zero = 0;
  for(int i=1; i<=n; i++)
  {
    pieces += s[i];
    if(b[i] > a[i])
      pref += s[i];
    zero += 1LL * a[i] * s[i];
  }
  long long pizzas = (pieces + (S-1)) / S;
  long long res = 0;
  for(int x=-5; x<=5; x++)
  {
    long long pizzb = pref / S + x;
    if(0 <= pizzb and pizzb <= pizzas)
      res = max(res, feed(pizzb*S, pizzas*S - pieces));
  }
  cout << zero+res << "\n";
  return 0;
}