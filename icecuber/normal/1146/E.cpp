#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double x[100000];
char s[100000];
int ans[100001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  for (int i = 0; i < q; i++) {
    cin >> s[i] >> x[i];
    x[i] += (s[i]=='>')-.5;
  }
  int last = 1e5+1, flip = 1;
  for (int i = q-1; i >= 0; i--) {
    if (x[i] > 0 && s[i] == '<' || x[i] < 0 && s[i] == '>') {
      flip *= -1;
      s[i] ^= '<'^'>';
    }
    int t = abs(x[i])+0.5;
    if (t >= last) continue;
    for (int j = last-1; j >= t; j--)
      ans[j] = ((s[i]=='<')*2-1)*flip;
    last = t;
  }
  for (int i = 0; i < n; i++) {
    int ab = abs(a[i]);
    if (ans[ab]) {
      cout << ans[ab]*ab << ' ';
    } else
      cout << a[i]*flip << ' ';
  }
  cout << endl;
}