#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int queries = 0;
int query(vector<int> a, vector<int> b, int v) {
  assert(queries++ < 11111);
  cout << a.size() << endl;
  for (int i : a) cout << i+1 << ' ';
  cout << endl;
  cout << b.size() << endl;
  for (int i : b) cout << i+1 << ' ';
  cout << endl;
  cout << v+1 << endl;
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}

vector<vector<int>> partition(vector<int> v, int root) {
  for (int i = 0; i < v.size(); i++) {
    int j = rand()%(v.size()-i)+i;
    swap(v[i],v[j]);
  }
  vector<vector<int>> ret(1,vector<int>());
  for (int i : v) {
    if (i == root) continue;

    vector<pair<int,int>> possible;
    for (int j = 0; j < ret.size(); j++)
      possible.emplace_back(ret[j].size(), j);
    while (possible.size() > 1) {
      //cerr << "OK" << endl;
      sort(possible.begin(), possible.end());
      vector<int> q, chose(ret.size(),0);
      vector<int> freq(ret.size(), 0);
      for (auto p : possible) {
	int best = 1e9, besti = -1;
	for (int i = 0; i <= p.first && i < ret.size(); i++)
	  if (freq[i] <= best) best = freq[i], besti = i;
	chose[p.second] = besti;
	freq[besti]++;
	for (int i = 0; i < besti; i++)
	  q.push_back(ret[p.second][i]);
      }
      int ans = q.size()-query(q, {i}, root);
      vector<pair<int,int>> newposs;
      for (auto p : possible)
	if (chose[p.second] == ans)
	  newposs.push_back(p);

      assert(newposs.size() < possible.size());
      possible = newposs;
    }
    ret[possible[0].second].push_back(i);
    if (ret.back().size()) ret.push_back({});
  }
  ret.pop_back();
  return ret;
}

int sz[500];

vector<pair<int,int>> ans;

void rec(vector<int> component) {
  int n = component.size();
  if (n <= 1) return;
  int mi = n+1, centroid = -1;
  for (int i : component) {
    if (sz[i] < mi && sz[i] >= (n+1)/2) {
      mi = sz[i];
      centroid = i;
    }
  }
  assert(centroid != -1);

  //cerr << "Centroid: " << centroid << endl;
  vector<vector<int>> parts = partition(component, centroid);
  for (auto v : parts) {
    int recalc = 0;
    for (int i : v) if (sz[i] > sz[centroid]) recalc = 1;
    if (recalc) {
      vector<int> left;
      for (int i : v)
	sz[i] = query(v, {centroid}, i);
    }
    int mai, ma = -1;
    for (int i : v) {
      if (sz[i] > ma) {
	ma = sz[i];
	mai = i;
      }
    }
    ans.push_back({mai,centroid});
    rec(v);
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int root = 0;
  vector<int> v;
  for (int j = 1; j < n; j++) v.push_back(j);
  for (int i = 0; i < n; i++)
    sz[i] = query(v, {root}, i);

  v.clear();
  for (int i = 0; i < n; i++)
    v.push_back(i);
  rec(v);

  cout << "ANSWER" << endl;
  assert(ans.size() == n-1);
  for (auto p : ans)
    cout << p.first+1 << ' ' << p.second+1 << endl;
}