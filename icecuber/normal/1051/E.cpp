#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cmp(string&text, int i, string&key, int overlap) {
  if (overlap == key.size()) return 0;
  assert(overlap+i < text.size());
  assert(overlap < key.size());
  return text[overlap+i] < key[overlap] ? -1 : 1;
}

vector<int> matchlen(string&text, string&key) {
  string sum = key+'@'+text;
  vector<int> z(sum.size(),0);
  int l = 0, r = 0;
  for (int i = 1; i < sum.size(); i++) {
    if (z[i-l] < r-i) {
      z[i] = z[i-l];
    } else {
      r = max(r,i);
      l = i;
      while (r < sum.size() && sum[r-i] == sum[r]) r++;
      z[i] = r-i;
    }
  }
  /*for (int i : z) {
    cerr << i << ' ';
  }
  cerr << endl;*/
  vector<int> ret((int)text.size()+1, 0);
  for (int i = key.size(); i <= text.size(); i++) {
    ret[i-(int)key.size()] = z[i+1];
  }
  return ret;
}

vector<int> matchlen_brute(string&text, string&key) {
  vector<int> r;
  for (int i = 0; i+key.size() <= text.size(); i++) {
    int j = 0;
    while (j < key.size() && text[i+j] == key[j]) j++;
    r.push_back(j);
  }
  return r;
}

int main() {
  if (0) {
    string a = "abababababbbababaabbabaaabbabababbsvadfvsxccababbaababbabbacbcabbaba", b = "abbaba";
    //string b = "aabcaab", a = "aaaz";
    //string a = "abab", b = "ab";
    auto ma = matchlen(a, b);
    auto mb = matchlen_brute(a,b);
    for (int i : ma) cout << i << ' '; cout << endl;
    for (int i : mb) cout << i << ' '; cout << endl;
    assert(ma == mb);
    return 0;
  }
  ios::sync_with_stdio(0); cin.tie(0);
  string s, l, r;
  cin >> s >> l >> r;
  vector<int> matchl = matchlen(s, l), matchr = matchlen(s, r);
  int n = s.size();
  ll mod = 998244353;
  vector<ll> dp(n+1,0);
  dp[n] = 1;
  assert((int)matchl.size() > n-int(l.size()));
  assert((int)matchr.size() > n-int(r.size()));
  for (int i = n-1; i >= 0; i--) {
    (dp[i] += dp[i+1]) %= mod;

    int mi = l.size(), ma = r.size();
    //if (i+l.size() <= n && s.substr(i,l.size()) < l) mi++;
    //if (i+r.size() <= n && s.substr(i,r.size()) > r) ma--;
    if (i+l.size() <= n && cmp(s, i, l, matchl[i]) == -1) mi++;
    if (i+r.size() <= n && cmp(s, i, r, matchr[i]) ==  1) ma--;
    if (s[i] == '0') {
      ma = min(ma, 1);
    }
    if (ma >= mi) {
      if (i+mi <= n)
	(dp[i] += dp[i+mi]) %= mod;
      if (i+ma+1 <= n)
	(dp[i] -= dp[i+ma+1]) %= mod;
    }
    //for (int j = mi; j <= ma; j++)
    //  (dp[i] += dp[i+j]) %= mod;

    /*for (int j = 1; j+i <= n && (s[i] != '0' || j == 1); j++) {
      if ((j > l.size() || j == l.size() && s.substr(i,j) >= l) &&
      (j < r.size() || j == r.size() && s.substr(i,j) <= r))
      (dp[i] += dp[i+j]) %= mod;
      }*/
  }
  cout << (dp[0]-dp[1]+mod*2)%mod << endl;
}