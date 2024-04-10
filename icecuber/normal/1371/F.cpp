#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<19;

struct Range {
  char cl, cr;
  array<int,2> nl, nr;
  int best, bestflip;
  int full;
  void flip() {
    if (!best) return;
    swap(best, bestflip);
    cl ^= '<'^'>';
    cr ^= '<'^'>';
  }
  Range() {}
  Range(char c) {
    if (c == ' ') {
      best = bestflip = 0;
      cl = cr = ' ';
      nl[0] = nl[1] = nr[0] = nr[1] = 0;
      full = 0;
    } else {
      cl = cr = c;
      nl[0] = nr[0] = 1;
      nl[1] = nr[1] = 0;
      best = bestflip = 1;
      full = 1;
    }
  }
  void print() {
    cout << cl << ' ' << nl[0] << ' ' << nl[1] << endl;
    cout << cr << ' ' << nr[0] << ' ' << nr[1] << endl;
    cout << best << ' ' << bestflip << ' ' << full << endl;
  }
};

Range operator+(const Range&a, const Range&b) {
  if (a.best == 0) return b;
  if (b.best == 0) return a;
  Range r;
  r.best = max(a.best, b.best);
  r.bestflip = max(a.bestflip, b.bestflip);
  if (a.cr == '>' && b.cl == '<') {
    r.best = max(r.best, a.nr[0]+b.nl[0]);
  } else if (a.cr == '<' && b.cl == '<') {
    r.best = max(r.best, a.nr[1]+a.nr[0]+b.nl[0]);
    r.bestflip = max(r.bestflip, a.nr[0]+b.nl[0]+b.nl[1]);
  } else if (a.cr == '>' && b.cl == '>') {
    r.best = max(r.best, a.nr[0]+b.nl[0]+b.nl[1]);
    r.bestflip = max(r.bestflip, a.nr[1]+a.nr[0]+b.nl[0]);
  } else if (a.cr == '<' && b.cl == '>') {
    r.bestflip = max(r.bestflip, a.nr[0]+b.nl[0]);
  } else assert(0);

  r.cl = a.cl;
  r.cr = b.cr;

  vector<pair<char,int>> q;
  auto add = [&](char c, int n) {
    if (!n) return;
    if (q.size() && c == q.back().first)
      q.back().second += n;
    else
      q.push_back({c, n});
  };
  add(a.cl, a.nl[0]);
  add(a.cl^'<'^'>', a.nl[1]);
  if (!a.full) {
    add(' ', 1);
    add(a.cr^'<'^'>', a.nr[1]);
    add(a.cr, a.nr[0]);
  }
  if (!b.full) {
    add(b.cl, b.nl[0]);
    add(b.cl^'<'^'>', b.nl[1]);
    add(' ', 1);
  }
  add(b.cr^'<'^'>', b.nr[1]);
  add(b.cr, b.nr[0]);

  if ((int)q.size() == 1) {
    r.cl = r.cr = q[0].first;
    r.nl = {q[0].second, 0};
    r.nr = {q[0].second, 0};
  } else {
    r.cl = q[0].first;
    r.nl = {q[0].second, q[1].second};
    r.cr = q.back().first;
    r.nr = {q.back().second, q.end()[-2].second};
  }
  r.full = ((int)q.size() <= 2);
  return r;
}

Range mem[nax*2];
int lazy[nax*2];

void prop(int i) {
  if (lazy[i]) {
    mem[i].flip();
    if (i < nax) {
      lazy[i*2] ^= 1;
      lazy[i*2+1] ^= 1;
    }
    lazy[i] = 0;
  }
}

void Flip(int a, int b, int l = 0, int r = nax, int i = 1) {
  prop(i);
  if (a >= r || b <= l) return;
  if (a <= l && b >= r) {
    lazy[i] ^= 1;
    prop(i);
  } else {
    int m = (l+r)/2;
    Flip(a, b, l, m, i*2);
    Flip(a, b, m, r, i*2+1);
    mem[i] = mem[i*2]+mem[i*2+1];
  }
}

Range Query(int a, int b, int l = 0, int r = nax, int i = 1) {
  prop(i);
  if (a >= r || b <= l) return Range(' ');
  if (a <= l && b >= r) {
    //cout << l << ": " << mem[i].cl << endl;
    return mem[i];
  } else {
    int m = (l+r)/2;
    return Query(a, b, l, m, i*2)+Query(a, b, m, r, i*2+1);
  }
}

void print(int n) {
  for (int i = 0; i < n; i++) {
    cout << Query(i, i+1).cl;
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    mem[nax+i] = Range(s[i]);
  }
  for (int i = n; i < nax; i++) {
    mem[nax+i] = Range(' ');
  }
  for (int i = nax-1; i; i--) {
    mem[i] = mem[i*2]+mem[i*2+1];
  }
  // <><< <>>< <
  /*{
    Range a('<'), b('>');
    cout << ((a+((a+b)+(b+a)))+a).bestflip << endl;
  }
  cout << Query(3, 9).bestflip << endl;//mem[1].best << ' ' << mem[1].bestflip << endl;
  return 0;*/
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    Flip(l, r);
    cout << Query(l, r).best << endl;
  }
}