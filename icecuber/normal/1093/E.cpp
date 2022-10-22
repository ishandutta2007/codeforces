#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
int,
int,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> map_t;

int x[200000], y[200000], b[200000];

struct Fenwick {
  map_t data[200010];
  const int n = 200010;
  void add(int x, int y, int v) {
    if (v > 0)
      for (y += 5; y < n; y += y&-y)
	data[y][x] = 1;
    else
      for (y += 5; y < n; y += y&-y)
	data[y].erase(x);
  }
  int sum(int x, int y) {
    int r = 0;
    for (y += 5; y; y -= y&-y)
      r += data[y].order_of_key(x+1)-1;
    return r;
  }
  int sum(int x0, int x1, int y0, int y1) {
    return sum(x0,y0)+sum(x1,y1)-sum(x1,y0)-sum(x0,y1);
  }
};

Fenwick ftree;

int main() {
  /*{
    map_t m;
    for (int i = 0; i < 10; i++) m[i*2];
    cout << m.order_of_key(5) << endl;
    return 0;
    }*/
  ios::sync_with_stdio(0);cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    x[a-1] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
    y[b[i]] = i;
  }
  for (int i = 0; i < n; i++)
    ftree.add(x[i], y[i], 1);
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int la,ra,lb,rb;
      cin >> la >> ra >> lb >> rb;
      /*int slow = 0;
      for (int i = 0; i < n; i++)
	if (x[i] > la-2 && x[i] < ra && y[i] > lb-2 && y[i] < rb)
	slow++;
	cout << slow << endl;*/
      cout << ftree.sum(la-2,ra-1,lb-2,rb-1) << '\n';
    } else {
      int i,j;
      cin >> i >> j;
      i--,j--;
      int u = b[i], v = b[j];
      swap(b[i],b[j]);
      ftree.add(x[u],y[u],-1);
      ftree.add(x[v],y[v],-1);
      swap(y[u],y[v]);
      ftree.add(x[u],y[u],1);
      ftree.add(x[v],y[v],1);
    }
  }
}