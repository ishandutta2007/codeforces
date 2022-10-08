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
  int n, m;
  cin >> n >> m;
  vi ans(n);
  vector <tuple <int, int, int> > E(m);
  for(int i=0; i<m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    E[i] = make_tuple(x, y, z);
    ans[y] = m+1;
  }
  vi F(m);
  for(int i=0; i<m; i++) F[i] = i;
  sort(F.begin(), F.end(), [&](const int& a, const int& b) {
    return get<0>(E[a]) < get<0>(E[b]);
  });
  set <pair <int, int> > P;
  int ix = 0;
  for(int day=0; day<n; day++) {
    cerr << "DAY " << day << "\n";
    while(ix < SZ(F) and day == get<0>(E[F[ix]])) {
      P.emplace(get<1>(E[F[ix]]), F[ix]);
      ix++;
    }
    for(auto p : P) {
      cerr << get<1>(p) << "\n";
    }
    if(ans[day] == 0 and !P.empty()) {
      int fin, jx;
      tie(fin, jx) = *P.begin();
      if(fin <= day) {
        cout << "-1\n";
        return 0;
      }
      get<2>(E[jx])--;
      if(get<2>(E[jx]) == 0) {
        P.erase(P.begin());
      }
      cerr << "UCZE" << jx << "\n";
      ans[day] = jx+1;
    }
  }
  for(int i=0; i<m; i++) {
    if(get<2>(E[i]) != 0) {
      cout << "-1\n";
      return 0;
    }
  }
  for(auto a : ans) cout << a << " ";
  cout << "\n";
  return 0;
}