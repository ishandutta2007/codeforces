#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//#warning Small for testing
const int B = 300;
const int nax = 1e5+10;

int mu[nax];
int isprime[nax];

struct Block {
  vector<pair<int,int>> cnt;
  int l, r;
  vector<int> a;
  Block(vector<int>&got, int l_, int r_) {
    vector<int> divs;
    l = l_, r = r_;
    for (int i = l; i < r; i++) {
      if (got[i]) {
	a.push_back(i);
	for (int d = 1; d*d <= i; d++) {
	  if (i%d) continue;
	  divs.push_back(d);
	  if (d*d < i)
	    divs.push_back(i/d);
	}
      }
    }
    sort(divs.begin(), divs.end());
    int last = -1;
    for (int d : divs) {
      if (last != d) {
	if (mu[d])
	  cnt.push_back({d, 0});
	last = d;
      }
      if (mu[d])
	cnt.back().second++;
    }
  }
};


int intersects(vector<pair<int,int>>&a, vector<pair<int,int>>&b) {
  int i = 0, j = 0;
  ll ans = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i].first == b[j].first) {
      ans += mu[a[i].first] * a[i].second * b[j].second;
      i++, j++;
    } else if (a[i].first < b[j].first)
      i++;
    else
      j++;
  }
  return ans;
}

int main() {
  mu[1] = 1;
  for (int i = 2; i < nax; i++) isprime[i] = mu[i] = 1;
  for (int i = 2; i < nax; i++) {
    if (!isprime[i]) continue;
    for (int j = i; j < nax; j += i)
      mu[j] *= -1, isprime[j] = 0;
    for (ll j = (ll)i*i; j < nax; j += (ll)i*i)
      mu[j] = 0;
  }

  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  vector<int> got(nax+B);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    got[a] = 1;
  }

  for (int d = 2; d < nax; d++) {
    for (int i = (nax-1)/d*d; i > 1; i -= d) {
      got[i/d] |= got[i];
    }
  }
  vector<Block> block;
  for (int l = 1; l < nax; l += B) {
    block.push_back(Block(got, l, l+B));
  }

  int c = block.size();
  vector<tuple<int,int,ll>> order;
  for (int i = 0; i < c; i++)
    for (int j = 0; j <= i; j++) {
      ll w = block[i].l+block[i].r>>1;
      ll h = block[j].l+block[j].r>>1;
      order.emplace_back(w*h, i, j);
    }
  sort(order.rbegin(), order.rend());
  ll ans = 0, sum = 0;
  for (auto [prod, i, j] : order) {
    Block&a = block[i];
    Block&b = block[j];
    int expect;
    if ((a.r-1)*ll(b.r-1) > ans && (expect = intersects(a.cnt, b.cnt))) {
      //sum += (ll)a.a.size() * b.a.size();
      //sum++;
      //int found = 0;
      for (int x : a.a)
	for (int y : b.a) {
	  if (__gcd(x,y) == 1) {
	    ans = max(ans, (ll)x*y);
	    //found++;
	  }
	}
      /*if (a.l != b.l) {
	cout << found << ' ' << expect << endl;
	cout << a.l << ' ' << a.r << endl;
	cout << b.l << ' ' << b.r << endl;
	assert(found == expect);
	}*/
    }
  }
  //cout << sum << endl;
  cout << ans << endl;
}