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

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector <pii> X;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    X.emplace_back(x, i+1);
  }
  sort(X.begin(), X.end());
  reverse(X.begin(), X.end());
  vector <int> Y;
  ll ret = 0;
  for(int i=0; i<k; i++) {
    ret += X[i].x;
    Y.push_back(X[i].y);
  }
  sort(Y.begin(), Y.end());
  Y.push_back(n+1);
  Y[0] = 1;
  cout << ret << "\n";
  for(int i=0; i<k; i++) {
    cout << Y[i+1] - Y[i] << " ";
  }
  cout << "\n";
  return 0;
}