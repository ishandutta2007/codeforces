#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;

int n, m, A, B, a[N], b[N], ac, bc, at[N], bt[N];
vector<int> ae[N], be[N];
map<pair<int, int>, int> mp;
ll ans;

void f(int x){
  if(a[x]) return;
  a[x] = ac;
  for(int i : ae[x]) f(i);
}

void g(int x){
  if(b[x]) return;
  b[x] = bc;
  for(int i : be[x]) g(i);
}

void solve(){
  cin >> n >> m >> A >> B;
  for(int x, y; m--; ){
    cin >> x >> y;
    if(x != A && y != A){
      ae[x].push_back(y);
      ae[y].push_back(x);
    }
    if(x != B && y != B){
      be[x].push_back(y);
      be[y].push_back(x);
    }
  }
  fill(a + 1, a + n + 1, 0);
  fill(b + 1, b + n + 1, 0);
  ac = bc = 0;
  for(int i = 1; i <= n; i++) if(i != A && i != B) {
    if(!a[i]){ ac++; f(i); }
    if(!b[i]){ bc++; g(i); }
  }
  fill(at + 1, at + n + 1, 0);
  fill(bt + 1, bt + n + 1, 0);
  mp.clear();
  for(int i = 1; i <= n; i++) if(i != A && i != B) {
    at[a[i]]++;
    bt[b[i]]++;
    mp[make_pair(a[i], b[i])]++;
  }
  ans = 0;
  for(int i = 1; i <= n; i++) if(i != A && i != B)
    ans += (n - 2 - at[a[i]] - bt[b[i]] + mp[make_pair(a[i], b[i])]);
  cout << ans/2 << '\n';
  for(int i = 1; i <= n; i++){
    ae[i].clear();
    be[i].clear();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) solve();
}