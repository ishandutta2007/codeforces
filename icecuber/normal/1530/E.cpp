#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    map<char,int> cnt;
    for (char c : s) cnt[c]++;
    if (cnt.size() == 1) {
      cout << s << endl;
      continue;
    }
    
    char unique = 0;
    for (auto [c,k] : cnt) {
      if (k == 1) {
        unique = c;
        break;
      }
    }
    if (unique) {
      cout << unique;
      for (auto [c,k] : cnt) {
        if (c != unique) cout << string(k,c);
      }
      cout << endl;
      continue;
    }

    {
      int as = cnt.begin()->second;
      if (as > 1 && (int)s.size()-as >= as-2) {
        char a = cnt.begin()->first;
        string r;
        for (auto [c,k] : cnt) {
          if (c != a) r += string(k,c);
        }
        cout << a << a;
        for (int i = 0; i < as-2; i++) {
          cout << r[i] << a;
        }
        cout << r.substr(as-2) << endl;
        continue;
      }
    }

    //start with ab
    char a = cnt.begin()->first;
    char b = next(cnt.begin())->first;
    if (cnt.size() == 2) {
      cout << a << string(cnt[b],b) << string(cnt[a]-1,a) << endl;
      continue;
    }

    char c = next(next(cnt.begin()))->first;
    cout << a << b << string(cnt[a]-1,a) << c;
    cnt[b]--, cnt[c]--;
    cnt[a] = 0;
    for (auto [C,k] : cnt)
      cout << string(k,C);
    cout << endl;
  }
}