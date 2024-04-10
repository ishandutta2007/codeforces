#include <bits/stdc++.h>
using namespace std;

string start[3000], target[3000];
int l[3000], r[3000];

typedef long long ll;

ll base = 257, mod = (1LL<<48)-5;

vector<ll> roll(string s, int k) {
  ll power = 1;
  for (int i = 0; i < k; i++)
    power = (power*base)%mod;
  vector<ll> ret;
  ll h = 0;
  for (int i = 0; i < s.size(); i++) {
    h = (h*base+s[i])%mod;
    if (i >= k) h = (h-power*s[i-k]%mod+mod)%mod;
    if (i >= k-1) {
      ret.push_back(h);
    }
  }
  return ret;
}

void fail() {
  cout << "NO" << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> start[i];
  for (int i = 0; i < n; i++)
    cin >> target[i];
  string replace, replace_with;
  for (int i = 0; i < n; i++) {
    l[i] = 1e9;
    r[i] = -1;
    for (int j = 0; j < start[i].size(); j++)
      if (start[i][j] != target[i][j]) {
	l[i] = min(l[i], j);
	r[i] = max(r[i], j);
      }
    if (r[i] != -1) {
      string substr = start[i].substr(l[i], r[i]-l[i]+1);
      if (!replace.size()) {
	replace = substr;
	replace_with = target[i].substr(l[i], r[i]-l[i]+1);
      } else if (replace != substr) {
	fail();
      }
    }
  }

  while (1) {
    int end = 0;
    set<char> needed;
    char replace_with_char;
    for (int i = 0; i < n; i++) {
      if (r[i] == -1) continue;
      if (r[i]+1 == start[i].size()) end = 1;
      else {
	needed.insert(start[i][r[i]+1]);
	replace_with_char = target[i][r[i]+1];
      }
    }
    if (end || needed.size() != 1) break;
    replace += *needed.begin();
    replace_with += replace_with_char;
    for (int i = 0; i < n; i++) if (r[i] != -1) r[i]++;
  }

  while (1) {
    int end = 0;
    set<char> needed;
    char replace_with_char;
    for (int i = 0; i < n; i++) {
      if (r[i] == -1) continue;
      if (!l[i]) end = 1;
      else {
	needed.insert(start[i][l[i]-1]);
	replace_with_char = target[i][l[i]-1];
      }
    }
    if (end || needed.size() != 1) break;
    replace = *needed.begin()+replace;
    replace_with = replace_with_char+replace_with;
    for (int i = 0; i < n; i++) if (r[i] != -1) l[i]--;
  }

  int k = replace.size();
  ll replace_h = roll(replace, k)[0];
  for (int i = 0; i < n; i++) {
    vector<ll> start_h = roll(start[i], k);
    int found = 1e9;
    for (int i = 0; i < start_h.size(); i++) {
      if (start_h[i] == replace_h) {
	found = i;
	break;
      }
    }
    if (found != l[i]) fail();
  }
  cout << "YES" << endl;
  cout << replace << endl;
  cout << replace_with << endl;
}