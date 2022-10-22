#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// from topcoder
class KuhnImplementation {
  public:
    int n, k;
  vector < vector < int > > g;
  vector < int > pairs;
  vector < bool > used;

  bool kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
      int to = g[v][i];
      if (pairs[to] == -1 || kuhn(pairs[to])) {
        pairs[to] = v;
        return true;
      }
    }
    return false;
  }

  vector < pair < int, int > > find_max_matching(vector < vector < int > > & _g, int _n, int _k) {
    g = _g;
    //g[i] is a list of adjacent vertices to vertex i, where i is from left patr and g[i][j] is from right part
    n = _n;
    //n is number of vertices in left part of graph
    k = _k;
    //k is number of vertices in right part of graph

    pairs = vector < int > (k, -1);
    //pairs[i] is a neighbor of vertex i from right part, on marked edge
    used = vector < bool > (n, false);
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; j++) {
            used[j] = false;
        }
      kuhn(i);
    }

    vector < pair < int, int > > res;
    for (int i = 0; i < k; i++)
      if (pairs[i] != -1)
        res.push_back(make_pair(pairs[i], i));

    return res;

  }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    if(2 * nums[n-1] >= m) {
        cout << "-1\n";
        return 0;
    }
    multiset<int> s;
    KuhnImplementation ki;
    vector<int> small, big;
    for(int i = 0; i < n; i++) {
        if(nums[i] <= m/3) small.push_back(nums[i]);
        else big.push_back(nums[i]);
    }
    int x = small.size(), y = big.size();
    if(y > x) {
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> adjmat(x);
    for(int i = 0; i < x; i++) {
        s.insert(small[i]);
        for(int j = 0; j < y; j++) {
            if((big[j] % small[i] == 0) && (big[j] * 2 + small[i] <= m)) {
                adjmat[i].push_back(j);
            }
        }
    }
    vector<pair<int, int>> res = ki.find_max_matching(adjmat, x, y);
    if(res.size() != y) {
        cout << "-1\n";
        return 0;
    }
    cout << x << '\n';
    for(auto p : res) {
        int xx = small[p.first];
        int yy = big[p.second];
        auto it = s.find(xx);
        s.erase(it);
        cout << 2 * yy + xx << ' ' << yy + xx << '\n';
    }
    for(int g : s) {
        cout << 3 * g << ' ' << 2 * g << '\n';
    }
}