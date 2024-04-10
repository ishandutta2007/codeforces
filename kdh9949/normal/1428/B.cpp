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

  int t;
  cin >> t;

  while(t--) {
    int n;
    string s;
    cin >> n >> s;
    if(!count(all(s), '<') || !count(all(s), '>')) {
      cout << n << '\n';
    }
    else {
      int cnt = 0;
      for(int i = 0; i < n; i++) {
        if(s[i] == '-' || s[(i + 1) % n] == '-') cnt++;
      }
      cout << cnt << '\n';
    }
  }

  return 0;
}