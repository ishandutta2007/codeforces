#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string operator*(string s, int m) {
  string r;
  for (int i = 0; i < m; i++)
    r += s;
  return r;
}

bool cmp(string a, string b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a <= b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int m = (s.size()+n-1)/n;
  if (s.size()%n == 0) {
    string ans = s.substr(0,n);
    if (cmp(ans*m, s)) {
      if (count(s.begin(), s.end(), '9') == s.size()) {
	ans = "1"+string("0")*(n-1);
	m++;
      } else {
	int i = n-1;
	while (ans[i] == '9') {
	  ans[i] = '0';
	  i--;
	}
	ans[i]++;
      }
    }
    cout << ans*m << endl;
  } else {
    string ans = "1"+string("0")*(n-1);
    cout << ans*m << endl;
  }
}