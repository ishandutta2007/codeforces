#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[1010][1010];

void f(int l, int r, vector<int> a) {
  int h = r-l, n = a.size(), w = 0, m = 0;
  /*cout << h << endl;
  for (int i : a) cout << i << ' ';
  cout << endl;
  cout << endl;
  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j];
    cout << endl;
  }
  cout << endl;*/

  for (int i = 0; i < n; i++) {
    w += a[i] > 0;
    m = max(m, a[i]);
  }
  assert(m < h);
  assert(w+1 >= h);

  if (m == 0) return;

  vector<int> pos;
  for (int i = 0; i < n; i++)
    if (a[i] == m) pos.push_back(i);
  if (m == h-1) {
    int k = pos.size();
    int rem = h-k;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < h; j++) {
	ans[l+j][pos[i]] = i%h != j;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == m) a[i] = 0;
      else {
	for (int j = 0; j < k && a[i] > (rem <= 1?0:1); j++) {
	  ans[l+j][i] = 1;
	  a[i]--;
	}
      }
    }
    if (rem > 1)
      f(l+k, r, a);
  } else {
    int hb = h-m;
    assert(hb >= 2);

    for (int j = 0; j < m; j++)
      ans[l+j][pos[0]] = 1;

    vector<int> ca(n), cb(n);
    int aw = 0;
    for (int i = 0; i < n; i++) {
      if (i == pos[0]) a[i] = 0;
      else if (a[i] > 1) {
	ca[i] = a[i]-1;
	cb[i] = 1;
	aw++;
      } else if (a[i] == 1) {
	if (aw < m-1) {
	  ca[i] = 1;
	  aw++;
	} else {
	  cb[i] = 1;
	}
      }
      assert(ca[i]+cb[i] == a[i]);
    }
    f(l, l+m, ca);
    f(l+m, r, cb);
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int m = *max_element(a.begin(), a.end());
  f(0, n+1, a);

  cout << n+1 << endl;
  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j];
    cout << endl;
  }

  for (int j = 0; j < n; j++) {
    int sum = 0;
    for (int i = 0; i < n+1; i++) {
      sum += ans[i][j];
    }
    assert(sum == a[j]);
  }

}