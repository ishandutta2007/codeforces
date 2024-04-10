#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

bool query(vector<int> s) {
  printf("? %d", int(s.size()));
  rep(i, 0, int(s.size())-1)
    printf(" %d", s[i]);
  puts("");
  fflush(stdout);
  char op[5];
  scanf("%s", op);
  return *op == 'Y';
}
void report(int s0) {
  printf("! %d\n", s0);
  fflush(stdout);
}
void attempt(int s0, int s1) {
  report(s0);
  char op[5];
  scanf("%s", op);
  if(op[1] == '(')
    report(s1);
}
void solve(vector<int> s) {
  if(s.size() == 1) return report(s[0]);
  if(s.size() == 2) return attempt(s[0], s[1]);
  if(s.size() == 3) {
    bool q1 = query({s[0]}), q2 = query({s[1]}), q3 = query({s[1]}), q4 = query({s[0]});
    if(q2 == q3)
      return q2 ? report(s[1]) : attempt(s[0], s[2]);
    if((q1 && q2) || (q3 && q4))
      return attempt(s[0], s[1]);
    return attempt(s[1], s[2]);
  }
  vector<int> s1, s2;
  for(int i = 0; i < s.size(); i += 2)
    s1.pb(s[i]);
  for(int i = 0; i < s.size(); i += 4) {
    s2.pb(s[i]);
    if(i + 3 < s.size())
      s2.pb(s[i + 3]);
  }
  bool q1 = query(s1), q2 = query(s2);
  if(!q1) {
    s1.clear();
    for(int i = 1; i < s.size(); i += 2)
      s1.pb(s[i]);
  }
  if(!q2) {
    s2.clear();
    for(int i = 0; i < s.size(); i += 4) {
      if(i + 1 < s.size())
        s2.pb(s[i + 1]);
      if(i + 2 < s.size())
        s2.pb(s[i + 2]);
    }
  }
  vector<int> v(s1.size() + s2.size());
  merge(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  return solve(v);
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> s;
  rep(i, 1, n) s.pb(i);
  solve(s);
  return 0;
}