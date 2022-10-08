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
#define double long double

int main()
{
  ios_base::sync_with_stdio(0);
  double k, d, t;
  cin >> k >> d >> t;
  double bede = ceil(k/d)*d;
  double ilegotuje = k+(bede-k)/2.0;
  long long okresy = floor(t/ilegotuje);
  double ans = bede*okresy;
  double pozostaly = t - ilegotuje*okresy;
  cout << fixed << setprecision(20);
  if(pozostaly <= k) {
    cout << ans + pozostaly << "\n";
  } else {
    cout << ans + k + 2*(pozostaly-k) << "\n";
  }


  return 0;
}