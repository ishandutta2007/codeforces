#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Rect {
  int x0, y0, x1, y1;
};
bool operator<(const Rect&a, const Rect&b) {
  return make_pair(a.x0,a.y0) < make_pair(b.x0,b.y0);
}

struct Segtree {
  static const int n = 1<<18;
  int mi[n*2], lazy[n*2];
  ll sum = 0;
  int query() {
    int i = 1, acc = 0;
    while (i < n) {
      i *= 2;
      if (mi[i]+lazy[i]+acc > 0) i++;
      acc += lazy[i];
    }
    return i-n;
  }
  void add(int i, int v) {
    sum += 1ll*i*v;
    for (i += n; i > 1; i >>= 1) {
      if (i&1)
	lazy[i-1] += v;
      mi[i>>1] = min(mi[i]+lazy[i],mi[i^1]+lazy[i^1]);
    }
  }
  void add(int a, int b, int v) {
    assert(a <= b);
    add(a,-v);
    add(b, v);
  }
  void print() {
    for (int i = 0; i < 10; i++) {
      int r = 0;
      for (int j = i+n; j; j >>= 1)
	r += lazy[j];
      cout << r << ' ';
    }
    cout << endl;
  }
};

void solve(set<Rect>&sx, set<Rect>&sy, Segtree&treex, Segtree&treey, int x1, int y1, int flips = 0) {
  if (sx.size() <= 1) {
    for (const Rect&r : sx) {
      treex.add(r.x0,r.x1,-1);
      treey.add(r.y0,r.y1,-1);
    }
    return;
  }

  //cerr << "Solve: " << sx.begin()->x0 << ' ' << sy.begin()->x0 << ' ' << x1 << ' ' << y1 << endl;
  //cerr << "Rects: " << sx.size() << endl;
  //treex.print();
  //treey.print();
  treex.add(sx.begin()->x0, 1);
  int x = treex.query();
  treex.add(sx.begin()->x0,-1);
  if (x < x1) {
    //cout << "Cutting at " << x << endl;
    set<Rect> sx_, sy_;
    auto sit = sx.begin(), eit = prev(sx.end());
    int nx1, nx1_;
    while (1) {
      //cout << sit->x0 << ' ' << eit->x0 << ' ' << x << endl;
      if (sit->x0 > x) {
	eit = sit;
	sit = sx.begin();
	nx1_= x;
	nx1 = x1;
	break;
      }
      if (eit->x0 <= x) {
	sit = next(eit);
	eit = sx.end();
        nx1 = x;
	nx1_= x1;
	break;
      }
      ++sit;
      --eit;
    }
    for (auto it = sit; it != eit; ++it) {
      sx_.insert(*it);
      auto yit = sy.find({it->y0,it->x0,it->y1,it->x1});
      sy_.insert(*yit);
    }
    for (const Rect&r : sx_) sx.erase(r);
    for (const Rect&r : sy_) sy.erase(r);
    for (const Rect&r : sx_) {
      treex.add(r.x0,r.x1,-1);
      treey.add(r.y0,r.y1,-1);
    }
    solve(sx,sy,treex,treey,nx1,y1);
    assert(treex.sum == 0 && treey.sum == 0);
    for (const Rect&r : sx_) {
      treex.add(r.x0,r.x1, 1);
      treey.add(r.y0,r.y1, 1);
    }
    solve(sx_,sy_,treex,treey,nx1_,y1);
    assert(treex.sum == 0 && treey.sum == 0);
    return;
  }
  if (!flips) {
    //cout << "Flipping" << endl;
    solve(sy,sx,treey,treex,y1,x1, flips+1);
    assert(treex.sum == 0 && treey.sum == 0);
  } else {
    cout << "NO" << endl;
    exit(0);
  }
}

Segtree treex, treey;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<Rect> sx, sy;
  map<int,int> mx, my;
  vector<Rect> rects;
  for (int i = 0; i < n; i++) {
    Rect r;
    cin >> r.x0 >> r.y0 >> r.x1 >> r.y1;
    r.x0++, r.y0++;
    rects.push_back(r);
    mx[r.x0], mx[r.x1], my[r.y0], my[r.y1];
  }
  int c = 1;
  for (auto&p : mx) p.second = c++;
  c = 1;
  for (auto&p : my) p.second = c++;
  for (Rect r : rects) {
    r = {mx[r.x0],my[r.y0],mx[r.x1],my[r.y1]};
    sx.insert(r);
    sy.insert({r.y0,r.x0,r.y1,r.x1});
    treex.add(r.x0, r.x1, 1);
    treey.add(r.y0, r.y1, 1);
  }
  assert(sx.size() == n && sy.size() == n);
  solve(sx,sy,treex,treey,2e5+10,2e5+10);
  assert(treex.sum == 0 && treey.sum == 0);
  cout << "YES" << endl;
}