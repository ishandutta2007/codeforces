#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;

const int M = 1e6;
bitset<M> mask;

vector<int> prime;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  uint A, B, C, D;
  cin >> n >> A >> B >> C >> D;

  for (ll i = 2; i*i <= n; i++) {
    if (mask[i]) continue;
    prime.push_back(i);
    for (ll j = i*i; j*j <= n; j += i) {
      mask.set(j);
    }
  }

  uint ans = 0;
  for (int l = 2; l <= n; l += M) {
    mask.reset();
    int r = min((ll)l+M, (ll)n+1);
    for (int p : prime) {
      for (int j = max((l+p-1)/p*p, p*2); j < r; j += p)
	mask.set(j-l);
    }
    for (uint i = l; i < (uint)r; i++)
      if (!mask[i-l]) {
	uint f = D+i*(C+i*(B+i*A));
	int m = n;
	while (m) {
	  m /= i;
	  ans += f*m;
	}
      }
  }
  cout << ans << endl;
}