// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (n % k) {
      cout << "-1\n";
      continue;
    }

    vector<int> c(26);
    for (char x : s) {
      c[x-'a']++;
    }

    // dobar odmah?
    if (all_of(begin(c), end(c), [&](int x) { return x % k == 0; })) {
      cout << s << '\n';
      continue;
    }

    auto fale = [&]() {
      int fale = 0;
      for (int j=0; j<26; j++) {
        if (c[j] % k) {
          fale += k - c[j] % k;
        }
      }
      return fale;
    };

    bool solved = 0;
    // pozicija gde povecavamo string
    for (int i=n-1; i>=0 && !solved; i--) {
      c[s[i]-'a']--;

      // koliko slova nam fale
      if (i + fale() > n) {
        continue;
      }

      // da li mogu da napravim veci?
      for (int j=s[i]-'a'+1; j<26; j++) {
        c[j]++;
        if (i + 1 + fale() <= n) {
          // moze!
          cout << s.substr(0, i);
          cout << char(j + 'a');

          cout << string(n - i - 1 - fale(), 'a');
          for (int i=0; i<26; i++) {
            if (c[i] % k) {
              cout << string(k - c[i] % k, char(i + 'a'));
            }
          }
          cout << '\n';

          solved = 1;
          break;
        } else {
          c[j]--;
        }
      }
    }

    if (!solved) {
      cout << "-1\n";
    }
  }
}