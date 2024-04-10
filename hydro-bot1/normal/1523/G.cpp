// Hydro submission #62031d696ce5d450633aa304@1644371306218
// 
// 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 6e6, inf = 2e9;
int n, m, ans[N];
struct node {  int l, r, len, id; } a[N];
vector <int> ver[N];
int s[N], cnt, ls[N], rs[N], rt[N];
void pushup(int p) {
  s[p] = min( s[ls[p]], s[rs[p]] );
}
void insert(int &p,int l,int r,int pos,int val) {
  if( !p ) p = ++cnt, s[p] = inf;
  if(l == r) {
    s[p] = min(s[p], val);
    return;
  }
  int mid = (l + r) >> 1;
  if( pos <= mid ) insert(ls[p], l, mid, pos, val);
  else insert(rs[p], mid + 1, r, pos, val);
  pushup(p);
}
int lowbit(int x) { return x & (-x); }
void change(int l,int r,int x) {
  for(int i = r; i <= n; i += lowbit(i))  insert(rt[i], 1, n, l, x);
}
int query(int p,int l,int r,int nx,int ny) {
  if(!p) return inf;
  if(nx <= l && r <= ny) return s[p];
  int mid = (l + r) >> 1, ans = inf;
  if(nx <= mid) ans = min(ans, query(ls[p], l, mid, nx, ny) );
  if(ny > mid) ans = min(ans, query(rs[p], mid + 1, r, nx, ny) );
  return ans;
}
int ask(int l,int r) {
  int ans = inf;
  for(int i = r; i; i -= lowbit(i)) {
    ans = min(ans, query(rt[i], 1, n, l, r) );
  }
  return ans;
}
int calc(int l,int r,int x) {
  if(l > r) return 0;
  int p = ask(l, r);
  if(p > m) return 0;
  return calc(l, a[p].l - 1, x) + calc(a[p].r + 1, r, x) + a[p].len;
}
signed main () {
  ios :: sync_with_stdio( 0 );
  cin.tie( 0 ), cout.tie( 0 );
  cin >> n >> m;
  for(int i = 0; i <= 4e6; i++) s[i] = inf;
  for(int i = 1; i <= m; i++) {
    cin >> a[i].l >> a[i].r;  a[i].id = i;
    a[i].len = a[i].r - a[i].l + 1;
    ver[ a[i].len ].push_back(i);
  }
  for(int x = n; x >= 1; x--) {
    for(int i = 0; i < ver[x].size(); i++) {
      int id = ver[x][i];
      change( a[id].l, a[id].r, id );
    }
    ans[x] = calc(1, n, x);
  }
  for(int i = 1; i <= n; i++)  cout << ans[i] << "\n";
  return 0;
}