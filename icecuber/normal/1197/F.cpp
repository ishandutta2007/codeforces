#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 64;
ll mod = 998244353;
struct Mat {
  ll v[n][n];
  void zero() {
    fill_n((ll*)v, n*n, 0);
  }
};

Mat operator*(Mat a, Mat b) {
  Mat r;
  r.zero();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
	(r.v[i][j] += a.v[i][k]*b.v[k][j]) %= mod;
  return r;
}

struct Vec {
  ll v[n];
  void zero() {
    fill_n(v, n, 0);
  }
};
Vec operator*(Mat A, Vec b) {
  Vec r;
  r.zero();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      (r.v[i] += A.v[i][j]*b.v[j]) %= mod;
  return r;
}

int a[1000];
vector<pair<int,int>> colored[1000];
int f[3][3];

Mat powmat[40];

Vec powmul(Vec b, ll p) {
  Vec r = b;
  for (int i = 0; i < 40; i++) {
    if (p>>i&1)
      r = powmat[i]*r;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    x--, y--, c--;
    colored[x].push_back({y,c});
  }
  Mat colmat[3];
  for (int i = 0; i < 3; i++) {
    colmat[i].zero();
    for (int j = 0; j < 3; j++) {
      cin >> f[i][j];
    }
    for (int x = 0; x < 4; x++)
      for (int y = 0; y < 4; y++)
	for (int z = 0; z < 4; z++) {
	  set<int> seen;
	  if (f[i][0])
	    seen.insert(z);
	  if (f[i][1])
	    seen.insert(y);
	  if (f[i][2])
	    seen.insert(x);
	  int w = 0;
	  while (seen.count(w)) w++;
	  colmat[i].v[y*16+z*4+w][x*16+y*4+z] = 1;
	  //cout << x << ' ' << y << ' ' << z << ": " << w << endl;
	}
  }
  powmat[0].zero();
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 64; j++)
      for (int k = 0; k < 64; k++)
	(powmat[0].v[j][k] += colmat[i].v[j][k]) %= mod;
  }
  /*{
    Vec ways;
    ways.zero();
    ways.v[63] = 1;
    cout << (colmat[0]*ways).v[3*16+3*4+0] << endl;
  }
  return 0;*/
  for (int l = 0; l+1 < 40; l++) {
    powmat[l+1] = powmat[l]*powmat[l];
  }
  ll ansdp[4] = {1,0,0,0};
  for (int i = 0; i < n; i++) {
    Vec ways;
    ways.zero();
    ways.v[63] = 1;
    sort(colored[i].begin(), colored[i].end());
    int last = 0;
    for (auto p : colored[i]) {
      int x = p.first, c = p.second;
      ways = powmul(ways, x-last);
      ways = colmat[c]*ways;
      last = x+1;
    }
    ways = powmul(ways, a[i]-last);
    ll answays[4] = {};
    for (int x = 0; x < 4; x++)
      for (int y = 0; y < 4; y++)
	for (int z = 0; z < 4; z++)
	  (answays[z] += ways.v[x*16+y*4+z]) %= mod;
    ll nansdp[4] = {};
    for (int x = 0; x < 4; x++)
      for (int y = 0; y < 4; y++)
	(nansdp[x^y] += ansdp[x]*answays[y]) %= mod;
    swap(ansdp, nansdp);
  }
  cout << (ansdp[0]%mod+mod)%mod << endl;
}