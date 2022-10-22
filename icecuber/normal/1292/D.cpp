#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5001;
int isprime[nax];

template<class T>
int BS(int fail, int pass, T f) {
  assert(f(pass));
  assert(!f(fail));
  while (abs(pass-fail) > 1) {
    int mid = (pass+fail)>>1;
    if (f(mid)) pass = mid;
    else fail = mid;
  }
  return pass;
}

struct RangeSum {
  vector<ll> data;
  int n;
  RangeSum(int n_) {
    n = n_+10;
    data.resize(n);
  }
  void add(int r, ll v) {
    for (int i = r+5; i < n; i += i&-i)
      data[i] += v;
  }
  void add(int l, int r, ll v) {
    add(l, v);
    add(r,-v);
    //for (int i = l; i < r; i++) data[i] += v;
  }
  ll get(int i) {
    ll r = 0;
    for (i += 5; i; i -= i&-i)
      r += data[i];
    return r;
  }
};

int main() {
  vector<int> prime;
  for (int i = 2; i < nax; i++) isprime[i] = 1;
  for (int i = 2; i < nax; i++) {
    if (!isprime[i]) continue;
    prime.push_back(i);
    for (int j = i*2; j < nax; j += i)
      isprime[j] = 0;
  }
  int primes = prime.size();

  ios::sync_with_stdio(0); cin.tie(0);
  vector<ll> w(nax);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    w[k]++;
  }
  vector<vector<int>> cnt(nax, vector<int>(primes+1));
  vector<vector<int>> acc(nax, vector<int>(primes+1));
  vector<vector<ll>> accz(nax+1, vector<ll>(primes+1));
  vector<vector<int>> accw(nax+1, vector<int>(primes+1));
  for (int i = 0; i < nax; i++) {
    {
      int pi = 0;
      for (int p : prime) {
	int m = i;
	while (m) {
	  m /= p;
	  cnt[i][pi] += m;
	}
	pi++;
      }
    }
    for (int pi = 1; pi <= primes; pi++) {
      acc[i][pi] = acc[i][pi-1]+cnt[i][pi-1];
    }
    for (int pi = 0; pi <= primes; pi++) {
      accz[i+1][pi] = accz[i][pi]+acc[i][pi] * w[i];
      accw[i+1][pi] = accw[i][pi]+w[i];
    }
  }
  vector<vector<int>> rl(nax, vector<int>(nax));
  for (int i = 0; i < nax; i++) {
    for (int j = 0; j <= i; j++) {
      rl[i][j] = j ? rl[i][j-1] : primes-1;
      int&r = rl[i][j];
      while (r >= 0 &&
	     cnt[i][r] == cnt[j][r])
	r--;
      rl[j][i] = r;
    }
  }

  ll ans = 1e18;
  for (int i = 0; i < nax; i++) {
    RangeSum tree(primes+1);
    //for (int z = 0; z <= primes; z++) {
    //  ll sum = -(ll)acc[i][z] * n;
    for (int j = 0; j < nax; j++) {
      int r = rl[i][j];
      //if (z <= r) {
      if (r > -1) {
	ll v = (acc[j][r] + acc[i][r] + abs(cnt[i][r]-cnt[j][r])) * w[j];
	tree.add(0, r+1, v);
      }
      //sum += v;
      //} else {
      //sum += (acc[j][z] + acc[i][z]) * w[j];
      //}
    }
    //ans = min(ans, sum);
    //}
    for (int z = 0; z <= primes; z++) {
      //cout << z << endl;
      int mi = BS(-1, i, [&](int j) {return j >= 0 ? rl[i][j] < z : 0;});
      int ma = BS(i, nax, [&](int j) {return j < nax ? rl[i][j] >= z : 1;});
      /*for (int j = 0; j < nax; j++) {
	assert((rl[i][j] < z) == (j >= mi && j < ma));
	}*/
      //cout << mi << ' '<< ma << endl;
      ll score = tree.get(z) + (accz[ma][z]-accz[mi][z]) - (ll)acc[i][z] * (accw[nax][z] - (accw[ma][z]-accw[mi][z]));
      //cout << score << ' ';
      ans = min(ans, score);
    }
    //cout << endl;
  }
  cout << ans << endl;
}