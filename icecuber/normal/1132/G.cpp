#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000000];

int par[1000000];
vector<int> child[1000000];

int i0[1000000], i1[1000000];
int ind = 0;
void dfs(int p) {
  i0[p] = ind++;
  for (int i : child[p]) dfs(i);
  i1[p] = ind;
}

const int n = 1<<20;
int ma[n*2], add[n*2];
void addf(int a, int b, int v, int l = 0, int r = n, int i = 1) {
  ma[i] += add[i];
  if (i < n) {
    add[i*2] += add[i];
    add[i*2+1] += add[i];
  }
  add[i] = 0;
  if (b <= l || a >= r) return;
  if (a <= l && b >= r) {
    if (i < n) {
      add[i*2] += v;
      add[i*2+1] += v;
    }
    ma[i] += v;
    return;
  }
  int m = l+r>>1;
  addf(a,b,v,l,m,i*2);
  addf(a,b,v,m,r,i*2+1);
  ma[i] = max(ma[i*2], ma[i*2+1]);
}
int query() {
  return ma[1];
}

vector<int> m[1000001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    m[a[i]].push_back(i);

  set<int> s;
  vector<int> roots;
  for (int it = n; it; it--) {
    auto&v = m[it];
    for (int i : v) {
      auto it = s.upper_bound(i);
      if (it == s.end()) {
	par[i] = -1;
	roots.push_back(i);
      } else {
	par[i] = *it;
	child[par[i]].push_back(i);
      }
    }
    for (int i : v) s.insert(i);
  }

  for (int i : roots)
    dfs(i);
  //for (int i = 0; i < n; i++)
  //  cout << (par[i] == -1 ? -1 : a[par[i]]) << ' ';

  for (int i = 0; i < n; i++) {
    //cout << i0[i] << ' ' << i1[i] << endl;
    addf(i0[i], i1[i], 1);
    if (i >= k)
      addf(i0[i-k], i0[i-k]+1, -1e7);
    if (i >= k-1) {
      cout << query() << ' ';
    }
  }
  cout << endl;
}