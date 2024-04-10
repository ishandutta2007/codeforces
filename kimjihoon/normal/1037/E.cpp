#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct edge {
	int tn, r;
	bool p;
	edge(int tn, int r, bool p) : tn(tn), r(r), p(p) {};
	edge() : tn(0), r(0), p(true) {};
};

struct query {
	int a, b, ai, bi;
};

int c[200009], ans[200009];
vector<edge> v[200009];
queue<int> q;
bool vs[200009];
query qr[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(edge(b, v[b].size(), true));
		v[b].push_back(edge(a, v[a].size() - 1, true));
		c[a]++; c[b]++;
		qr[i].a = a; qr[i].b = b; qr[i].ai = v[a].size() - 1; qr[i].bi = v[b].size() - 1;
	}
	for (int i = 1; i <= n; i++)
		if (c[i] < k) {
			q.push(i);
			vs[i] = true;
		}
	int s = n;
	for (int i = m - 1; i >= 0; i--) {
		while (!q.empty()) {
			int hn = q.front(); q.pop(); s--;
			for (int i = 0; i < v[hn].size(); i++) {
				edge tl = v[hn][i];
				if (!tl.p) continue;
				v[hn][i].p = false; v[tl.tn][tl.r].p = false;
				c[tl.tn]--;
				if (c[tl.tn] < k && !vs[tl.tn]) {
					q.push(tl.tn);
					vs[tl.tn] = true;
				}
			}
		}
		ans[i] = s;
		if (v[qr[i].a][qr[i].ai].p) {
		   v[qr[i].a][qr[i].ai].p = false; 
		   c[qr[i].a]--; 	 
 	    }
 	    if (v[qr[i].b][qr[i].bi].p) {
		   v[qr[i].b][qr[i].bi].p = false; 
		   c[qr[i].b]--; 	 
 	    }
		if (!vs[qr[i].a] && c[qr[i].a] < k) {
		   q.push(qr[i].a);
		   vs[qr[i].a] = true;
        }
		if (!vs[qr[i].b] && c[qr[i].b] < k) {
		   q.push(qr[i].b);
		   vs[qr[i].b] = true;
        }
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << '\n';
	return 0;
}