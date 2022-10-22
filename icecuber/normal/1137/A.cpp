#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000][1000];
int rowa[1000][1000], rowb[1000][1000];
int cola[1000][1000], colb[1000][1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      cin >> a[i][j];
  for (int i = 0; i < h; i++) {
    map<int,int> m;
    for (int j = 0; j < w; j++)
      m[a[i][j]];
    int c = 0;
    for (auto&p : m) p.second = c++;
    for (int j = 0; j < w; j++) {
      rowa[i][j] = m[a[i][j]];
      rowb[i][j] = c-m[a[i][j]];
    }
  }

  for (int i = 0; i < w; i++) {
    map<int,int> m;
    for (int j = 0; j < h; j++)
      m[a[j][i]];
    int c = 0;
    for (auto&p : m) p.second = c++;
    for (int j = 0; j < h; j++) {
      cola[j][i] = m[a[j][i]];
      colb[j][i] = c-m[a[j][i]];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << max(cola[i][j], rowa[i][j])+max(colb[i][j], rowb[i][j]) << ' ';
    }
    cout << endl;
  }
}