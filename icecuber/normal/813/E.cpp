#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<18;
struct Node {
  int sum;
  int vl, vr;
  Node*l, *r;
  Node(int a, int b) {
    l = r = NULL;
    vl = a;
    vr = b;
    sum = 0;
  }
  Node* add(int i, int v) {
    if (i == vl && i+1 == vr) {
      Node*n = new Node(vl,vr);
      n->sum = sum+v;
      return n;
    } else if (i < vl || i >= vr) {
      return this;
    } else {
      int mid = (vl+vr)/2;
      if (!l) l = new Node(vl,mid);
      if (!r) r = new Node(mid,vr);
      Node*n = new Node(vl,vr);
      n->l = l->add(i, v);
      n->r = r->add(i, v);
      n->sum = n->l->sum+n->r->sum;
      return n;
    }
  }
  int query(int b) {
    if (b <= vl) {
      return sum;
    } else if (b >= vr) {
      return 0;
    } else {
      int ans = 0;
      if (l) ans += l->query(b);
      if (r) ans += r->query(b);
      return ans;
    }
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int,vector<int>> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]].push_back(i);
  }
  vector<int> b(n);
  for (auto& p : m) {
    auto&v = p.second;
    for (int i = 0; i < (int)v.size(); i++) {
      b[v[i]] = i+k < (int)v.size() ? v[i+k] : n;
    }
  }

  vector<Node*> tree;
  tree.push_back(new Node(0,nax));
  for (int i = 0; i < n; i++) {
    tree.push_back(tree.back()->add(b[i],1));
  }

  int q;
  cin >> q;
  int last = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int l = (x+last)%n, r = (y+last)%n;
    if (l > r) swap(l,r);
    last = tree[r+1]->query(r+1)-tree[l]->query(r+1);
    cout << last << '\n';
  }
}