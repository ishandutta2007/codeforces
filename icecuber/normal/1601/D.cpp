#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Person {
  int s, a;
};
bool operator<(Person a, Person b) {
  return a.s+a.a < b.s+b.a;
}

struct segTree {
  vector<ll> ma, off;
  int n;
  segTree(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    ma.resize(n*2);
    off.resize(n*2);
  }
  void setMax(int p, int v) {
    int prev = queryMax(p, p+1);
    if (v > prev) {
      add(p, p+1, v-prev);
    }
  }
  int queryMax(int a, int b) {
    return queryMax(a, b, 0, n, 1);
  }
  int queryMax(int a, int b, int l, int r, int i) {
    if (a <= l && b >= r) {
      return ma[i]+off[i];
    } else if (a >= r || b <= l) return -1e8;
    int m = (l+r)/2;
    return max(queryMax(a, b, l, m, i*2), queryMax(a, b, m, r, i*2+1))+off[i];
  }
  void add(int a, int b, int v) {
    add(a, b, v, 0, n, 1);
  }
  void add(int a, int b, int v, int l, int r, int i) {
    if (a <= l && b >= r) {
      off[i] += v;
      return;
    } else if (a >= r || b <= l) return;
    int m = (l+r)/2;
    add(a, b, v, l, m, i*2);
    add(a, b, v, m, r, i*2+1);
    ma[i] = max(ma[i*2]+off[i*2], ma[i*2+1]+off[i*2+1]);
  }
};

int main() {
  if (0) {
    segTree tree(10);
    tree.add(2, 4, 1);
    for (int i = 0; i < 10; i++) 
      cout << tree.queryMax(i, i+1) << ' ';
    cout << endl;
    return 0;
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<Person> pers(n);
  vector<int> comp;
  comp.push_back(d);
  for (Person&p : pers) cin >> p.s >> p.a, comp.push_back(p.a),comp.push_back(p.s);
  sort(comp.begin(), comp.end());
  int c = comp.size();
  for (Person&p : pers) {
    p.a = lower_bound(comp.begin(), comp.end(), p.a)-comp.begin();
    p.s = lower_bound(comp.begin(), comp.end(), p.s)-comp.begin();
  }
  sort(pers.begin(), pers.end());

  d = lower_bound(comp.begin(), comp.end(), d)-comp.begin();

  segTree tree(c+10);
  for (Person p : pers) {
    tree.setMax(p.a, tree.queryMax(d, min(p.s,p.a)+1)+1);
    if (p.a < p.s)
      tree.add(p.a+1, p.s+1, 1);
  }
  cout << tree.queryMax(0, c) << endl;
}