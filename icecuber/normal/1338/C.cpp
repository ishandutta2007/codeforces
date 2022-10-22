#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll g(ll n) {
  if (n == 0) return 0;
  ll a[4] = {0,3,1,2};
  return g(n/4)*4+a[n%4];
}

ll f(ll n) {
  n--;
  ll r = n%3;
  n /= 3;
  ll off = 0;
  while (n >= 1ll<<off*2) n -= 1ll<<off*2, off++;
  ll a = (1ll<<off*2)+n;
  ll c = (3ll<<off*2)+g(n);
  ll b = a^c;
  ll ans[3] = {a,b,c};
  return ans[r];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    cout << f(n) << '\n';
  }
  /*
  int m = 1000;
  set<int> left;
  for (int i = 1; i <= m; i++) left.insert(i);
  vector<int> s;
  while (1) {
    tuple<int,int,int> best = {m+1,m+1,m+1};
    for (int a : left) {
      for (int b : left) {
	int c = a^b;
	if (left.count(c))
	  best = min(best, make_tuple(a,b,c));
      }
    }
    {
      auto [a,b,c] = best;
      if (c > m/3) break;
      if (a == m+1) break;
      for (int v : {a,b,c}) {
	s.push_back(v);
	left.erase(v);
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (f(i+1) != s[i]) {
      cout << i << ' ' << f(i+1) << ' ' << s[i] << endl;
      return 0;
    }
  }
  cout << "OK" << endl;
  return 0;
  for (int i = 0; i < s.size(); i += 3) {
    if ((s[i]&(s[i]-1)) == 0) cout << endl;
    int a = s[i], b = s[i+1], c = s[i+2];
    int x = 1<<31-__builtin_clz(a);
    a -= x, b -= x*2, c -= x*3;
    cout << a << ' ' << b << ' ' << c << "   ";
    //cout << bitset<10>(s[i]) << ' ' << bitset<10>(s[i+1]) << ' ' << bitset<10>(s[i+2]) << endl;//"   ";
  }
  //for (int v : s) cout << bitset<10>(v) << endl;
  cout << endl;*/
}