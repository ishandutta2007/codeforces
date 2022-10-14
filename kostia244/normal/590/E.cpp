#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 755, maxa = 10100000, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int to[maxa][2], tin[maxa], tout[maxa], link[maxa], term[maxa], nxt[maxa], sz = 1, timer = 0;
string s[maxn];
int rn = 0;
int go(int p) {
	int cur = 0;
	for(auto c : s[p]) {
		c-='a';
		if(!to[cur][c]) to[cur][c] = sz++;
		cur = to[cur][c];
	}
	if(term[cur]) return -1;
	term[cur] = 1+rn++;
	return cur;
}
int S = 0, F = 0, Q[maxa];
void push() {
	Q[F++] = 0;
	while(S < F) {
		int V = Q[S++];
		int U = link[V];
		if(V) {
			if(term[V]) nxt[V] = term[V]-1;
			else nxt[V] = nxt[U];
		} else nxt[0] = -1;
		for(int c = 0; c < 2; c++) {
			if(to[V][c]) {
				Q[F++] = to[V][c];
				link[to[V][c]] = V ? to[U][c] : 0;
			} else to[V][c] = to[U][c];
		}
	}
}
int n;
int C[maxn][maxn], rid[maxn];
struct BipartiteMatcher {
  vector<vector<int>> G;
  vector<int> L, R, Viz;
  
  BipartiteMatcher(int n, int m) :
  G(n), L(n, -1), R(m, -1), Viz(n) {}
  
  void AddEdge(int a, int b) {
    G[a].push_back(b);
  }
  
  bool Match(int node) {
    if (Viz[node])
      return false;
    Viz[node] = true;
    
    for (auto vec : G[node]) {
      if (R[vec] == -1) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    for (auto vec : G[node]) {
      if (Match(R[vec])) {
        L[node] = vec;
        R[vec] = node;
        return true;
      }
    }
    
    return false;
  }
  
  int Solve() {
    int ok = true;
    while (ok--) {
      fill(Viz.begin(), Viz.end(), 0);
      for (int i = 0; i < (int)L.size(); ++i)
        if (L[i] == -1)
          ok |= Match(i);
    }
    
    int ret = 0;
    for (int i = 0; i < L.size(); ++i)
      ret += (L[i] != -1);
    return ret;
  }
  vector<int> gg, ggl;
  void efs(int v) {
	  if(ggl[v]) return;
	  ggl[v] = 1;
	  for(auto &i : G[v]) if(i != L[v]) {
		  gg[i] = 1;
		  if(R[i] != -1) efs(R[i]);
	  }
  }
  vector<int> mis() {
	  gg.resize(n), ggl.resize(n);
	  Solve();
	  //for(int i = 0; i < n; i++) if(L[i] != -1) cout << i << " -- " << 10+L[i] << endl;
	  vector<int> ans;
	  for(int i = 0; i < n; i++) if(L[i] == -1) efs(i);
	  //for(int i = 0; i < n; i++) cout << gg[i] << " "; cout << endl;
	  //for(int i = 0; i < n; i++) cout << ggl[i] << " "; cout << endl;
	  for(int i = 0; i < n; i++) if(!(!ggl[i] || gg[i])) ans.push_back(i);
	  return ans;
  }
};
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[rn];
		rid[rn] = i+1;
		go(rn);
	}
	n = rn;
	push();
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(auto j : s[i]) {j -= 'a';
			cur = to[cur][j];
			int f = nxt[cur];
			if(nxt[cur] == i)
				f = nxt[link[cur]];
			if(f != -1)
				C[i][f] = 1;
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				C[j][k] |= C[j][i]&C[i][k];
	BipartiteMatcher M(n, n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			//if(C[i][j]) cout << i << " " << 10+j << endl;
			if(C[i][j]) M.AddEdge(i, j);
		}
	auto t= M.mis();
	cout << t.size() << endl;
	for(auto i : t) cout << rid[i] << " "; cout << endl;
}