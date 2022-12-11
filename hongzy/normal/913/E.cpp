#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

string ans[512][3];
bool mark;
void chk(string &t, string s) {
  if(!t.size() || s.size() < t.size() || (s.size() == t.size() && s < t)) {
    t = s; mark = 1;
  }
}
int main() {
  ans[0b00001111][0] = "x";
  ans[0b00110011][0] = "y";
  ans[0b01010101][0] = "z";
  mark = 1;
  while(mark) {
    mark = 0;
    rep(i, 0, 255) rep(j, 0, 2) if(ans[i][j].size()) {
      string s = ans[i][j];
      if(j) s = '(' + s + ')';
      s = '!' + s;
      chk(ans[i ^ 255][0], s);
      rep(u, 0, 255) rep(v, 0, 2) if(ans[u][v].size()) {
        rep(op, 1, 2) {
          string s = (op < j ? '(' + ans[i][j] + ')' : ans[i][j]) + (op == 1 ? '&' : '|') + (op < v ? '(' + ans[u][v] + ')' : ans[u][v]);
          chk(ans[op == 1 ? (i & u) : (i | u)][op], s);
        }        
      }
    }
  }
  int test; scanf("%d", &test);
  while(test --) {
    char op[12]; scanf("%s", op + 1);
    int z = 0;
    rep(i, 1, 8) z = z << 1 | (op[i] & 1);
    string res = ans[z][0];
    chk(res, ans[z][1]);
    chk(res, ans[z][2]);
    puts(res.c_str());
  }
  return 0;
}