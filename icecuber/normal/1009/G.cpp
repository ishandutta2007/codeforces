#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int end, cap;
};
vector<Edge> edges;
const int nax = 64+6+2;
vector<int> node[nax];

int done[nax];
int maxflow(int p, int sink, int ma = 1e9) {
  if (p == sink) return ma;
  if (done[p]++) return 0;
  for (int ei : node[p]) {
    Edge&e = edges[ei];
    int flow;
    if (e.cap && (flow = maxflow(e.end, sink, min(ma,e.cap)))) {
      e.cap -= flow;
      edges[ei^1].cap += flow;
      return flow;
    }
  }
  return 0;
}

void addEdge(int a, int b, int c) {
  node[a].push_back(edges.size());
  edges.push_back({b,c});
  node[b].push_back(edges.size());
  edges.push_back({a,0});
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int cnt[6] = {};
  for (char c : s) cnt[c-'a']++;

  int n = s.size();
  vector<int> mask(n, (1<<6)-1);
  int m;
  cin >> m;
  while (m--) {
    int p;
    string allow;
    cin >> p >> allow;
    p--;
    mask[p] = 0;
    for (char c : allow)
      mask[p] |= 1<<(c-'a');
  }

  int mcnt[64] = {};
  for (int&v : mask) mcnt[v]++;

  int source = nax-2, sink = nax-1;

  {
    for (int i = 0; i < 64; i++) {
      addEdge(source, i, mcnt[i]);
      for (int j = 0; j < 6; j++)
	if (i>>j&1)
	  addEdge(i, 64+j, 1e9);
    }
    for (int j = 0; j < 6; j++)
      addEdge(64+j, sink, cnt[j]);
  }

  int flow = 0;
  string ans;
  for (int i = 0; i < n; i++) {
    auto cpedges = edges;
    int cpflow = flow;
    mcnt[mask[i]]--;
    int found = 0;
    for (int j = 0; j < 6; j++) {
      if ((mask[i]>>j&1) == 0 || !cnt[j]) continue;

      cnt[j]--;

      edges = cpedges;
      flow = cpflow;
      {
	int ei = node[sink][j];
	if (!edges[ei^1].cap) {
	  int a = edges[ei].cap-1;
	  assert(a >= 0);
	  int b = edges[ei^1].cap+1;
	  edges[ei].cap = 0;
	  edges[ei^1].cap = 0;
	  fill_n(done, nax, 0);
	  assert(maxflow(edges[ei].end, source, 1) == 1);
	  edges[ei].cap = a;
	  edges[ei^1].cap = b;
	  flow--;
	}
	assert(edges[ei^1].cap--);
	assert(edges[ei].cap+edges[ei^1].cap == cnt[j]);
      }

      {
	int ei = node[source][mask[i]];
	if (!edges[ei].cap) {
	  int a = edges[ei].cap+1;
	  int b = edges[ei^1].cap-1;
	  assert(b >= 0);
	  edges[ei].cap = 0;
	  edges[ei^1].cap = 0;
	  fill_n(done, nax, 0);
	  assert(maxflow(sink, edges[ei].end, 1) == 1);
	  edges[ei].cap = a;
	  edges[ei^1].cap = b;
	  flow--;
	}
	assert(edges[ei].cap--);
	assert(edges[ei].cap+edges[ei^1].cap == mcnt[mask[i]]);
      }


      while (1) {
	fill_n(done, nax, 0);
	int f = maxflow(source, sink);
	if (!f) break;
	flow += f;
      }

      if (flow == n-i-1) {
	ans += 'a'+j;
	found = 1;
	break;
      } else cnt[j]++;
    }
    if (!found) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << ans << endl;
}