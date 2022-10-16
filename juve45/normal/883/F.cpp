#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int i, j, n, p[N], rs;
bool viz[N];
set<string> S[N];
string a[N];

int pfind(int x) { return p[x] == x ? x : p[x] = pfind(p[x]); }

void punite(int x, int y) { p[pfind(x)] = pfind(y); }

void solve(string s, int pz) {
  queue<string> q;

  string aux;
  for(int i = 0; i < s.size(); ++i)
    if(s[i] == 'u') aux += "oo";
    else aux += s[i];

  s = aux; aux = "";
  for(int i = s.size() - 1; i >= 0; --i)
    if(s[i] == 'k') {
      if(aux[aux.size() - 1] == 'h') continue;
      aux += s[i];
    } else aux += s[i];

  reverse(aux.begin(), aux.end());
  S[pz].insert(aux);
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n;
  for(i = 1; i <= n; ++i) cin >> a[i], p[i] = i;

  for(i = 1; i <= n; ++i) solve(a[i], i);

  for(i = 1; i <= n; ++i)
    for(j = i + 1; j <= n; ++j) {
      if(pfind(i) == pfind(j)) continue;
      for(auto it : S[i])
        if(S[j].count(it))
          punite(i, j);
    }

  for(i = 1; i <= n; ++i) viz[pfind(i)] = 1;

  for(i = 1; i <= n; ++i) rs += viz[i];

  cout << rs << '\n';

  return 0;
}