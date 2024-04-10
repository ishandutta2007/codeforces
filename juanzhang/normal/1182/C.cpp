#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 1e5 + 10;
const char ch[] = "aeiou";
string str[maxn];
int n, p1, p2, a[maxn], b[maxn];
pii data[maxn];

vector <int> pos[maxn * 10][5];

int main() {
  scanf("%d", &n);
  cin.tie(0), cout.tie(0);
  int N = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> str[i];
    int cnt = 0, lst;
    for (char c : str[i]) {
      for (int k = 0; k < 5; k++) {
        if (c == ch[k]) {
          cnt++, lst = k;
        }
      }
    }
    N = max(N, cnt);
    data[i] = pii(cnt, lst);
    pos[cnt][lst].push_back(i);
  }
  for (register int i = 1; i <= N; ++i) {
    for (register int j = 0; j < 5; ++j) {
      int _sz = pos[i][j].size();
      register int k = 0;
      for (; k < _sz - 1; k += 2) {
        b[++p2] = pos[i][j][k];
        b[++p2] = pos[i][j][k + 1];
      }
      if (k < _sz) {
        a[++p1] = pos[i][j][k];
      }
    }
  }
  int c1 = 0, c2 = 0;
  for (int i = 2; i <= p1; i++) {
    if (data[a[i]].first == data[a[i - 1]].first) {
      c1++, i++;
    }
  }
  c2 = p2 >> 1;
  while (c2 > 0 && c1 < c2) {
    c1++, c2--;
    a[++p1] = b[p2--];
    a[++p1] = b[p2--];
  }
  int len = 0;
  for (int i = 2; i <= p1; i++) {
    if (data[a[i]].first == data[a[i - 1]].first) {
      a[++len] = a[i - 1], a[++len] = a[i], i++;
    }
  }
  int ans = c2;
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) {
    int x = i + i - 1, y = x + 1;
    cout << str[a[x]] << ' ' << str[b[x]] << endl;
    cout << str[a[y]] << ' ' << str[b[y]] << endl;
  }
  return 0;
}