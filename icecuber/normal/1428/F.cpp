#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Brute {
  vector<ll> a;
  int n;
  Brute(int n_) {
    n = n_+10;
    a.resize(n);
  }
  void setmax(int r, ll v) {
    for (int i = 0; i < r; i++) a[i] = max(a[i], v);
  }
  ll Sum() {
    ll ans = 0;
    for (ll v : a) ans += v;
    return ans;
  }
};

struct Smart {
  set<pair<int,ll>> s;
  ll sum;
  Smart(int n_) {
    s.insert({(int)1e6, 0});
    s.insert({0, (int)1e6});
    sum = 0;
  }
  void setmax(int r, ll v) {
    //cout << "Add: " << r << ' ' << v << endl;
    assert(v >= 0);
    auto right = s.lower_bound({r,-1});
    if (right->second >= v) return;
    if (right->first == r) ++right;

    auto [rx, ry] = *right;

    while (prev(right)->second <= v) {
      auto b = prev(right);
      assert(b != s.begin());
      auto a = prev(b);

      auto [ax,ay] = *a;
      auto [bx,by] = *b;
      sum -= (by-ry)*(bx-ax);
      s.erase(b);
    }
    {
      auto a = prev(right);
      auto [ax,ay] = *a;

      sum += (v-ry)*(r-ax);
      s.insert({r,v});
    }
  }
  ll Sum() {
    /*for (auto [x,y] : s) cout << x << ' ' << y << endl;
    cout << sum << endl;
    cout << endl;*/
    return sum;
  }
};



int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);

  //Brute tree(n);
  Smart tree(n);

  ll ans = 0;
  int streak = 0;
  for (int r = 0; r < n; r++) {
    if (s[r] == '0') {
      for (int l = r-streak; l < r; l++) {
	//a[l] = max(a[l], r-l);
	tree.setmax(l+1, r-l);
      }
      tree.setmax(r-streak, streak);
      //for (int l = 0; l < r-streak; l++)
      //a[l] = max(a[l], streak);

      streak = 0;
    } else if (s[r] == '1') {
      streak++;
    } else assert(0);

    ans += (ll)streak*(streak+1)/2;
    tree.setmax(r-streak+1, streak);
    ans += tree.Sum();
    /*for (int l = r-streak+1; l <= r; l++) {
      ans += r-l+1;
    }
    for (int l = 0; l < r-streak+1; l++) {
      ans += max(a[l], streak);
      }*/
    /*
    for (int l = 0; l <= r; l++) {
      //cout << l << ' ' << r << ' ' << max(min(streak, r-l+1), a[l]) << ' ' << streak << ' ' << a[l] << endl;
      assert(a[l] <= r-l+1);
      ans += max(min(streak, r-l+1), a[l]);
      }*/
  }
  cout << ans << endl;
}