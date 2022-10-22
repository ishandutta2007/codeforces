#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int has(vector<string>&a, int p, char c) {
  if (p == -1) return 0;
  if (c == ' ') return 1;
  return !!count(a[p].begin(), a[p].end(), c) || has(a, p-1, c);
}
int rec(vector<string>&a, int p, char c) {
  if (p == -1) return 0;
  string s = a[p];
  int start = 0;
  while (start < s.size() && s[start] == s[0] && (s[0]==c||c==' ')) start++;
  if (start == s.size()) {
    if (c == ' ' || c == s[0]) {
      return (rec(a, p-1, s[0])+1)*(s.size()+1)-1;
    } else {
      return has(a, p-1, c);
    }
  }
  int end = s.size()-1;
  while (end > -1 && s[end] == s[s.size()-1] && (s[s.size()-1]==c||c==' ')) end--;
  end = s.size()-1-end;

  int streak = 0, maxstreak = 0;
  char last = ' ';
  for (char i : s) {
    if (i == last) streak += i==c||c==' ';
    else streak = i==c||c==' ';
    maxstreak = max(maxstreak, streak);
    last = i;
  }
  int ans = maxstreak;
  if (c == ' ') {
    if (has(a, p-1, s[0]))
      ans = max(ans, start+1+(s[0] == s[s.size()-1])*end);
    if (has(a, p-1, s[s.size()-1]))
      ans = max(ans, end+1+(s[0] == s[s.size()-1])*start);
  } else if (has(a, p-1, c))
    ans = max(ans, start+end+1);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (string&s : a) cin >> s;
  cout << rec(a, n-1, ' ') << endl;
}