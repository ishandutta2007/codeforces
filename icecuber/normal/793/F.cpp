#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int k = 400;
int start[100000];
#define ends kdfgh
vector<int> ends[100000];

int reach[400][100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    start[i] = i;

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    start[r] = l;
    ends[l].push_back(r);
  }
  for (int r = 0; r < n; r += k) {
    vector<pair<int,int>> deq;
    int*a = reach[r/k];
    for (int l = 0; l < n; l++)
      a[l] = l;
    for (int l = r-1; l >= 0; l--) {
      for (int e : ends[l]) {
	if (e <= r)
	  a[l] = max(a[l], e);
      }
      while (deq.size() && a[l] >= deq.back().first) {
	a[l] = max(a[l], deq.back().second);
	deq.pop_back();
      }
      deq.push_back({l,a[l]});
    }
    /*cout << r << endl;
    for (int l = 0; l < n; l++)
      cout << a[l] << ' ';
      cout << endl;*/
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int x = reach[r/k][l];
    for (int i = max(r/k*k+1,l); i <= r; i++) {
      if (x >= start[i] && start[i] >= l) x = max(x,i);
    }
    cout << x+1 << '\n';
  }
}