#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];

int n, m;
struct Roll {
  ll mod, base, seed, h, pown;
  Roll(ll mod_, ll base_, ll seed_) {
    mod = mod_;
    base = base_;
    seed = seed_;
    pown = 1;
    h = 0;
    for (int i = 0; i < n; i++)
      pown = pown*base%mod;
  }
  ll myhash(vector<int>&v) {
    ll r = 123;
    for (int i : v)
      (r += i*seed) %= mod;
    //cout << r << endl;
    return r;
  }
  void add(vector<int>&v) {
    ll v_ = myhash(v);
    h = (h*base+v_)%mod;
  }
  void erase(vector<int>&v) {
    ll v_ = myhash(v);
    h = (h+mod-pown*v_%mod)%mod;
  }
  ll query() {
    return h;
  }
};

void addEdge(int a, int b) {
  node[a].push_back((b-a+n)%n);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    addEdge(a,b);
    addEdge(b,a);
  }

  int rolls = 8;
  vector<Roll> roll;
  ll mod[] = {550070320, 1442135613, 1790733028, 1813444074, 608672454, 18733727, 1943499158, 2044794333};
  ll base[] = {1932012838, 263694159, 1386674096, 449887499, 110846301, 1480787470, 1417883473, 1501579031};
  ll seed[] = {266250424, 818970402, 1787308878, 1350311366, 432885055, 1208444541, 1114166902, 823355380};
  for (int j = 0; j < rolls; j++) {
    roll.push_back(Roll(mod[j], base[j], seed[j]));
  }
  set<vector<ll>> seen;
  for (int i = 0; i < n*2-1; i++) {
    vector<ll> h;
    for (int j = 0; j < rolls; j++) {
      roll[j].add(node[i%n]);
      if (i >= n)
	roll[j].erase(node[i%n]);
      h.push_back(roll[j].query());
    }
    if (seen.count(h)) {
      cout << "Yes" << endl;
      return 0;
    }
    seen.insert(h);
  }
  cout << "No" << endl;
}