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

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
  return make_pair(get<1>(a), get<2>(a)) < make_pair(get<1>(b), get<2>(b));
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, T;
  cin >> n >> T;
  vector <tuple <int, int, int> > X;
  for(int i=0; i<n; i++) {
    int a, t;
    cin >> a >> t;
    X.emplace_back(a,t,i);
  }
  sort(X.begin(), X.end());
  reverse(X.begin(), X.end());
  multiset <int> S;
  ll czas = 0;
  int res = 0;
  for(int i=0; i<n; i++) {
    int ile, cz;
    tie(ile, cz, ignore) = X[i];
    czas += cz;
    S.emplace(cz);

    while(ile < SZ(S) or czas > T) {
      auto it = S.end(); it--;
      czas -= (*it);
      S.erase(it);
    }

    res = max(res, SZ(S));
  }
  cout << res << "\n";
  cout << res << "\n";
  sort(X.begin(), X.end(), cmp);
  vector <int> ps;
  for(int i=0; i<n; i++) {
    if(SZ(ps) < res and get<0>(X[i]) >= res) ps.push_back(get<2>(X[i]) + 1);
  }
  sort(ps.begin(), ps.end());
  for(auto p : ps) cout << p << " ";
  cout << "\n";
  return 0;
}