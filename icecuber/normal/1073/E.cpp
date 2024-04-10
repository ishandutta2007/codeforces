#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

vector<int> reduce(vector<int> v, int mask) {
  int mi = 9, ma = 0;
  for (int j = 0; j < 10; j++) {
    if (mask>>j&1) {
      mi = min(mi, j);
      ma = max(ma, j);
    }
  }
  int loan = 0;
  for (int i = 0; i < v.size(); i++) {
    v[i] -= loan;
    loan = 0;
    if (v[i] < mi) {
      for (int j = 0; j <= i; j++)
	v[j] = ma;
      loan = 1;
    } else if (mask>>v[i]&1) {
    } else {
      while (!(mask>>v[i]&1)) v[i]--;
      for (int j = 0; j < i; j++)
	v[j] = ma;
    }
  }
  if (loan) v.pop_back();
  while (v.size() && !*v.rbegin())
    v.pop_back();
  return v;
}

vector<int> digits(ll n) {
  vector<int> v;
  ll base = 1;
  while (n) {
    ll d = n%10;
    v.push_back(d);
    n /= 10;
  }
  return v;
}
ll num(vector<int> v) {
  ll m = 1, r = 0;
  for (int i : v) {
    r += m*i;
    m *= 10;
  }
  return r;
}

vector<int> safereduce(ll n, int mask) {
  while (1) {
    int ok = 1;
    for (int i : digits(n))
      if (!(mask>>i&1)) ok = 0;
    if (ok) break;
    n--;
  }
  return digits(n);
}

ll sum(vector<int> v, int mask) {
  int ind[10], mi = 9, ma = 0, pop = 0;
  for (int j = 0; j < 10; j++) {
    ind[j] = (j?ind[j-1]:-1)+(mask>>j&1);
    if (mask>>j&1) {
      mi = min(mi, j);
      ma = max(ma, j);
      pop++;
    }
  }

  ll ans = 0;
  ll right = 1, rval = 0, p10 = 1;
  for (int i = 0; i < v.size(); i++) {
    ll left = 0;
    for (int j = v.size()-1; j > i; j--)
      left = (left*pop+ind[v[j]]) % mod;
    ll mul = !(mask&1);
    for (int j = i+1; j < v.size(); j++) {
      left = (left+mul) % mod;
      mul = mul*pop % mod;
    }

    //cout << left << ' ' << right << ' ' << rval << endl;
    for (int j = 1; j < 10; j++)
      if (mask>>j&1) {
	(ans += left*right%mod * j %mod * p10) %= mod;
	if (j < v[i]) (ans += right*j %mod * p10) %= mod;
	else if (j == v[i]) (ans += (rval+1)*v[i] %mod * p10) %= mod;
      }
    rval = (rval+right*ind[v[i]]) %mod;
    right = right*pop %mod;
    p10 = p10*10 %mod;
  }
  return ans;
}

ll safesum(ll n, int mask) {
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    int ok = 1;
    for (int i : digits(i))
      if (!(mask>>i&1)) ok = 0;
    ans += ok*i;
  }
  return ans;
}

ll dp[1<<10], dp2[1<<10];
ll f(ll n, int k) {
  vector<int> v = digits(n);

  for (int mask = 1; mask < 1<<10; mask++)
    dp[mask] = sum(reduce(v,mask), mask);
  for (int i = 1; i < 1<<10; i++) {
    dp2[i] = 0;
    for (int j = 1; j < 1<<10; j++)
      if ((j&i) == j) {
	int k = i^j;
	int pop = 0;
	while (k) k -= k&-k, pop++;
	(dp2[i] += (pop%2?-1:1)*dp[j]) %= mod;
      }
  }
  ll ans = 0;
  for (int mask = 1; mask < 1<<10; mask++) {
    int pop = 0;
    int i = mask;
    while (i) i -= i&-i, pop++;
    if (pop > k) continue;
    (ans += dp2[mask]) %= mod;
  }
  return (ans+mod)%mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  /*for (int it = 0; it < 10000; it++) {
    int n = rand()%10000+1;
    int mask = rand()%1023+1;
    int r = num(reduce(digits(n),mask));
    auto a = sum(digits(r), mask);
    auto b = safesum(r, mask);
    if (a != b) {
      cout << n << ' ' << r << endl;
      cout << "mask: ";
      for (int i = 0; i < 10; i++)
	if (mask>>i&1) cout << i << ' ';
      cout << endl;
      cout << a << ' ' << b << endl;
    }
  }
  return 0;
  */
  ll l, r, k;
  cin >> l >> r >> k;
  cout << (f(r,k)-f(l-1,k)+mod)%mod << endl;
}