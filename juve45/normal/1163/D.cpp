#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 55;
int n, la[N], lb[N], dp[N * N][N][N], ans = -10000;
string s, a, b;

void lPreSuf(int * lps, const string &s) { 
  int n = s.length(), len = 0; 
  lps[0] = 0; 
  
  int i = 1; 
  while (i < n)  { 
    if (s[i] == s[len])  { 
      len++; 
      lps[i] = len; 
      i++; 
    } 
    else { 
      if (len != 0) 
        len = lps[len-1]; 
      else // if (len == 0) 
      { 
        lps[i] = 0; 
        i++; 
      } 
    } 
  } 
  // lps[0] = -1;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin >> s >> a >> b;

  lPreSuf(la, a);
  lPreSuf(lb, b);

  dbg_v(la, 3);
  dbg_v(lb, 3);

  for(int i = 0; i <= s.size(); i++)
    for(int j = 0; j <= a.size(); j++)
      for(int  k = 0; k < b.size(); k++)
        dp[i][j][k] = -100000;

  dp[0][0][0] = 0;

  for(int i = 0; i <= s.size(); i++)
    for(int j = 0; j < a.size(); j++)
      for(int k = 0; k < b.size(); k++) {
        // char c = '*';
        // if(s[i] != '*') c = s[i];
        // if(j > 0)
        // if(s[i] == '*')  {
        //   if(k == 0 || j == 0 || bad[k - 1] == good[j - 1])
        // }
        // if(k > 0 && bad[k - 1] != )
        // dbg(i,j,k, dp[i][j][k]);
        if(i == s.size()) {
          ans = max(ans, dp[i][j][k]);
          continue;
        }

        for(char c = 'a'; c <= 'z'; c++) {
          if(s[i] != '*' && s[i] != c) continue;

          // if(i == 3)
          // dbg(c);

          int add = 0;
          int jj = j;
          while(jj > 0 && a[jj] != c)  {

            // if(c == 'c') dbg(jj), dbg(a[jj - 1]);
            jj = la[jj - 1];
          }
          if(a[jj] == c) jj++;
          // if(c == 'c') dbg(jj);
          
          if(jj == a.size()) {
            jj = la[jj - 1];
            add++;
          }

          int kk = k;
          while(kk > 0 && b[kk] != c) {
            kk = lb[kk - 1];
          }
          if(b[kk] == c) kk++;
          if(kk == b.size()) {
            kk = lb[kk - 1];
            add--;
          }

          // jj = max(0, jj);
          // kk = max(0, kk);
          // dbg(c, jj, kk, add);
          dp[i + 1][jj][kk] = max(dp[i + 1][jj][kk], dp[i][j][k] + add);
        }
      }
  cout << ans << '\n';
}