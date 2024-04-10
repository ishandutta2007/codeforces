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
#define all(v) v.begin(),v.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) {
    string s;
    cin >> s;

    int n = s.length();
    vector<char> st;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'A') st.push_back(s[i]);
      else {
        if(!st.empty() && st.back() == 'A') st.pop_back();
        else st.push_back(s[i]);
      }
    }

    int ans = st.size();
    for(int i = 0; i + 1 < st.size(); i += 2) {
      if(st[i] == 'B' && st[i + 1] == 'B') ans -= 2;
      else break;
    }
    cout << ans << '\n';
  }

  return 0;
}