#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll area(int i) {
  if (i < 2) return 0;
  //cerr << "Ask: " << 1 << ' ' << 0 << ' ' << 1 << ' ' << i << endl;
  cout << 1 << ' ' << 1 << ' ' << 2 << ' ' << i+1 << endl;
  ll a;
  cin >> a;
  return a;
}

int sign(int i, int j, int k) {
  if (i == 0 && j == 1 && k == 0) return -1;
  if (i == 0 && j == 1 && k == 1) return 1;
  assert(i != j && i != k && j != k);
  //cerr << "Ask: " << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
  cout << 2 << ' ' << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
  int a;
  cin >> a;
  return a;
}

int main() {
  //ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  /*for (int i = 0; i < 8; i++)
    cerr << area(i) << endl;
    exit(0);*/
  vector<pair<ll,int>> A[2];
  for (int i = 0; i < n; i++) {
    ll ar = area(i);
    int sgn = sign(0, 1, i) > 0;
    A[sgn].emplace_back(ar, i);
  }
  for (int k : {0,1}) {
    sort(A[k].begin(), A[k].end());
    /*for (auto p : A[k]) {
      cerr << k << ' ' << p.first << ' ' << p.second << endl;
      }*/
  }
  int x = A[0].back().second;
  int y = A[1].back().second;
  //cerr << x << ' ' << y << endl;
  vector<pair<ll,int>> B[4];
  for (int k : {0,1}) {
    for (auto p : A[k]) {
      int i = p.second;
      int side = 0;
      if (i == x) {
	side = 0;
      } else if (i == y) {
	side = 0;
      } else {
	side = (sign(x, y, i) > 0);
      }
      //cerr << p.second << endl;
      B[k*2+side].push_back(p);
    }
  }
  vector<int> ans;
  for (int k : {1,0,2,3}) {
    if (k == 0 || k == 3) reverse(B[k].begin(), B[k].end());
    for (auto p : B[k]) ans.push_back(p.second+1);
  }
  int onepos = 0;
  for (int i = 0; i < n; i++)
    if (ans[i] == 1) onepos = i;


  cout << 0 << ' ';
  for (int i = 0; i < n; i++) {
    cout << ans[(onepos+i)%n] << ' ';
  }
  cout << endl;
}