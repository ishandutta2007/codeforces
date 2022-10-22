#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> node[100000];

int visit[100000];
vector<vector<int>> cycles;

void dfs(int p, int t = 1, int par = -1) {
  static vector<int> stack = {-1};
  if (visit[p] && visit[p] < t) {
    vector<int> v;
    for (int i = visit[p]; i < t; i++)
      v.push_back(stack[i]);
    cycles.push_back(v);
    return;
  }
  if (visit[p] > t) return;
  visit[p] = t;
  for (auto e : node[p]) {
    if (e.first == par) continue;
    stack.push_back(e.second);
    dfs(e.first, t+1, p);
    stack.pop_back();
  }
}


void FST(vector<ll>& a, bool inv) {
  for (int n = a.size(), step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) {
      for (int j = i; j < i+step; j++) {
	ll &u = a[j], &v = a[j + step];
	tie(u, v) =
	  make_pair(u + v, u - v);
      }
    }
  }
  if (inv) for (ll&x : a) x /= a.size();
}

ll mod = 1000000007;

vector<ll> conv(vector<ll> a, vector<ll> b) {
  FST(a, 0); FST(b, 0);
  for (int i = 0; i < a.size(); i++)
    a[i] *= b[i];
  FST(a, 1);
  for (int i = 0; i < a.size(); i++)
    a[i] %= mod;
  return a;
}

vector<ll> conv2(vector<ll> a, vector<ll> b) {
  FST(a, 0); FST(b, 0);
  for (int i = 0; i < a.size(); i++)
    a[i] *= b[i];
  FST(a, 1);
  for (int i = 0; i < a.size(); i++)
    a[i] = !!a[i];
  return a;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int base = 0;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back({b,c});
    node[b].push_back({a,c});
    base ^= c;
  }
  dfs(0);

  int nax = 1<<17;
  vector<ll> reachable(nax,0);
  vector<ll> count(nax,0);
  reachable[base] = 1;
  count[base] = 1;

  //cout << base << endl;
  for (auto v : cycles) {
    vector<ll> b(nax,0);
    //b[0] = 1; //We need to output a tree, right?
    for (int i : v) {
      b[i]++;
    }
    count = conv(count, b);
    reachable = conv2(reachable, b);
  }
  for (int i = 0; i < nax;i++) {
    if (reachable[i]) {
      cout << i << ' ' << (count[i]%mod+mod)%mod << endl;
      return 0;
    }
  }
  assert(0);
}