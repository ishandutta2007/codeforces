#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> pink[100000];
vector<int> rpink[100000];

int done0[100000];
int topo[100000], topos = 0;
void dfs0(int p) {
  if (done0[p]++) return;
  for (int i : pink[p]) dfs0(i);
  topo[topos++] = p;
}

int done1[100000];
int component[100000], components = 0;

vector<int> clist[100000];
void dfs1(int p) {
  if (done1[p]++) return;
  for (int i : rpink[p]) dfs1(i);
  clist[components].push_back(p);
  component[p] = components;
}


int indeg[100000];
vector<int> node[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    //cerr << "Client: " << a << ' ' << b << endl;
    a--, b--;
    pink[a].push_back(b);
    rpink[b].push_back(a);
  }
  for (int i = 0; i < n; i++)
    dfs0(i);

  components = 0;
  for (int i = n-1; i >= 0; i--) {
    if (done1[topo[i]]) continue;
    dfs1(topo[i]);
    components++;
  }

  set<int> active;
  for (int i = 0; i < n; i++) {
    int a = component[i];
    for (int j : pink[i]) {
      int b = component[j];
      if (a != b) {
	node[a].push_back(b);
	indeg[b]++;
      }
    }
  }

  //cerr << "Components: " << components << endl;
  for (int i = 0; i < components; i++)
    if (!indeg[i]) active.insert(i);
  /*cerr << "Active: ";
  for (int i : active) {
    for (int j : clist[i])
      cerr << j << ' ';
    cerr << ", ";
  }
  cerr << endl;*/

  while (active.size() > 1) {

    int ca = *active.begin(), cb = *active.rbegin();
    int a = clist[ca].back();
    int b = clist[cb].back();
    cout << "? " << a+1 << ' ' << b+1 << endl;
    int is_edge;
    cin >> is_edge;
    //cerr << "client ? " << a << ' ' << b << ' ' << is_edge << endl;
    int to_remove = is_edge ? cb : ca;
    clist[to_remove].pop_back();
    if (clist[to_remove].empty()) {
      active.erase(to_remove);
      for (int i : node[to_remove])
	if (!--indeg[i])
	  active.insert(i);
    }
  }
  cout << "! " << clist[*active.begin()].back()+1 << endl;
  //cerr << *active.begin()+1 << endl;
  //cerr << "Client done!" << endl;
}