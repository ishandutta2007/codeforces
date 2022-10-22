#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string t;
    cin >> t;
    int n = t.size();
    string rem;
    int cnt[256] = {};
    for (int i = n-1; i >= 0; i--) {
      if (!count(rem.begin(), rem.end(), t[i]))
        rem += t[i];
      cnt[(int)t[i]]++;
    }
    reverse(rem.begin(), rem.end());
    int len = 0;
    for (int i = 0; i < (int)rem.size(); i++) {
      if (cnt[(int)rem[i]]%(i+1)) goto fail;
      len += cnt[(int)rem[i]]/(i+1);
    }
    {
      string s = t.substr(0, len), cp = s;
      string newt;
      for (char c : rem) {
        newt += cp;
        string ncp;
        for (char d : cp) 
          if (d != c) ncp += d;
        if (cp.size() == ncp.size()) goto fail;
        cp = ncp;
      }
      if (newt != t || cp.size()) goto fail;
      cout << s << ' ' << rem << endl;
      continue;
    }
fail:
    cout << -1 << endl;
  }
}