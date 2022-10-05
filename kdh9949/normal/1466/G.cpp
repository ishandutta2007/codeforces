#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

// kmp -> operates in O(|s| + |t|)
int find_occurrences(string s, string t) {
  int n = s.length(), m = t.length();
  s = " " + s;
  t = " " + t;
  vint fa(m + 1);
  for(int i = 2, k = 0; i <= m; i++) {
    while (k && t[k + 1] != t[i]) k = fa[k];
    if (t[k + 1] == t[i]) k++;
    fa[i] = k;
  }
  int r = 0;
  for(int i = 1, k = 0; i <= n; i++) {
    while (k && t[k + 1] != s[i]) k = fa[k];
    if(t[k + 1] == s[i]) k++;
    if(k == m) { k = fa[k]; r++; }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  const static ll M = ll(1e9) + 7;

  ints(n, q);
  string s0, t;
  cin >> s0 >> t;

  vll p2(n + 1, 1);
  for(int i = 1; i <= n; i++) p2[i] = p2[i - 1] * 2 % M;
  vector<vll> acnt(26, vll(n + 1));
  for(int i = 1; i <= n; i++) {
    if(i) for(int j = 0; j < 26; j++) acnt[j][i] = acnt[j][i - 1] * 2 % M;
    ++acnt[t[i - 1] - 'a'][i] %= M; 
  }

  while(q--) {
    ints(k);
    string p;
    cin >> p;
    string s = s0;
    int c = 0;
    while(c < k && s.length() < p.length()) s = s + t[c++] + s;
    if(s.length() < p.length()) { cout << "0\n"; continue; }
    ll ans = find_occurrences(s, p) * p2[k - c] % M;
    if(c < k) {
      s = s + t[c] + s;
      int plen = p.length();
      int smid = int(s.size()) / 2;
      for(int i = 0; i < 26; i++) {
        ll ccnt = (acnt[i][k] - p2[k - c] * acnt[i][c] % M + M) % M;
        s[smid] = 'a' + i;
        ans = (ans + ccnt * find_occurrences(s.substr(smid - plen + 1, 2 * plen - 1), p)) % M;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}