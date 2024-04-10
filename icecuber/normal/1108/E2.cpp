#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segTree {
  int*data, *ma;
  int n;
  segTree(int n_) {
    n = n_;
    data = new int[n*4]();
    ma = new int[n*4]();
  }
  void add(int a, int b, int v, int l = 0, int r = -1, int i = 1) {
    if (r == -1) r = n;
    if (r <= a || l >= b) return;
    if (l >= a && r <= b) {
      data[i] += v;
      ma[i] += v;
      return;
    }
    int m = l+r>>1;
    add(a, b, v, l, m, i*2);
    add(a, b, v, m, r, i*2+1);
    ma[i] = max(ma[i*2],ma[i*2+1])+data[i];
  }
  int top() {
    return ma[1];
  }
};

struct Event {
  int x, t, l, r, i;
};
bool operator<(Event a, Event b) {
  if (a.x != b.x) return a.x < b.x;
  return a.t < b.t;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  segTree tree(n);
  vector<Event> event;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    tree.add(i,i+1,a);
    event.push_back({i,2,0,0,a});
  }
  //for (int i = n; i < tree.n; i++)
  //  tree.add(i,i+1,-1e9);
  for (int i = 0; i < m; i++) {
    int l,r;
    cin >> l >> r;
    l--;
    event.push_back({l,0,l,r,i+1});
    event.push_back({r,1,l,r,i+1});
  }
  sort(event.begin(), event.end());
  set<int> chose;
  set<int> best_chose;
  int best = -1;
  int tot = 0;
  for (Event e : event) {
    if (e.t == 0) {
      chose.insert(e.i);
      tree.add(e.l,e.r,-1);
      tot--;
    } else if (e.t == 1) {
      chose.erase(e.i);
      tree.add(e.l,e.r,1);
      tot++;
    } else {
      int v = tree.top()-(e.i+tot);
      if (v > best) {
	best = v;
	best_chose = chose;
      }
    }
  }
  cout << best << endl;
  cout << best_chose.size() << endl;
  for (int i : best_chose)
    cout << i << ' ';
  cout << endl;
}