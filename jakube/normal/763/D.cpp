#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 1e5+1;
int size[maxn];
unsigned long long hashes[maxn];
int centroid;
vector<int> adj[maxn];

void dfs_size(int v, int p){
    size[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs_size(u, v);
        size[v] += size[u];
    }
}

void find_centroid(int v, int p) {
    if (size[v] * 2 < n) return;

    bool b = true;
    for (int u : adj[v]) {
        if (u == p) continue;
        find_centroid(u, v);
        if (size[u] * 2 >= n) b = false;
    }
    
    if (b)
        centroid = v;
}

map<unsigned long long, int> hcnt;
constexpr unsigned P1 = 1000003, P2 = 1000033;
constexpr unsigned M1 = 1000000007, M2 = 1000000009;
void dfs1(int t, int p)
{
	unsigned h1 = 1, h2 = 1;

	vector<unsigned> child1, child2;

	for (int nxt : adj[t])
	{
		if (nxt == p) continue;
		dfs1(nxt, t);
		child1.push_back(hashes[nxt] >> 32);
		child2.push_back(hashes[nxt]);
	}

	sort(child1.begin(), child1.end());
	sort(child2.begin(), child2.end());

	for (int i = 0; i < child1.size(); i++)
	{
		h1 = (h1 * 1ull * P1 + child1[i] * (i + 1ull)) % M1;
		h2 = (h2 * 1ull * P2 + child2[i] * 1ull * (child1.size() - i)) % M2;
	}

	hashes[t] = (unsigned long long)h1 << 32 | h2;
	hcnt[hashes[t]]++;
}
void compute_hashes(int v, int p) {
    int h = 1;

    vector<int> children;
    for (int u : adj[v]) {
        if (u == p) continue;

        compute_hashes(u, v);
        children.push_back(hashes[u]);
    }

    sort(children.begin(), children.end());
    
    
    int c = 1;
    for (int hash : children) {
        h = h * 793 + hash * c;
        c++;
    }

    hashes[v] = h;
    hcnt[h]++;
}

int best_node;
int best = 0;

void find_best(int v, int p, int avoided) {
    if (best < avoided) {
        best = avoided;
        best_node = v;
    }
         
    for (int u : adj[v]) {
        if (u == p) continue;
        
        if (hcnt[hashes[u]] > 1)
            find_best(u, v, avoided + 1);
        else 
            find_best(u, v, avoided);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs_size(1, 0);
    find_centroid(1, 0);

    // compute_hashes(centroid, 0);
    dfs1(centroid, 0);
    find_best(centroid, 0, 1);

    cout << best_node << endl;
}