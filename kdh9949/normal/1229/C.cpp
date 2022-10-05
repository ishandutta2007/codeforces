#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define x first
#define y second

const int N = 100005;

int n, m, q;
ll r, oc[N];
vector<int> is[N];

ll f(int x){ return ll(is[x].size()) * oc[x]; }

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0, x, y; i < m; i++){
    cin >> x >> y;
    if(x > y) swap(x, y);
    is[x].push_back(y);
    oc[y]++;
  }
  for(int i = 1; i <= n; i++) r += f(i);
  cout << r << '\n';
  cin >> q;
  for(int i = 0, x; i < q; i++){
    cin >> x;
    r -= f(x);
    for(int i : is[x]){
      r -= f(i);
      oc[x]++;
      oc[i]--;
      is[i].push_back(x);
      r += f(i);
    }
    is[x].clear();
    cout << r << '\n';
  }
}