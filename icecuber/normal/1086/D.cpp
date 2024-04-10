#include <bits/stdc++.h>
using namespace std;

int a[200000];
set<int> p[3];
int n, q;

const int M = 300000;
int data[3][M];
void add(int t, int i, int v) {
  for (i += 10; i < M; i += i&-i) data[t][i] += v;
}
int sum(int t, int i) {
  int r = 0;
  for (i += 10; i; i -= i&-i) r += data[t][i];
  return r;
}

int sum(int t, int a, int b) {
  if (a > b) return 0;
  return sum(t, b)-sum(t, a-1);
}

void query() {
  int ans = 0;
  for (int t = 0; t < 3; t++) {
    int x = (t+2)%3, y = (t+1)%3;
    ans += p[t].size();
    if (p[x].size() && p[y].size()) {
      int minx = *p[x].begin(), maxx = *p[x].rbegin();
      int miny = *p[y].begin(), maxy = *p[y].rbegin();
      //cout << minx << ' ' << maxx << ' ' << miny << ' '<< maxy << endl;
      ans -= sum(t, miny, minx)+sum(t, maxx, maxy);
    } else if (p[y].size()) {
      ans -= p[t].size();
    }
  }
  cout << ans << endl;
  //exit(0);
}

int main() {
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    a[i] = s[i]=='R' ? 0 : (s[i] == 'P' ? 1 : 2);
    p[a[i]].insert(i);
    add(a[i], i, 1);
  }
  query();
  while (q--) {
    int i;
    char c;
    cin >> i >> c;
    i--;
    int t = c == 'R' ? 0 : (c == 'P' ? 1 : 2);
    p[a[i]].erase(i);
    add(a[i], i, -1);
    a[i] = t;
    p[t].insert(i);
    add(t, i, 1);
    query();
  }
}