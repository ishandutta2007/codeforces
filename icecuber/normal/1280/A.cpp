#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x;
    string s;
    cin >> x >> s;
    int l = 0;
    ll len = s.size(), mod = 1e9+7;
    while (l < x) {
      int cp = s[l]-'1';
      l++;
      if (cp) {
	if (s.size() < x) {
	  string add = s.substr(l,s.size()-l);
	  for (int j = 0; j < cp; j++)
	    s += add;
	}
	(len += (len-l)*cp) %= mod;
      }
    }
    cout << (len%mod+mod)%mod << endl;
  }
}