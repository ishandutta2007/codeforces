#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> node[100000];
int depth[100000];
int deg[100000];
int par[100000];
int done[100000];

int main() {
  {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      par[i] = -1;
      deg[i] = node[i].size();
      if (node[i].size() == 1) {
	depth[i] = 1;
	q.push(i);
      }
      else if (node[i].size() == 2) goto fail;
    }
    while (q.size()) {
      int p = q.front();
      q.pop();
      for (int i : node[p]) {
	if (!depth[i]) {
	  depth[i] = depth[p]+1;
	  q.push(i);
	}
	if (depth[i] > depth[p]){
	  par[p] = i;
	  //cout << i+1 << ' ' << p+1 << endl;
	}
      }
    }
    //for (int i = 0; i < n; i++) cout << depth[i] << ' ';
    //cout << endl;
    int ma = 0, mas = 0;
    for (int i = 0; i < n; i++) {
      if (par[i] == -1) ma = depth[i], mas++;
      else if (depth[i]+1 != depth[par[i]]) {
	//cout << i+1 << ' ' << par[i]+1 << endl;
	goto fail;
      }
    }
    for (int i = 0; i < n; i++) {
      if (node[i].size() == 3 && depth[i] != ma) goto fail;
    }
    if (ma != k+1 || mas != 1) goto fail;
    cout << "Yes" << endl;
    return 0;
  }
 fail:
  cout << "No" << endl;
}