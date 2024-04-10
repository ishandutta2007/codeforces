#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define sd(x) scanf("%d", &(x))
#define slld(x) scanf("%lld", &(x))

const int N = 1e5 + 109;
ll p[N], p1[N], q[N], q1[N], P[N], P1[N], Q[N], Q1[N], d[N], par[N];
int n, u, v;
vector<int> con[N];

ld distsum = 0, sizesum = 0, sump = 0, sumq = 0, ans;

ld get(int s){
	return (P1[s] / sump) * (Q[s] / sumq) + (P[s] / sump) *
	(Q1[s] / sumq) - 2 * d[s] * (P[s] / sump) * (Q[s] / sumq);
}
ll sz[N];
void dfs(int s, int pa){
	sz[s] = 1;
	d[s] = d[pa] + 1;
	P1[s] = p1[s] = p[s] * d[s];
	Q1[s] = q1[s] = q[s] * d[s];
	P[s] = p[s];
	Q[s] = q[s];

	for(int v : con[s]){
		if(v != pa){
			dfs(v, s);
			P1[s] += P1[v];
			Q1[s] += Q1[v];
			P[s] += P[v];
			Q[s] += Q[v];
		}
	}

	ans += get(s);
	for(int v : con[s]){
		if(v != pa){
			ans -= get(v);
			sz[s] += sz[v];
		}
	}
}

ld ans2;
void dfs1(int t, int pa=0) {
	ans2 += q[t] * sz[t] / sumq * (P[1] - P[t]) / sump;
	// cout << q[t] << " " << sz[t] << endl;
	for (int c: con[t]) {
		if (c != pa) {
			dfs1(c, t);
			ans2 += P[c] / sump * q[t] * (n - sz[c]) / sumq;
		}
	}
}

int main(){
	sd(n);
	ll prob = 0;
	for(int i = 1; i < n; i++){
		sd(u);
		sd(v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		slld(p[i]);
		slld(q[i]);
		sump += p[i];
		sumq += q[i];
		prob += p[i]*q[i];
	}
	ld prob2 = 1. - prob / sump / sumq;
	dfs(1, 0);
	dfs1(1);
	// cout << ans << " " << ans2 << endl;
	ld final = n * prob2 - ans2;
	printf("%.10lf\n", final);
}