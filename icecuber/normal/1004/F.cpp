#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int target;

struct Range {
  int l, r, v;
};

struct Node {
  ll inside;
  int or_sum;
  int w;
  vector<Range> pref, suf;
};

vector<Range> merge(const vector<Range>&a, const vector<Range>&b, int aw, int bw) {
  vector<Range> ret = a;
  int cur = ret.back().v;
  for (const Range&r : b) {
    int ncur = cur | r.v;
    if (ncur == cur) {
      ret.back().r = aw+r.r;
    } else {
      ret.push_back({aw+r.l, aw+r.r, ncur});
    }
    cur = ncur;
  }
  assert(ret.back().r == aw+bw);
  return ret;
}

Node operator+(const Node& a, const Node& b) {
  if (a.w == 0) return b;
  if (b.w == 0) return a;
  Node ret;
  ret.inside = a.inside+b.inside;
  ret.or_sum = a.or_sum | b.or_sum;
  ret.w = a.w+b.w;

  ret.pref = merge(a.pref, b.pref, a.w, b.w);
  ret.suf = merge(b.suf, a.suf, b.w, a.w);

  int j = a.suf.size();
  for (const Range&br : b.pref) {
    while (j && (a.suf[j-1].v | br.v) >= target) j--;
    if (j < (int)a.suf.size()) {
      ret.inside += (ll)(a.w-a.suf[j].l)*(br.r-br.l);
    }

    /*for (const Range&ar : a.suf) {
      if ((ar.v | br.v) >= target) {
	ret.inside += (ll)(ar.r-ar.l)*(br.r-br.l);
      }
      }*/
  }
  return ret;
}

const int nax = 1<<17;
Node tree[nax*2];

void put(int a, int v, int l = 0, int r = nax, int i = 1) {
  if (a == l && r-l == 1) {
    ll ok = (ll)(v>=target);
    tree[i] = {ok,v,1,{{0,1,v}},{{0,1,v}}};
  } else if (l <= a && a < r) {
    int m = (l+r)/2;
    put(a, v, l, m, i*2);
    put(a, v, m, r, i*2+1);
    tree[i] = tree[i*2] + tree[i*2+1];
  }
}

Node query(int a, int b, int l = 0, int r = nax, int i = 1) {
  if (a <= l && r <= b) return tree[i];
  else if (a >= r || b <= l) return {0,0,0,{},{}};
  else {
    int m = (l+r)/2;
    return
      query(a, b, l, m, i*2) +
      query(a, b, m, r, i*2+1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q >> target;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    put(i, a);
  }
  //cout << tree[1].w << endl;
  //return 0;
  /*for (int i = 0; i < n; i++)
    cout << tree[nax+i].inside << ' ';
  cout << endl;
  return 0;*/
  while (q--) {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 1) {
      put(a-1, b);
    } else if (type == 2) {
      cout << query(a-1, b).inside << '\n';
    } else assert(0);
  }
}