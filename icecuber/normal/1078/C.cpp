#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;
vector<int> node[300000];

ll borte[300000], mark[300000], ikke[300000];
ll acc0[300001], acc1[300001];

void rec(int p, int parent = -1) {
  borte[p] = 1;
  mark[p] = 1;
  //ll pcut = 1, sumpar = 0, sumodd = 0, oddpar = 0;
  vector<ll> v, m;
  for (int i : node[p]) {
    if (i == parent) continue;
    rec(i, p);
    (borte[p] *= borte[i]) %= mod;
    (mark[p] *= ikke[i]+borte[i]) %= mod;
    v.push_back(ikke[i]+borte[i]);
    m.push_back(mark[i]);
  }
  acc0[0] = 1;
  for (int i = 1; i < v.size(); i++)
    acc0[i] = (acc0[i-1]*v[i-1])%mod;
  acc1[v.size()] = 1;
  for (int i = int(v.size())-1; i >= 0; i--)
    acc1[i] = (acc1[i+1]*v[i])%mod;

  ikke[p] = 0;
  for (int i = 0; i < v.size(); i++)
    (ikke[p] += m[i]*acc0[i]%mod*acc1[i+1]%mod) %= mod;
  (borte[p] += ikke[p]) %= mod;
  //cout << p+1 << ' ' << cut[p] << ' ' << par[p] << ' ' << odd[p] << endl;
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  rec(0);
  cout << (borte[0]%mod+mod)%mod << endl;
}