#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll n = 1<<18;
ll sum[n*2];

ll s[n];
ll p[n];

ll get(ll s) {
  ll j = 1;
  while (j < n) {
    if (sum[j*2] > s) {
      j *= 2;
    } else {
      s -= sum[j*2];
      j = j*2+1;
    }
  }
  return j-n;
}

void add(ll i, ll v) {
  i += n;
  sum[i] += v;
  for (i >>= 1; i; i >>= 1) {
    sum[i] = sum[i*2]+sum[i*2+1];
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> s[i];
    add(i, i+1);
  }
  for (ll i = n-1; i >= 0; i--) {
    ll v = get(s[i]);
    add(v, -(v+1));
    p[i] = v+1;
  }
  for (ll i = 0; i < n; i++)
    cout << p[i] << ' ';
  cout << endl;
}