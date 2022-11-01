#include <bits/stdc++.h>
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

// TREAP
typedef struct item * pitem;
struct item {
  int prior, value, cnt, add;
  bool rev;
  pitem l, r;
  item(int val) {
    prior = rand();
    value = val; cnt = 1; rev = false; l = r = NULL;
    add = 0;
  }
};

int cnt (pitem it) {
  return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
  if (it)
    it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
  if (it && it->rev) {
    it->rev = false;
    swap (it->l, it->r);
    if (it->l)  it->l->rev ^= true;
    if (it->r)  it->r->rev ^= true;
  }
  if (it) {
    if (it->l) it->l->add += it->add;
    if (it->r) it->r->add += it->add;
    it->value += it->add;
    it->add = 0;
  }
}

void merge (pitem & t, pitem l, pitem r) {
  push (l);
  push (r);
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge (l->r, l->r, r),  t = l;
  else
    merge (r->l, l, r->l),  t = r;
  upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t)
    return void( l = r = 0 );
  push (t);
  int cur_key = t->value;
  if (key <= cur_key)
    split (t->l, l, t->l, key, add),  r = t;
  else
    split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
  upd_cnt (t);
}

void splitbsz (pitem t, pitem & l, pitem & r, int key, int add = 0) {
  if (!t)
    return void( l = r = 0 );
  push (t);
  int cur_key = add+cnt(t->l);
  if (key <= cur_key)
    splitbsz (t->l, l, t->l, key, add),  r = t;
  else
    splitbsz (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
  upd_cnt (t);
}

void ins(pitem &t, int x) {
  pitem nw = new item(x);
  pitem l, r;
  split(t, l, r, x);
  merge(t, l, nw);
  merge(t, t, r);
}

void output (pitem t) {
  if (!t)  return;
  push (t);
  output (t->l);
  if (t->value < 1.5e9) printf ("%d ", t->value);
  output (t->r);
}

int ans;
void cntsmall (pitem t) {
  if (!t)  return;
  push (t);
  cntsmall (t->l);
  if (t->value < 1.5e9) ans++;
  cntsmall (t->r);
}

int n;
int vls[100];
void uvls(int l, int r) {
  for (int i = r-1; i >= l; i--) {
    vls[i] = max(vls[i], vls[i-1]+1);
  }
  FO(i,1,100) vls[i] = max(vls[i],vls[i-1]);
  /*FO(i,0,30) printf("%d ", vls[i]);
  printf("\n");

  FO(i,0,100) if (i == 0 || vls[i] != vls[i-1]) {
    printf("%d ", i);
  }
  printf("\n");*/
}

void delfrst(pitem &t) {
  if (!t) return;
  pitem frst, rst;
  splitbsz(t, frst, rst, 1);
  t = rst;
}

//int ls[300005], rs[300005];
//map<int,int> cc[300005];

/*int dp(int i, int dy) {
  if (i == n) return 0;
  if (cc[i].count(dy)) return cc[i][dy];
  int ans = dp(i+1,dy);
  int ndy = max(dy+1, ls[i]);
  if (ndy <= rs[i]) ans = max(ans, dp(i+1,ndy)+1);
  return cc[i][dy]=ans;
}*/

int main() {
  scanf("%d", &n);

  pitem t = NULL;
  ins(t, 0);
  FO(i,0,n+5) ins(t, 2e9+i);

  //output(t); printf("\n");

  FO(_,0,n) {
    int l, r; scanf("%d %d", &l, &r);
    //ls[_] = l;
    //rs[_] = r;
    //printf("l = %d, r = %d\n", l, r);
    //uvls(l, r+1);
    pitem lsl, btw, ger;
    split(t, lsl, t, l);
    split(t, btw, ger, r);
    //printf("LSL: "); output(lsl); printf("\n");
    //printf("BTW: "); output(btw); printf("\n");
    //printf("GER: "); output(ger); printf("\n");
    if (btw) btw->add++;
    delfrst(ger);

    pitem nw = new item(l);

    merge(t, lsl, nw);
    merge(t, t, btw);
    merge(t, t, ger);

    //printf("T: "); output(t); printf("\n");
  }

  cntsmall(t);
  printf("%d\n", ans-1);
  //int ans2 = vls[99];
  //assert(ans-1 == ans2);
  //int ans3 = dp(0,0);
  //assert(ans-1 == ans3);
}