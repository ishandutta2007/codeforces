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

// vector <pii> V[2];
// vector <pair <ll, ll> > X[2];
//
// void gen(int x) {
//   int v = SZ(V[x]);
//   for(int mas=0; mas<(1<<v); mas++) {
//     ll liter = 0, koszt = 0;
//     for(int i=0; i<v; i++) {
//       if((1<<i) & mas) {
//         liter += V[x][i].x;
//         koszt += V[x][i].y;
//       }
//     }
//     X[x].emplace_back(liter, koszt);
//   }
//   sort(X[x].begin(), X[x].end());
// }

int main()
{
  ios_base::sync_with_stdio(0);
  int n, L;
  cin >> n >> L;
  vector <int> X(30);
  for(int i=0; i<n; i++) cin >> X[i];
  for(int i=1; i<n; i++) X[i] = min(X[i], 2*X[i-1]);
  for(int i=n; i<30; i++) X[i] = 2*X[i-1];
  ll res = 1LL<<62, tmp = 0;
  for(int i=n-1; i>=0; i--) {
    ll trzeba = (L + (1<<i) - 1) / (1<<i);
    res = min(res, trzeba * X[i] + tmp);
    if(trzeba * (1<<i) > L) trzeba--;
    L -= 1LL * trzeba * (1<<i);
    tmp += 1LL * trzeba * X[i];
  }
  cout << res << "\n";
  return 0;
}