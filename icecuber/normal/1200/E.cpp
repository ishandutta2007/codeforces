#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
ll mod = mrand()&(1ll<<48)-1 | 1ll<<48, base = 256;

void merge(string&a, string&b) {
  ll ha = 0, hb = 0;
  int overlap = 0;
  ll base_pow = 1;
  for (int l = 0; l < a.size() && l < b.size(); l++) {
    ha = ( ha+(a.end()[-l-1])*base_pow )%mod;
    hb = ( hb*base+b[l] )%mod;
    if (ha == hb) overlap = l+1;
    base_pow = base_pow*base%mod;
  }
  a += b.substr(overlap,(int)b.size()-overlap);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string a;
  cin >> a;
  for (int i = 1; i < n; i++) {
    string b;
    cin >> b;
    merge(a,b);
  }
  cout << a << endl;
}