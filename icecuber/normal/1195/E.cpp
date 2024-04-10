#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[3000][3000];
int b[3000][3000];
int c[3000];
int sparse[20][3000];

void compress1(int*a, int*b, int n, int k) {
  multiset<int> s;
  for (int j = 0; j < n; j++) {
    s.insert(a[j]);
    if (j >= k) s.erase(s.find(a[j-k]));
    if (j >= k-1)
      b[j-(k-1)] = *s.begin();
  }
}

void compress2(int*a, int*b, int n, int k) {
  copy_n(a, n, sparse[0]);
  int lod = log2(k);
  for (int l = 1; l <= lod; l++) {
    for (int i = 0; i+(1<<l) <= n; i++)
      sparse[l][i] = min(sparse[l-1][i], sparse[l-1][i+(1<<l-1)]);
  }
  for (int i = 0; i <= n-k; i++) {
    b[i] = min(sparse[lod][i], sparse[lod][i+k-(1<<lod)]);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, hi, wi;
  cin >> h >> w >> hi >> wi;
  ll g, x, y, z;
  cin >> g >> x >> y >> z;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      a[i][j] = g;
      g = (g*x+y)%z;
    }
  }
  for (int i = 0; i < h; i++)
    compress2(a[i], b[i], w, wi);
  for (int i = 0; i < max(w,h); i++)
    for (int j = 0; j < i; j++)
      swap(b[i][j],b[j][i]);
  swap(w,h);
  swap(wi,hi);
  ll ans = 0;
  for (int i = 0; i <= h-hi; i++) {
    compress2(b[i], c, w, wi);
    for (int j = 0; j <= w-wi; j++)
      ans += c[j];
  }
  cout << ans << endl;
}