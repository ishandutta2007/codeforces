#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1000;
vector<int> node[nax];
int removed[nax];

void remove(int p, int par) {
  removed[p] = 1;
  for (int i : node[p]) {
    if (i == par || removed[i]) continue;
    remove(i,p);
  }
}

int query(int a, int b) {
  cout << "? " << a+1 << ' ' << b+1 << endl;
  int ret;
  cin >> ret;
  assert(ret != -1);
  return ret-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  int root = -1;
  while (1) {
    int found = 0;
    vector<int> alive;
    for (int i = 0; i < n; i++) {
      if (removed[i]) continue;
      alive.push_back(i);

      vector<int> nbr;
      for (int j : node[i]) if (!removed[j]) nbr.push_back(j);
      if (nbr.size() >= 2) {
	int lca = query(nbr[0], nbr[1]);
	if (lca == i) {
	  remove(nbr[0], i);
	  remove(nbr[1], i);
	} else if (lca == nbr[0]) {
	  remove(i, nbr[0]);
	} else if (lca == nbr[1]) {
	  remove(i, nbr[1]);
	} else assert(0);
	found = 1;
	break;
      }
    }
    if (!found) {
      if (alive.size() >= 2) {
	assert(alive.size() == 2);
	root = query(alive[0], alive[1]);
      } else {
	assert(alive.size() == 1);
	root = alive[0];
      }
      break;
    }
  }
  cout << "! " << root+1 << endl;
}