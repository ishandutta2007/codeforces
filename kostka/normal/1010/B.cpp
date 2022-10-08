//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int ask(int x) {
  cout << x << endl;
  int ret;
  cin >> ret;
  assert(ret != -2);
  if(ret == 0) exit(0);
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  int m, n;
  cin >> m >> n;
  vector <int> ans(n);
  for(int i=0; i<n; i++) ans[i] = ask(1);
  int l = 1, r = m+1, tr = 0;
  while(r - l > 1) {
    int med = (l+r)>>1;
    int w = ask(med) * ans[tr++];
    tr %= n;
    if(w == 1) l = med;
    else r = med;
  }
  assert(ask(l) == 0);
  return 0;
}