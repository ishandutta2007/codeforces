#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
https://codeforces.com/contest/906/problem/D
https://github.com/ShahjalalShohag/code-library/blob/master/Number%20Theory/Power%20Tower.cpp
*/
map<int, int> mp;
int phi(int n) {
  if (mp.count(n)) return mp[n];
  int ans = n, m = n;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) m /= i;
      ans = ans / i * (i - 1);
    }
  }
  if (m > 1) ans = ans / m * (m - 1);
  return mp[n] = ans;
}
inline int MOD(int x, int m) {
  if (x < m) return x;
  return x % m + m;
}
int power(int n, int k, int mod) {
  int ans = MOD(1, mod);
  while (k) {
    if (k & 1) ans = MOD(ans * n, mod);
    n = MOD(n * n, mod);
    k >>= 1;
  }
  return ans;
}
int a[1000005];
// if x >= log2(m), then a^x = a^(MOD(x, phi(m))) % m
int yo(int l, int r, int m) {
  if (l == r) return MOD(a[l], m);
  if (m == 1) return 1;
  return power(a[l], yo(l + 1, r, phi(m)), m); 
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << yo(l,r,m)%m << "\n";
	}
	return 0;
}