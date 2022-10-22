#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int V = 7001;

bitset<V> s[100002];
bitset<V> getmask[V];
bitset<V> init[V];

int square[100], squares = 0;
int squarefree[V];
int main() {
  for (int i = 2; i < 100; i++)
    square[squares++] = i*i;

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i < V; i++) {
    for (int j = 1; j < V; j++)
      if (i%j == 0) init[i].set(j);
  }
  for (int i = 1; i < V; i++) {
    squarefree[i] = 1;
    for (int j = 0; j < squares; j++)
      if (i%square[j]==0) squarefree[i] = 0;
  }
  for (int i = 1; i < V; i++)
    for (int j = 1; j*i < V; j++)
      getmask[i].set(i*j,squarefree[j]);
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x, v;
      cin >> x >> v;
      s[x] = init[v];
    } else if (cmd == 2) {
      int x, y, z;
      cin >> x >> y >> z;
      s[x] = s[y]^s[z];
    } else if (cmd == 3) {
      int x, y, z;
      cin >> x >> y >> z;
      s[x] = s[y]&s[z];
    } else {
      int x, v;
      cin >> x >> v;
      cout << (s[x]&getmask[v]).count()%2;
    }
  }
  cout << endl;
}