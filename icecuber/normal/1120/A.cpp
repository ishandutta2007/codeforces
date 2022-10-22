#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[500000], b[500000], c[500000], c0[500000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m, k, n, s;
  cin >> m >> k >> n >> s;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < s; i++) {
    cin >> b[i];
    c[--b[i]]++;
    c0[b[i]]++;
  }
  int j = 0, oks = 0;
  int M = 500000;
  for (int i = 0; i < M; i++) oks += !c[i];
  for (int i = 0; i < m; i++) {
    while (j < m && (oks < M || j-i < k))
      if (--c[a[j++]] == 0)
	oks++;
    if (oks == M && j-i >= k && i/k+1+(m-j)/k >= n) {
      int d = i%k+j-i-k;
      cout << d << endl;
      for (int l = 0; l < i%k; l++)
	cout << i+l+1 << ' ';
      int dones = 0;
      for (int l = i; l < j; l++) {
	if (j-l+dones == k || c0[a[l]] > 0) {
	  c0[a[l]]--;
	  dones++;
	} else
	  cout << l+1 << ' ';
      }
      cout << endl;
      return 0;
    }
    if (c[a[i]]++ == 0) {
      oks--;
    }
  }
  cout << -1 << endl;
}