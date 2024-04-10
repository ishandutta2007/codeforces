#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int backup[500001];
int kmp(string s) {
  backup[0] = -1;
  int p = -1;
  for (int i = 1; i <= s.size(); i++) {
    while (p > -1 && s[i-1] != s[p])
      p = backup[p];
    backup[i] = ++p;
  }
  // for (int i = 1; i <= n; i++)
  //   cout << backup[i] << ' ';
  // cout << endl;
  return backup[s.size()];
}

// _AAACAAAAAC
// 0012

//Largest positive x so s[:x] == s[x:i]
int f(string s, int i) {
  if (i <= 1) return 0;
  int p = f(s,i-1);
  if (s[p] == s[i-1]) return p+1;
  p = f(s,p);
  if (s[p] == s[i-1]) return p+1;
  p = f(s,p);
  if (s[p] == s[i-1]) return p+1;
  p = f(s,p);
  if (s[p] == s[i-1]) return p+1;
  return 0;
}

int main() {
  /*  kmp("AAACAAAAAC");
  for (int i = 1; i <= 10; i++)
    cout << f("AAACAAAAAC", i) << ' ';
  cout << endl;
  return 0;*/
  ios::sync_with_stdio(0); cin.tie(0);
  string s, t;
  cin >> s >> t;
  int count[2] = {};
  for (char c : s)
    count[c-'0']++;

  int x = kmp(t);
  int base[2] = {}, extra[2] = {};
  for (int i = 0; i < x; i++)
    count[t[i]=='1']--;
  for (int i = x; i < t.size(); i++)
    extra[t[i]=='1']++;

  string ans;
  int occs = 0;
  while (count[0] >= extra[0] && count[1] >= extra[1])
    count[0] -= extra[0], count[1] -= extra[1], occs++;
  if (occs == 0) ans = s;
  else {
    ans = t.substr(0,x);
    for (int i = 0; i < occs; i++)
      ans += t.substr(x,t.size()-x);
    for (int i = 0; i < count[0]; i++)
      ans += '0';
    for (int i = 0; i < count[1]; i++)
      ans += '1';
  }
  cout << ans << endl;
}