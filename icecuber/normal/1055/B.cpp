#include <bits/stdc++.h>
using namespace std;

int par[100000], size[100000];

int find(int p) {
  if (par[par[p]] != par[p])
    par[p] = find(par[p]);
  return par[p];
}

int groups = 0;
void join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  groups--;
  if (size[a] < size[b]) {
    par[a] = b;
    size[b] += size[a];
  } else {
    par[b] = a;
    size[a] += size[b];
  }
}

long long a[100000];
int main() {
  long long n, q, l;
  cin >> n >> q >> l;
  for (int i = 0; i < n; i++) par[i] = i, size[i] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    groups += a[i] > l;
    if (i && a[i] > l && a[i-1] > l) join(i-1, i);
  }
  while (q--) {
    int cmd;
    cin >> cmd;
    if (!cmd) {
      cout << groups << endl;
    } else {
      long long i, d;
      cin >> i >> d;
      i--;
      a[i] += d;
      if (a[i]-d <= l && a[i] > l) {
	groups++;
	if (i && a[i-1] > l) join(i-1,i);
	if (i < n-1 && a[i+1] > l) join(i, i+1);
      }
    }
  }
}