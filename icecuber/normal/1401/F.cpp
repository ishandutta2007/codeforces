#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int logn, q;
  cin >> logn >> q;
  int n = 1<<logn;

  vector<int> flip(logn);
  vector<ll> sum(n*2);
  for (int i = 0; i < n; i++)
    cin >> sum[i+n];
  for (int i = n-1; i; i--)
    sum[i] = sum[i*2]+sum[i*2+1];

  auto query = [&](int r) {
    if (r == n) return sum[1];
    ll ret = 0;
    int i = 1;
    for (int li = logn-1; li >= 0; li--) {
      if (flip[li] == 0) {
	i *= 2;
	if (r>>li&1) {
	  ret += sum[i];
	  i++;
	}
      } else {
	i *= 2;
	if (r>>li&1) {
	  ret += sum[i+1];
	} else i++;
      }
    }
    return ret;
  };
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, v;
      cin >> i >> v;
      i--;
      for (int li = 0; li < logn; li++)
	i ^= flip[li]<<li;
      i += n;
      sum[i] = v;
      for (i >>= 1; i; i >>= 1)
	sum[i] = sum[i*2]+sum[i*2+1];
    } else if (type == 2) {
      int k;
      cin >> k;
      for (int i = 0; i < k; i++)
	flip[i] ^= 1;
    } else if (type == 3) {
      int k;
      cin >> k;
      flip[k] ^= 1;
    } else if (type == 4) {
      int l, r;
      cin >> l >> r;
      cout << query(r)-query(l-1) << endl;
    } else assert(0);
    /*for (int i = 0; i < n; i++)
      cout << query(i+1)-query(i) << ' ';
      cout << endl;*/
  }
}