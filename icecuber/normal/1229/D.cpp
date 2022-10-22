#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> operator*(vector<int> a, vector<int> b) {
  vector<int> r(a.size());
  for (int i = 0; i < a.size(); i++) {
    r[i] = a[b[i]];
  }
  return r;
}

int mul_table[120][120];
bitset<120> reach[120][120];
int npos[200001][120];

unordered_map<bitset<120>,bitset<120>> mem[120];
bitset<120> expand(bitset<120> b, int p, int m) {
  auto&done = mem[p][b];
  if (!done.count()) {
    queue<int> q;
    for (int i = 0; i < m; i++)
      if (b[i]) {
	q.push(i);
	done.set(i);
      }
    while (q.size()) {
      int i = q.front();
      q.pop();
      for (int j = 0; j < m; j++) {
	if (!b[j] && j != p) continue;
	int e = mul_table[i][j];
	if (!done[e]) {
	  done.set(e);
	  q.push(e);
	}
      }
    }
  }
  return done;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> perms;
  {
    vector<int> v;
    for (int i = 0; i < k; i++) v.push_back(i);
    do {
      perms.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
  }

  int m = perms.size();

  map<vector<int>, int> permi;
  for (int i = 0; i < m; i++)
    permi[perms[i]] = i;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      mul_table[i][j] = permi[perms[i]*perms[j]];
    }
  }

  {
    unordered_set<bitset<120>> s;
    bitset<120> start;
    start.set(0);
    s.insert(start);
    for (int p = 0; p < m; p++) {
      vector<bitset<120>> toadd;
      for (auto b : s) {
	toadd.push_back(expand(b, p, m));
      }
      for (auto b : toadd)
	s.insert(b);
    }
    /*for (auto b : s) {
      for (int i = 0; i < m; i++)
	if (b[i]) cout << i << ' ';
      cout << endl;
      }
      cout << s.size() << endl;*/
  }

  //unordered_set<bitset<120>> s;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      int p = i;
      do {
	reach[i][j].set(p);
	p = mul_table[p][j];
      } while (p != i);
      //if (i == j)
      //s.insert(reach[i][j]);
    }
  }
  //cout << s.size() << endl;
  //return 0;

  vector<int> a;
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < k; j++) {
      int p;
      cin >> p;
      v.push_back(p-1);
    }
    a.push_back(permi[v]);
  }

  for (int j = 0; j < m; j++) npos[n][j] = n;
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < m; j++)
      npos[i][j] = npos[i+1][j];
    npos[i][a[i]] = i;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    bitset<120> has = reach[a[i]][a[i]];
    int r = i;

    vector<pair<int,int>> q;
    for (int j = 0; j < m; j++) {
      q.push_back({npos[i][j], j});
    }
    sort(q.begin(), q.end());

    int j = 0;
    while (r < n) {
      int p = n;
      while (j < m && has[q[j].second]) j++;
      if (j < m)
	p = q[j].first;
      ans += has.count()*(p-r);
      r = p;
      if (r == n) break;
      has = expand(has, a[r], m);
    }
  }
  cout << ans << endl;
}