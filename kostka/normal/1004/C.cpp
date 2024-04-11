//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

const int MAXN = 1e5+7;

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi X(n), E;
  for(int i=0; i<n; i++) cin >> X[i];
  vector <bool> W(MAXN);
  reverse(X.begin(), X.end());
  int counter = 0;
  for(int i=0; i<n; i++) {
    if(!W[X[i]]) {
      W[X[i]] = true;
      counter++;
    }
    E.push_back(counter);
  }
  reverse(X.begin(), X.end());
  reverse(E.begin(), E.end());
  W.clear();
  W.resize(MAXN);
  ll ret = 0;
  for(int i=0; i<n-1; i++) {
    if(!W[X[i]]) {
      W[X[i]] = true;
      ret += E[i+1];
    }
  }
  cout << ret << "\n";
  return 0;
}