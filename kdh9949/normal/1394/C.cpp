#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vpii v(n);
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x = count(all(s), 'B');
    int y = count(all(s), 'N');
    v[i] = pii(x, y);
  }

  pii ans;
  auto f = [&](int x) {
    pii A(v[0].x - x, v[0].y - x);
    pii B(v[0].x + x, v[0].y + x);
    pii D(v[0].y - v[0].x - x, v[0].y - v[0].x + x);
    
    for(int i = 1; i < n; i++) {
      A.x = max(A.x, v[i].x - x);
      A.y = max(A.y, v[i].y - x);
      B.x = min(B.x, v[i].x + x);
      B.y = min(B.y, v[i].y + x);
      D.x = max(D.x, v[i].y - v[i].x - x);
      D.y = min(D.y, v[i].y - v[i].x + x);
    }

    if(A.x > B.x || A.y > B.y || D.x > D.y) return 0;
    if(B.y - A.x < D.x || A.y - B.x > D.y) return 0;
    
    if(B.y - A.x <= D.y) ans = pii(A.x, B.y);
    else if(B.y - B.x >= D.y) ans = pii(B.x, B.x + D.y); 
    else ans = pii(B.y - D.y, B.y);
    return 1;
  };

  int l = 0, r = int(1e6);
  while(l < r) {
    int m = (l + r) / 2;
    if(f(m)) r = m;
    else l = m + 1;
  }

  f(l);
  cout << l << '\n';
  for(int i = 0; i < ans.x; i++) cout << 'B';
  for(int i = 0; i < ans.y; i++) cout << 'N';
  cout << '\n';
  return 0;
}