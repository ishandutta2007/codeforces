#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  ll lods = 20;
  vector<vector<ll>> ma(lods, vector<ll>(n+1));
  vector<vector<ll>> mi(lods, vector<ll>(n+1));
  vector<int> A(n), B(n);
  for (int&v : A) cin >> v;
  for (int&v : B) cin >> v;
  for (int i = 0; i < n; i++) {
    mi[0][i+1] = ma[0][i+1] = ma[0][i]+B[i]-A[i];
  }
  n++;

  for (int l = 1; l < lods; l++) {
    for (int i = 0; i+(1<<l) <= n; i++) {
      mi[l][i] = min(mi[l-1][i], mi[l-1][i+(1<<(l-1))]);
      ma[l][i] = max(ma[l-1][i], ma[l-1][i+(1<<(l-1))]);
    }
  }

  auto MI = [&](int l, int r) {
    int lod = 0;
    while (2<<lod <= r-l) lod++;
    return min(mi[lod][l], mi[lod][r-(1<<lod)]);
  };
  auto MA = [&](int l, int r) {
    int lod = 0;
    while (2<<lod <= r-l) lod++;
    return max(ma[lod][l], ma[lod][r-(1<<lod)]);
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    if (MI(l, r) < mi[0][l] || mi[0][l] != mi[0][r]) {
      cout << -1 << endl;
    } else {
      cout << MA(l, r)-mi[0][l] << endl;
    }
  }
}