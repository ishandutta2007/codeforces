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
  int n;
  cin >> n;
  ll res = 0;
  vector <pii> X;
  for(int i=0; i<n; i++) {
    pii sh = {0, 0};
    string x;
    cin >> x;
    for(auto c : x) {
      if(c == 's') sh.x++;
      else {
        res += sh.x;
        sh.y++;
      }
    }
    X.push_back(sh);
  }
  sort(X.begin(), X.end(), [&](const pii& a, const pii& b){
    return 1LL * a.x * b.y > 1LL * a.y * b.x;
  });
  ll ss = 0;
  for(int i=0; i<n; i++) {
    res += ss * X[i].y;
    ss += X[i].x;
  }
  cout << res << "\n";
  return 0;
}