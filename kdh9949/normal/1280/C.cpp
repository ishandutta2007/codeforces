#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

int n, sz[N];
vector<pii> e[N];
ll A, B;

void f(int x, int y){
  sz[x] = 1;
  for(pii i : e[x]){
    if(i.x == y) continue;
    f(i.x, x);
    sz[x] += sz[i.x];
    if(sz[i.x] & 1) A += i.y;
    B += 1LL * min(sz[i.x], n - sz[i.x]) * i.y;
  }
}

void solve(){
  cin >> n;
  n <<= 1;
  for(int i = 0, x, y, z; i < n-1; i++){
    cin >> x >> y >> z;
    e[x].emplace_back(y, z);
    e[y].emplace_back(x, z);
  }
  A = B = 0;
  f(1, 0);
  cout << A << ' ' << B << '\n';
  for(int i = 1; i <= n; i++) e[i].clear();
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--) solve();
}