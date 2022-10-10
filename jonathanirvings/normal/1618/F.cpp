#include <bits/stdc++.h>
using namespace std;

string to_binary(long long x) {
  string s = "";
  while (x > 0) {
    s = (char)(x % 2 + '0') + s;
    x /= 2;
  }
  return s;
}

string t;
set<string> done;
bool ans = 0;

string trim(string s)
{
  while (s.size() > 0 && s.back() == '0') s.pop_back();
  return s;
}

string rev(string s)
{
  s = trim(s);
  reverse(s.begin(), s.end());
  return s;
}

void dfs(string s)
{
  if (done.count(s)) return;
  done.insert(s);
  if (s == t)
  {
    ans = 1;
    return;
  }
  if (t.find(trim(s)) == string::npos && t.find(rev(s)) == string::npos) return;
  dfs(rev(s + '0'));
  if (ans == 0) dfs(rev(s + '1'));
}

int main() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  string s = to_binary(x);
  t = to_binary(y);
  dfs(s);
  puts(ans ? "YES" : "NO");
}