#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(vector<int> a, vector<int> b) {
  cout << "? " << a.size() << ' ' << b.size() << endl;
  for (int i : a) cout << i+1 << ' ';
  cout << endl;
  for (int i : b) cout << i+1 << ' ';
  cout << endl;
  string ans;
  cin >> ans;
  if (ans == "FIRST") return 1;
  else if (ans == "SECOND") return -1;
  else if (ans == "EQUAL") return 0;
  else assert(0);
}

mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int isstone = 1;
    for (int it = 0; it < 20; it++) {
      int j = 1+mrand()%(n-1);
      if (query({0}, {j}) == -1) {
	isstone = 0;
	break;
      }
    }
    if (!isstone) {
      cout << "! 1" << endl;
      continue;
    }
    vector<int> stones = {0};
    vector<int> cands;
    while (1) {
      vector<int> add;
      for (int i = stones.size(); i < (int)stones.size()*2 && i < n; i++)
	add.push_back(i);
      if (add.size() < stones.size()) {
	cands = add;
	break;
      }
      if (query(stones,add) == 1) {
	cands = add;
	break;
      }
      for (int i : add)
	stones.push_back(i);
    }
    while (cands.size() > 1) {
      int m = cands.size()/2;
      vector<int> a, b, c;
      for (int i : stones) {
	if ((int)a.size() == m) break;
	a.push_back(i);
      }
      for (int i : cands) {
	if ((int)b.size() == m) {
	  c.push_back(i);
	} else {
	  b.push_back(i);
	}
      }
      if (query(a, b) == 1) cands = b;
      else cands = c;
    }
    cout << "! " << cands[0]+1 << endl;
  }
}