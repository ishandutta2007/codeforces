#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const ll MAXK = -1;
const ll MAXN = -1;
const ll MOD = 1; // 1000 * 1000 * 1000 + 7;
const ll INF = (ll)(3e9);

struct Edge {
	ll from, to, cap, flow, cost;

	Edge() {}
	Edge(ll from, ll to, ll cap, ll cost) : from(from), to(to), cap(cap), flow(0), cost(cost) {}
};

ll q[(ll)(1e7)], qL, qR;
struct Graph {
	ll n;
	vector<Edge> edges;
	vector<vector<ll> > e;

	Graph(ll n) {
		this->n = n;
		e.resize(n);
	}

	void addEdge(ll from, ll to, ll cap, ll cost) {
		e[from].push_back(edges.size());
		edges.push_back(Edge(from, to, cap, cost));
		e[to].push_back(edges.size());
		edges.push_back(Edge(to, from, 0, -cost));
	}

	vector<ll> d;
	vector<ll> pr;
	vector<ll> fl;
	vector<char> inq;

	void ford() {
		d.assign(n, INF);
		fl.assign(n, 0);
		pr.assign(n, -1);
		inq.assign(n, 0);
		d[0] = 0;
		qL = qR = 0;
		q[qR++] = 0;
		inq[0] = 1;
		fl[0] = INF;
		while (qL < qR) {
			ll v = q[qL++];
			inq[v] = 0;
			for (ll i = 0; i < (ll)e[v].size(); i++) {
				Edge cur = edges[e[v][i]];
				if (d[cur.to] > d[v] + cur.cost && cur.flow < cur.cap) {
					d[cur.to] = d[v] + cur.cost;
					fl[cur.to] = min(fl[v], cur.cap - cur.flow);
					pr[cur.to] = e[v][i];
					if (!inq[cur.to]) {
						inq[cur.to] = 1;
						q[qR++] = cur.to;
					}
				}
			}
		}
	}

	ll mincost() {
		ll ans = 0;
		while (1) {
			ford();
			if (d[n - 1] > -INF / 2) return ans;
			ll flow = fl[n - 1];
			ans += d[n - 1] * flow;
			ll v = n - 1;
			while (pr[v] != -1) {
				edges[pr[v]].flow += flow;
				edges[pr[v] ^ 1].flow -= flow;
				v = edges[pr[v]].from;
			}
		}
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ll n, m;
	while (cin >> n >> m) {
		vector<ll> u(m), v(m), c(m), f(m);

		for (ll i = 0; i < m; i++) {
			cin >> u[i] >> v[i] >> c[i] >> f[i];
			u[i]--;
			v[i]--;
		}

		Graph gr(n + 2);
		
		ll ans = 0;
		vector<ll> dif(n);
		for (ll i = 0; i < m; i++) {
			if (f[i] > c[i]) {
				ans += f[i] - c[i];
				gr.addEdge(1 + u[i], 1 + v[i], f[i] - c[i], 0);
			}
			else {
				gr.addEdge(1 + u[i], 1 + v[i], c[i] - f[i], 1);
			}
			ll mn = min(f[i], c[i]);
			dif[u[i]] -= mn;
			dif[v[i]] += mn;
			gr.addEdge(1 + v[i], 1 + u[i], mn, 1);
			gr.addEdge(1 + u[i], 1 + v[i], INF, 2);
		}
		ll cnt = 0;
		//gr.addEdge(0, 1 + 0, INF, 0);
		gr.addEdge(1 + 0, 1 + n, INF * 300, 0);
		for (ll i = 1; i < n - 1; i++) {
			if (dif[i] > 0) {
				gr.addEdge(0, 1 + i, dif[i], -INF);
				cnt += dif[i];
			}
			else if (dif[i] < 0) {
				gr.addEdge(1 + i, 1 + n, -dif[i], -INF);
				cnt += -dif[i];
			}
		}
		//gr.addEdge(1 + n - 1, 1 + n, INF, 0);
		gr.addEdge(0, 1 + n - 1, INF * 300, 0);

		gr.addEdge(1 + n - 1, 1 + 0, INF * 300, 0);

		ans += gr.mincost();
		ans += INF * cnt;

		cout << ans << endl;

	}

	return 0;
}