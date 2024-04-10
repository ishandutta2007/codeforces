#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[500000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) node[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    string s;
    cin >> s;
    int maxdeg = 0;
    for (int i = 0; i < n; i++) maxdeg = max(maxdeg, int(node[i].size()));
    int whites = count(s.begin(), s.end(), 'W');
    if (n <= 3) {
      if (n == 3 && whites == 2) goto win;
      else goto draw;
    }

    if (maxdeg >= 4) goto win;
    if (maxdeg == 2) {
      for (int i = 0; i < n; i++)
	if (s[i] == 'W' && node[i].size() == 2) goto win;
      if (whites == 2 && n%2) goto win;
      else goto draw;
    } else if (maxdeg == 3 && !whites) {
      if (n <= 5) goto draw;
      int triples = 0;
      for (int i = 0; i < n; i++) {
	if (node[i].size() == 3) {
	  int leaves = 0;
	  for (int j : node[i]) leaves += node[j].size()==1;
	  if (leaves <= 1) goto win;
	  triples++;
	}
      }
      if (triples >= 3) goto win;
      if (triples == 2 && n%2) goto win;
      goto draw;
    } else if (maxdeg == 3 && whites) {
      int ok = 0;
      for (int i = 0; i < n; i++)
	if (s[i] == 'W' && node[i].size() >= 2) ok = 1;

      int leaves = 0, triples = 0;
      for (int i = 0; i < n; i++) {
	if (node[i].size() == 3) {
	  for (int j : node[i]) {
	    leaves += node[j].size()==1;
	    if (s[j] == 'W') ok = 1;
	  }
	  triples++;
	}
      }
      if (triples == 1 && leaves == 2 && !ok && n%2) goto draw;
      goto win;
    }
    assert(0);
    continue;
  win:
    cout << "White" << endl;
    continue;
  draw:
    cout << "Draw" << endl;
  }
}