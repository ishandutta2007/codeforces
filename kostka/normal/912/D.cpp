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

int n, m, r, k;

ll squares(int a, int b) {
  return 1LL * (min(a, n-r+1) - max(1, a-r+1) + 1) * (min(b, m-r+1) - max(1, b-r+1) + 1);
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool onboard(int a, int b) {
  return 1 <= a and a <= n and 1 <= b and b <= m;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> r >> k;
  int srn = (n+1)/2;
  int srm = (m+1)/2;
  long double res = 0;
  int odw = 0;
  priority_queue <pair <int, pii> > Q;
  set <pair <int, int> > S;
  Q.push(make_pair(squares(srn, srm), make_pair(srn, srm)));
  S.insert({srn, srm});
  while(odw < k) {
    res += Q.top().first;
    int x, y;
    tie(x, y) = Q.top().second;
    odw++;
    Q.pop();
    for(int d=0; d<4; d++) {
      int nx = x+dx[d], ny = y+dy[d];
      if(onboard(nx, ny) and S.find({nx, ny}) == S.end()) {
        S.insert({nx, ny});
        Q.push(make_pair(squares(nx, ny), make_pair(nx, ny)));
      }
    }
  }
  res /= 1.0 * (n-r+1) * (m-r+1);
  cout << fixed << setprecision(10) << res << "\n";
  return 0;
}