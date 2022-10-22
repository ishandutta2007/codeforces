#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100000];
int done[100000];
int ans[100000];
int found;

void findcycle(int p, int par = -1) {
  if (done[p]++) {
    found = p;
    return;
  }
  for (int i : node[p]) {
    if (i == par) continue;
    findcycle(i,p);
    if (found != -1) {
      if (found != -2) {
	ans[p] = 1;
	if (found == p)
	  found = -2;
      }
      return;
    }
  }
}

int p30;
void dfs3(int p, int par = -1) {
  if (done[p]++) return;
  if (p != p30 && node[p].size() == 3) {
    ans[p] = 2;
    for (int i : node[p]) ans[i] = 1;
    found = 1;
    return;
  }
  for (int i : node[p]) {
    if (i == par) continue;
    dfs3(i,p);
    if (found) {
      ans[p] = 2;
      if (p == p30)
	for (int i : node[p])
	  if (!ans[i])
	    ans[i] = 1;
      return;
    }
  }
}

void dfs(vector<int>&v, int p, int par) {
  if (done[p]++) return;
  //cout << p << ' ' << par << endl;
  v.push_back(p);
  for (int i : node[p]) {
    if (i == par) continue;
    //cout << i << ' ' << p << endl;
    dfs(v,i,p);
  }
}

bool lengthcmp(const vector<int>&a, const vector<int>&b) {
  return a.size() < b.size();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    found = -1;
    for (int i = 0; i < n; i++)
      ans[i] = done[i] = 0, node[i].clear();
    while (m--) {
      int a, b;
      cin >> a >> b;
      a--,b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      findcycle(i);
      if (found != -1)
	goto print;
    }

    for (int i = 0; i < n; i++) {
      if (node[i].size() >= 4) {
	ans[i] = 2;
	for (int j : node[i])
	  ans[j] = 1;
	goto print;
      }
    }

    for (int i = 0; i < n; i++) done[i] = 0;
    for (int i = 0; i < n; i++) {
      if (done[i] || node[i].size() != 3) continue;
      p30 = i;
      found = 0;
      dfs3(i);
      if (found)
	goto print;
    }


    for (int i = 0; i < n; i++) ans[i] = done[i] = 0;
    for (int i = 0; i < n; i++) {
      if (done[i] || node[i].size() != 3) continue;
      vector<vector<int>> v;
      for (int j : node[i]) {
	vector<int> v_;
	dfs(v_,j,i);
	v.push_back(v_);
      }
      sort(v.begin(), v.end(), lengthcmp);
      int a = v[0].size(), b = v[1].size(), c = v[2].size();
      if (a >= 2) {
	ans[i] = 3;
	for (int j = 0; j < 3; j++) {
	  ans[v[j][0]] = 2;
	  ans[v[j][1]] = 1;
	}
	goto print;
      }
      if (b >= 3) {
	ans[i] = 4;
	ans[v[0][0]] = 2;
	for (int j = 1; j < 3; j++) {
	  ans[v[j][0]] = 3;
	  ans[v[j][1]] = 2;
	  ans[v[j][2]] = 1;
	}
	goto print;
      }
      if (b >= 2 && c >= 5) {
	ans[i] = 6;
	ans[v[0][0]] = 3;
	ans[v[1][0]] = 4;
	ans[v[1][1]] = 2;
	for (int j = 0; j < 5; j++)
	  ans[v[2][j]] = 5-j;
	goto print;
      }
    }

    cout << "NO" << '\n';
    continue;
  print:
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++)
      cout << ans[i] << ' ';
    cout << '\n';
  }
}