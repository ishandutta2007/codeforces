#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;
int a[200000];

ll inv(ll a) {
  ll p = mod-2;
  ll r = 1;
  while (p) {
    if (p&1) r = (r*a)%mod;
    a = (a*a)%mod;
    p >>= 1;
  }
  return r;
}

struct Fenwick {
  int n;
  ll*data;
  Fenwick(int n_) {
    n = n_+10;
    data = new ll[n]();
  }
  void add(int i, int v) {
    for (i+=5; i < n; i += i&-i) data[i] += v;
  }
  int sum(int i) {
    ll r = 0;
    for (i+=5; i; i -= i&-i) r += data[i];
    return r;
  }
};

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(i);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] != -2) s.erase(a[i]);
  }
  Fenwick seen(n), notseen(n);
  for (int i : s) notseen.add(i,1);
  ll tot_blanks = s.size();
  ll iblanks = inv(tot_blanks), ans = 0;
  ll blanks = 0;
  for (int i = n-1; i >= 0; i--) {
    if (a[i] == -2) {
      blanks++;
    } else {
      ans = (ans+seen.sum(a[i]))%mod;
      ll c = notseen.sum(a[i]);
      ans = (ans+c*iblanks%mod*blanks)%mod;
      ans = (ans+(tot_blanks-c)*iblanks%mod*(tot_blanks-blanks))%mod;
      seen.add(a[i],1);
    }
  }
  ans += blanks*(blanks-1)%mod*inv(4)%mod;
  cout << (ans%mod+mod)%mod << endl;
}