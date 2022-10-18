#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<vector<int>> adj;

vector<bool> visited;
vector<long long> maxs;

vector<long long> sums;

void f(int cur) {
    long long sum = v[cur];
    long long m = numeric_limits<long long>::min();

    visited[cur] = true;
    for (int i : adj[cur]) {
        if (!visited[i]) {
            f(i);
            sum += sums[i];
            m = max(m, maxs[i]);
        }
    }

    m = max(m, sum);
    sums[cur] = sum;
    maxs[cur] = m;
}

long long compute(int cur) {
    long long a = numeric_limits<long long>::min();
    long long b = numeric_limits<long long>::min();
    visited[cur] = true;
    long long best = numeric_limits<long long>::min();
    for (int next : adj[cur]) {
        if (!visited[next])  {
            if (a == numeric_limits<long long>::min()) {
                a = maxs[next];
            } else if (b == numeric_limits<long long>::min()) {
                b = maxs[next];
            } else if (maxs[next] > a && a <= b) {
                a = maxs[next];
            } else if (maxs[next] > b && b <= a) {
                b = maxs[next];
            }
            best = max(best, compute(next));
        }

    }
    
    if (a != numeric_limits<long long>::min() && b != numeric_limits<long long>::min())
        best = max(best, a+b);
    return best;
}

int SQRT;
vector<int> h;
vector<int> par;
vector<int> r;
void dfs(int v,int p = -1){
	if(p + 1)
		h[v] = h[p] + 1;
	par[v] = p;
	if(h[v] % SQRT == 0)
		r[v] = p;
	else
		r[v] = r[p];
	for(auto u : adj[v])	if(p - u)
		dfs(u,v);
}

int LCA(int v,int u){
	if(v == u)
		return v;
	if(h[v] < h[u])
		swap(v,u);
	if(h[v] == h[u])
		return (r[v] == r[u] ? LCA(par[v], par[u]) : LCA(r[v], r[u]));
	if(h[v] - h[u] < SQRT)
		return LCA(par[v], u);
	return LCA(r[v], u);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    
    v.assign(n, 0);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n, false);
    sums.resize(n);
    maxs.resize(n);

    f(0);

    h.assign(n, 0);
    par.assign(n, 0);
    r.assign(n, 0);

    visited.assign(n, false);

    long long res = compute(0);
    if (res == numeric_limits<long long>::min())
        cout << "Impossible" << endl;
    else
        cout << res << endl;

    return 0;
}