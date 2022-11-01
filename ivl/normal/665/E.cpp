#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

class trie{
public:
  int cnt;
  trie *l, *r;
  trie() : cnt(0), l(NULL), r(NULL){}
} root;

int n, k;
int a[1<<20];

int p[1<<20];

int get(int num, int pos, trie *t, bool care = true){
  if (t == NULL) return 0;
  if (pos == -1) return t->cnt;
  if (care){
    if ((k>>pos)&1){
      if ((num>>pos)&1) return get(num, pos-1, t->l, true);
      else return get(num^(1<<pos), pos-1, t->r, true);
    } else {
      if ((num>>pos)&1) return get(num, pos-1, t->l, false) + get(num^(1<<pos), pos-1, t->r, true);
      else return get(num, pos-1, t->l, true) + get(num^(1<<pos), pos-1, t->r, false);
    }
  } else return t->cnt;
}

void add(int num, int pos, trie *t){
  ++t->cnt;
  if (pos == -1) return;
  if (t->cnt == 1) t->l = new trie, t->r = new trie;
  if ((num>>pos)&1) add(num, pos-1, t->r);
  else add(num, pos-1, t->l);
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i,n) cin >> a[i];

  REP(i,n) p[i+1] = (p[i]^a[i]);
  ll cnt = 0;
  REP(i,n+1){
    cnt += get(p[i], 30, &root);
    add(p[i], 30, &root);
  } cout << cnt << endl;
  
  return 0;
}