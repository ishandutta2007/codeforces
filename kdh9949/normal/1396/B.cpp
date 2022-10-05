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

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    
    vint a(n);
    for(int &x : a) cin >> x;

    sort(all(a), greater<int>());
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    if(a[0] <= sum - a[0] && sum % 2 == 0) cout << "HL\n";
    else cout << "T\n";
  }

  return 0;
}