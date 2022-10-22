#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> brute(vector<ll> h) {
  int n = h.size();
  while (1) {
    auto nh = h;
    int found = 0;
    for (int i = 1; i < n; i++) {
      if (h[i]-h[i-1] >= 2)
	nh[i]--, nh[i-1]++, found = 1;
    }
    h = nh;
    if (!found) break;
  }
  return h;
}

struct Slope {
  ll l, r;
  ll len() {
    return r-l+1;
  }
  ll sum() {
    return (l+r)*len()/2;
  }
};

vector<ll> fast(vector<ll> h) {
  auto start = [](ll sum, ll len) {
    return (sum-len*(len-1)/2 +len-1)/len;
  };
  int n = h.size();
  vector<Slope> ans;
  for (int i = 0; i < n; i++) {
    ll len = 1;
    ll sum = h[i];
    while (ans.size() && ans.back().r+2 <= start(sum, len)) {
      ll x0 = ans.back().l;
      len += ans.back().len();
      sum += ans.back().sum();
      ll x1 = start(sum, len);
      assert(x1 >= x0);
      ans.pop_back();
    }
    {
      ll l = start(sum, len);
      ll diff = (l+l+len-1)*len/2-sum;
      assert(diff >= 0 && diff < len);

      ll m = len-diff-1;
      ans.push_back({l, l+m});
      if (diff) {
	ans.push_back({l+m, l+len-2});
	assert(ans.end()[-2].sum()+ans.end()[-1].sum() == sum);
      } else assert(ans.back().sum() == sum);
    }
  }
  vector<ll> ret;
  for (auto [l,r] : ans) {
    for (ll i = l; i <= r; i++)
      ret.push_back(i);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> h(n);
  for (ll&v : h) cin >> v;
  for (ll v : fast(h)) cout << v << ' ';
  cout << endl;
  /*
    return 0;
    for (int it = 0; it < 1e5; it++) {
    int n = rand()%10+1;
    vector<ll> h(n);
    int m = rand()%10+1;
    for (int i = 1; i < n; i++) h[i] = h[i-1]+rand()%m;
    //for (int i = 1; i < n; i++) cout << h[i]-h[i-1] << ' ';
    //cout << endl;
    assert(brute(h) == fast(h));
    }
    //for (int i = 1; i < n; i++) cout << h[i]-h[i-1] << ' ';
    //cout << endl;
    //for (int v : h) cout << v << ' ';
    //cout << endl;
    */
}