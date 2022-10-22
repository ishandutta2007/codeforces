#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<string,int>,int> mem;
int brute(string s, int turn = 0) {
  auto [it, inserted] = mem.insert({{s,turn},-1});
  if (inserted) {
    int win = 0;
    char c = "RB"[turn];
    for (int i = 0; i+1 < (int)s.size(); i++) {
      if (s[i] == c || s[i+1] == c) {
        string cp = s;
        cp[i] = cp[i+1] = 'W';
        win |= !brute(cp, !turn);
      }
    }
    it->second = win;
  }
  return it->second;
}

vector<pair<char,int>> streaks(string s) {
  int n = s.size();
  vector<pair<char,int>> a;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (i == n || s[i] == s[i-1]) {
      if ((i-last)%2)
        a.push_back({s[last], i-last});
      else
        a.push_back({'W', i-last});
      last = i;
    }
  }
  return a;
}

const int nax = 1e3;
int nim[nax];
const int mod = 34*2;

int fast(string s) {
  int n = s.size();
  int R = count(s.begin(), s.end(), 'R');
  if (R*2 > n) return 1;
  if (R*2 < n) return 0;
  int sum = 0;
  for (auto [c,l] : streaks(s)) {
    sum ^= nim[l%mod+mod*(l>=mod)];
  }
  return sum != 0;
}

int main() {
  for (int i = 1; i < nax; i++) {
    int r = 2;
    set<int> s;
    for (int j = 0; j <= i-r-j; j++) {
      s.insert(nim[j]^nim[i-r-j]);
    }
    int mex = 0;
    while (s.count(mex)) mex++;
    nim[i] = mex;
    //if (!nim[i]) cout << i << ' ';
    /*if (nim[i] != nim[i%mod+mod*(i>=mod)]) {
      cout << i << ' ' << nim[i] << ' ' << nim[i%mod+mod] << endl;
    }*/
  }
  if (0) {
    set<vector<pair<char,int>>> seen;
    for (int n = 2; n <= 14; n += 2) {
      for (int m = 0; m < 1<<n; m++) {
        if (__builtin_popcount(m)*2 != n) continue;
        string s;
        for (int i = 0; i < n; i++) {
          s += "RB"[m>>i&1];
        }
        if (brute(s) != fast(s)) {
          auto A = streaks(s);
          sort(A.begin(), A.end());
            for (auto [c,l] : A) cout << c << '-' << l << ' ';
          cout << endl;
          exit(0);
        }
        continue;
        if (brute(s) == 0) {
          auto A = streaks(s);
          sort(A.begin(), A.end());
          if (count(A.begin(), A.end(), make_pair('R',1)) && 
              count(A.begin(), A.end(), make_pair('B',1))) continue;
          if (count(A.begin(), A.end(), make_pair('W',2)) > 1) continue;
          if (seen.insert(A).second) {
            for (auto [c,l] : A) cout << c << '-' << l << ' ';
            cout << endl;
          }
        }
      }
    }
    //cout << brute("RBRBRBRBRRBB", 0) << endl;
    //cout << brute("RBRBRBRBRWWB", 1) << endl;
    return 0;
  }
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (fast(s) ? "Alice" : "Bob") << endl;
  }
}