#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
  out << v.size() << '\n';
  for(auto e : v) out << e << ' ';
  return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.st << ' ' << p.nd << ')';  
}

const int N = 1010;
int n, k, m, ans = N * N, type;
string s[300 * N], t[300 * N], per;

int cnt(string & s, string & p) {
  int ans = 0;
  for(int i = 0; i < s.size(); i++)
    ans += (s[i] != p[i % 2]);
  return ans;
}

void regen(string patt, int tt) {
  string ch[2], hc[2];
  ch[0] = patt.substr(0, 2);
  ch[1] = patt.substr(2, 2);
  hc[0] += ch[0][1]; hc[0] += ch[0][0];
  hc[1] += ch[1][1]; hc[1] += ch[1][0];

  if(tt == 1)
    for(int i = 0; i < n; i++)
      if(cnt(s[i], ch[i % 2]) < cnt(s[i], hc[i % 2])) {
        for(int j = 0; j <= m; j++)
          s[i][j] = ch[i % 2][j % 2];
      } else {
        for(int j = 0; j <= m; j++)
          s[i][j] = hc[i % 2][j % 2];
      }
  
  if(tt == 2)
    for(int i = 0; i < m; i++)
      if(cnt(t[i], ch[i % 2]) < cnt(t[i], hc[i % 2])) {
        for(int j = 0; j <= n; j++)
          s[j][i] = ch[i % 2][j % 2];
      } else {
        for(int j = 0; j <= n; j++)
          s[j][i] = hc[i % 2][j % 2];
      }
}

void calc(string patt) {
  string ch[2], hc[2];
  ch[0] = patt.substr(0, 2);
  ch[1] = patt.substr(2, 2);
  hc[0] += ch[0][1]; hc[0] += ch[0][0];
  hc[1] += ch[1][1]; hc[1] += ch[1][0];

  int ans1 = 0, ans2 = 0;

  for(int i = 0; i < n; i++)
    ans1 += min(cnt(s[i], ch[i % 2]), cnt(s[i], hc[i % 2]));

  for(int i = 0; i < m; i++)
    ans2 += min(cnt(t[i], ch[i % 2]), cnt(t[i], hc[i % 2]));

  if(ans1 < ans)
    ans = ans1, type = 1, per = patt;

  if(ans2 < ans)
    ans = ans2, type = 2, per = patt;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  
  for(int i = 0; i < n; i++)
    cin >> s[i];

  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      t[i] += s[j][i];

  string ss = "ACGT";
  do {
    calc(ss);
  } while(std::next_permutation(ss.begin(), ss.end()));
  // cout << ans << '\n';

  regen(per, type);
  for(int i = 0; i < n; i++)
    cout << s[i] << '\n';
}