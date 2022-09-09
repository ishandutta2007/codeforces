#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <unordered_map>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

//#define int li

const int INF = 1000*1000*1000;

struct rib {
	int b, u;
	double c;
	int f;
	size_t back;
};

void add_rib (vector < vector<rib> > & g, int a, int b, int u, double c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back (r1);
	g[b].push_back (r2);

	//cout << a << ' ' << b << ' ' << u << ' ' << c << endl;

}

pair<double, double> a[1000];

double dist (pair <double, double> q, pair <double, double> w) {
	return sqrt( (q.first - w.first) * (q.first - w.first) + (q.second - w.second) * (q.second - w.second) );
}

void solve()
{

	int n, k = INF;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;

	vector < vector<rib> > g (2 * n + 2);

	int s = 2 * n, t = 2 * n + 1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j && a[i].second > a[j].second + 1e-9) {
				add_rib(g, i, j + n, 1, dist(a[i], a[j]));
			}
	for (int i = 0; i < n; ++i)
		add_rib(g, s, i, 2, 0);

	for (int i = n; i < 2 * n; ++i)
		add_rib(g, i, t, 1, 0);
	
	int N = n;

	n = 2 * n + 2;

	int flow = 0;
	double cost = 0;
	while (flow < k) {
		vector<int> id (n, 0);
		vector<double> d (n, 1.0 * INF);
		vector<int> q (n);
		vector<int> p (n);
		vector<size_t> p_rib (n);
		int qh=0, qt=0;
		q[qt++] = s;
		d[s] = 0;
		while (qh != qt) {
			int v = q[qh++];
			id[v] = 2;
			if (qh == n)  qh = 0;
			for (size_t i=0; i<g[v].size(); ++i) {
				rib & r = g[v][i];
				if (r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0) {
						q[qt++] = r.b;
						if (qt == n)  qt = 0;
					}
					else if (id[r.b] == 2) {
						if (--qh == -1)  qh = n-1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}
		if (d[t] > 1.0 * INF / 2)  
			break;
		int addflow = k - flow;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v];
			addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;

	//	cout << cost << endl;

	}


	if (flow < N - 1) {
		cout << "-1";
		return;
	}
	

	printf ("%.15lf", cost);

}