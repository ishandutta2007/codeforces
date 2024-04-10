#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define x first
#define y second

const int N = 2005;

int n, s[N], c[N], a[N];
vector<int> e[N];

int sf(int x){
  s[x] = 1;
  for(int i : e[x]) s[x] += sf(i);
  return s[x];
}

void f(int x, vector<int> v){
  if(v.size() <= c[x]){
    cout << "NO";
    exit(0);
  }
  a[x] = v[c[x]];
  int j = 0;
  for(int i : e[x]){
    vector<int> w;
    for(int k = 0; k < s[i]; k++){
      if(j == c[x]) j++;
      w.push_back(v[j++]);
    }
    f(i, w);
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int root;
  for(int i = 1; i <= n; i++){
    int par;
    cin >> par >> c[i];
    e[par].push_back(i);
    if(!par) root = i;
  }

  sf(root);

  vector<int> v;
  for(int i = 1; i <= n; i++) v.push_back(i);
  f(root, v);

  cout << "YES\n";
  for(int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << '\n';

  return 0;
}