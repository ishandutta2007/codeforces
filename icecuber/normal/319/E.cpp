#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int nax = 1e5;
int par[nax];
int find(int p) {
  return p == par[p] ? p : par[p] = find(par[p]);
}

struct Interval {
  int id;
  int l, r;
  map<int, Interval*> child;
  void recMerge(int p) {
    auto it = child.lower_bound(p);
    if (it == child.begin()) return;
    --it;
    Interval*o = it->second;
    if (o->l < p && o->r > p) {
      child.erase(o->l);
      o->recMerge(p);
      l = min(l, o->l);
      r = max(r, o->r);
      if (o->child.size() > child.size()) {
	swap(o->child, child);
      }
      for (auto&c : o->child) {
	child.insert(c);
      }
      par[o->id] = id;
      o->child.clear();
      delete o;
    }
  }
};

Interval*ipos[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++)
    par[i] = i;
  map<int, Interval*> roots;
  int added = 0;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      Interval*toadd = new Interval({added,l,r});
      ipos[added++] = toadd;

      vector<int> to_erase;
      auto it = roots.lower_bound(r);
      while (it != roots.begin() && (--it)->second->r > l) {
	to_erase.push_back(it->second->l);
	toadd->child[it->first] = it->second;
      }
      for (int i : to_erase)
	roots.erase(i);
      toadd->recMerge(l);
      toadd->recMerge(r);
      roots[toadd->l] = toadd;
    } else {
      assert(type == 2);
      int a, b;
      cin >> a >> b;
      a--, b--;
      a = find(a);
      b = find(b);
      Interval*ia = ipos[a], *ib = ipos[b];
      cout << (a == b || ib->l <= ia->l && ib->r >= ia->r ? "YES" : "NO") << '\n';
    }
  }
}