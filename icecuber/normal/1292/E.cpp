#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string convert(string s) {
  string r;
  for (char c : s) {
    if (c == 'a') r += 'C';
    else if (c == 'b') r += 'H';
    else if (c == 'c') r += 'O';
    else assert(0);
  }
  return r;
}

string ans;
vector<int> query(string s) {
  cout << "? " << convert(s) << endl;
  int k;
  cin >> k;
  if (k == -1) exit(0);
  vector<int> r(k);
  for (int&v : r) {
    cin >> v;
    v--;
    for (int i = 0; i < (int)s.size(); i++) {
      ans[v+i] = s[i];
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ans.assign(n, 0);

    for (string s : {"ab", "ac", "aaa"}) {
      vector<int> pos = query(s);
      if (pos.size()) {
	int l = pos[0];
	int r = l+s.size();
	while (r < n) {
	  for (char c : "abc") {
	    ans[r] = c;
	    if (c == 'c') break;
	    vector<int> v = query(ans.substr(l, r-l+1));
	    if (count(v.begin(), v.end(), l)) break;
	  }
	  r++;
	}
	while (l) {
	  for (char c : "abc") {
	    ans[l-1] = c;
	    if (c == 'c') break;
	    vector<int> v = query(ans.substr(l-1, r-l+1));
	    if (count(v.begin(), v.end(), l-1)) break;
	  }
	  l--;
	}
	goto finish;
      }
    }

    {
      for (string s : {"bc", "cb", "bba", "cca"}) query(s);
      char last = 0;
      for (int i = n-1; i >= 0; i--) {
	if (ans[i]) last = ans[i];
	ans[i] = last;
      }
      int last_known = n-1;
      while (last_known >= 0 && !ans[last_known]) last_known--;
      string options;
      if (last_known == -1) options = "bc";
      else if (ans[last_known] == 'b') options = "ab";
      else options = "ac";

      for (char c : options) {
	for (int i = last_known+1; i < n; i++)
	  ans[i] = c;
	if (c == options[1] || query(ans).size()) break;
      }
    }

    finish:

    cout << "! " << convert(ans) << endl;
    int good;
    cin >> good;
    if (!good) exit(0);
  }
}