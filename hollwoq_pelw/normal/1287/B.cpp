#include <bits/stdc++.h>
using namespace std;

const int N = 1505;

string s[N];
map<string, int> cnt;
int n, k;

void work() {
  long long ret = 0;

  for (int i = 0 ; i < n ; i++) {
    for (int j = i+1 ; j < n ; j++) {
      string cur = "";

      for (int kk = 0 ; kk < k ; kk++) {
        if (s[i][kk] == s[j][kk]) {
          cur += s[i][kk];
        } else {
          if ('S' != s[i][kk] && 'S' != s[j][kk]) {
            cur += 'S';
          }         
          if ('E' != s[i][kk] && 'E' != s[j][kk]) {
            cur += 'E';
          }
          if ('T' != s[i][kk] && 'T' != s[j][kk]) {
            cur += 'T';
          }
        }
      }

      if (cnt.count(cur)) {
        ret += cnt[cur];
      }
    }

    cnt[s[i]]++;
  }

  cout << ret << endl;
}

int main() {
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) {
        cin >> s[i];
    }
    work();
    return 0;
}