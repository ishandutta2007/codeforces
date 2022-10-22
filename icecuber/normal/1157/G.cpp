#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<200> a0[200], a[200];
int inv_col[200], inv_row[200];
int h, w;

void check(int zeros) {
  bitset<200> maskw;
  for (int j = 0; j < w; j++)
    maskw.set(j);
  bitset<200> maskh;

  copy_n(a0, 200, a);
  for (int i = 0; i < h; i++) {
    if (zeros >= w) {
      zeros -= w;
    } else if (!zeros) {
      a[i] ^= maskw;
    } else {
      for (int j = 0; j < w; j++)
	if (zeros > 0)
	  zeros--;
	else
	  a[i].flip(j);
    }
  }
  /*for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << a[i][j] << ' ';
    cout << endl;
    }*/
  for (int j = 0; j < w; j++) {
    inv_col[j] = a[0][j];
    maskh.set(j,inv_col[j]);
  }

  for (int i = 0; i < h; i++)
    a[i] ^= maskh;
  for (int i = 0; i < h; i++) {
    inv_row[i] = a[i][0];
    if (inv_row[i])
      a[i] ^= maskw;
  }
  /*for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << a[i][j] << ' ';
    cout << endl;
    }*/
  for (int i = 0; i < h; i++)
    if (a[i].any())
      return;
  cout << "YES" << endl;
  for (int i = 0; i < h; i++)
    cout << inv_row[i];
  cout << endl;
  for (int i = 0; i < w; i++)
    cout << inv_col[i];
  cout << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      int v;
      cin >> v;
      a0[i][j] = v;
    }
  for (int i = 0; i <= w*h; i++)
    check(i);
  cout << "NO" << endl;
}