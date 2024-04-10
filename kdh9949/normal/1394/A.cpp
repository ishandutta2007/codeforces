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

  int n, d;
  ll m;
  cin >> n >> d >> m;

  vll B, S;
  for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if(x > m) B.push_back(x);
    else S.push_back(x);
  }

  sort(all(B), greater<int>());
  sort(all(S), greater<int>());

  ll ans = 0, cur = 0;
  for(int i = 0; i < S.size(); i++) cur += S[i];
  ans = max(ans, cur);
  int bd = 1, sd = S.size();
  for(int i = 0; i < B.size(); i++) {
    if(bd > n) break;
    while(bd + sd > n) cur -= S[--sd];
    cur += B[i];
    ans = max(ans, cur);
    bd += (d + 1);
  }

  cout << ans << '\n';
  return 0;
}