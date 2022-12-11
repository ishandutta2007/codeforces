#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 3e5 + 20;
inline int cntz(int n) {
   int c = 0;
   while(n % 2 == 0) n /= 2, c ++;
   return c;
}
struct Node {
   int fail, tag, sum, ch[26], tr[26];
} null;
struct AC {
   int id; vector<Node> vec;
   void init() { vec.clear(); vec.resize(2); id = 1; }
   int newnode() { vec.pb(null); return ++ id; }
   void build() {
      rep(i, 1, id) copy(vec[i].tr, vec[i].tr + 26, vec[i].ch);
      queue<int> q;
      vec[1].fail = 1;
      int v = 0;
      rep(i, 0, 25) {
         if(bool(v = vec[1].ch[i])) {
            q.push(v);
            vec[v].fail = 1;
         } else {
            vec[1].ch[i] = 1;
         }
      }
      while(q.size()) {
         int u = q.front(); q.pop();
         int t = vec[u].fail;
         vec[u].sum = (t == u ? 0 : vec[t].sum) + vec[u].tag;
         rep(i, 0, 25) {
            if(bool(v = vec[u].ch[i])) {
               q.push(v);
               vec[v].fail = vec[t].ch[i];
            } else {
               vec[u].ch[i] = vec[t].ch[i];
            }
         }
      }
   }
   void insert(char *s) {
      int u = 1;
      for(; *s; s ++) {
         if(!vec[u].tr[*s - 'a']) {
            int nw = newnode();
            vec[u].tr[*s - 'a'] = nw;
         }
         u = vec[u].tr[*s - 'a'];
      }
      vec[u].tag ++;
   }
   ll query(char *s) {
      int u = 1; ll ans = 0;
      for(; *s; s ++) {
         u = vec[u].ch[*s - 'a'];
         ans += vec[u].sum;
      }
      return ans;
   }
   int dfs(int u, int v, AC &A) {
      if(!v) return u;
      if(!u) u = newnode();
      vec[u].tag += A.vec[v].tag;
      rep(i, 0, 25) {
         int nw = dfs(vec[u].tr[i], A.vec[v].tr[i], A);
         vec[u].tr[i] = nw;
      }
      return u;
   }
   void merge(AC &A) { dfs(1, 1, A); }
};
struct ACs {
   AC a[24];
   int n;
   void init() {
      rep(i, 0, 20) a[i].init();
   }
   void insert(char *s) {
      n ++;
      int z = cntz(n);
      rep(i, 0, z - 1) { a[z].merge(a[i]); a[i].init(); }
      a[z].insert(s); a[z].build();
   }
   ll query(char *s) {
      ll ans = 0;
      rep(i, 0, 20) if(a[i].id > 1) ans += a[i].query(s);
      return ans;
   }
} a, b;
int main() {
   static char s[N];
   a.init(); b.init();
   int q, op; scanf("%d", &q);
   rep(Q, 1, q) {
      scanf("%d%s", &op, s);
      if(op == 1) a.insert(s);
      if(op == 2) b.insert(s);
      if(op == 3) printf("%lld\n", a.query(s) - b.query(s));
      fflush(stdout);
   }
   return 0;
}