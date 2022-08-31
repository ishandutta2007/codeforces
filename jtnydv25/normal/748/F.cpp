#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
const int N = 2e5 + 10;

int tree[N], val[N];
vector<int> con[N];
void dfs1(int s, int p){
	tree[s] = val[s];
	for(int v : con[s]){
		if(v != p){
			dfs1(v, s);
			tree[s] += tree[v];
		}
	}
}

inline int get(int s, int p, int k){
	for(int v : con[s]){
		if(v != p && tree[v] > k)
			return get(v, s, k);
	}
	return s;
}
bool valid[N];
set<pair<int, int > > st;
set<int> rem[N];
void dfs(int s, int p, int node, bool beg){
	valid[node] = 1;
	if(!beg) if(val[s]){
		rem[node].insert(s);
	}
	for(int v : con[s]){
		if(v != p){
			int nnode = beg ? v : node;
			dfs(v, s, nnode, 0);
		}
	}
}

int main(){
	int n, a, b, k, x;
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		con[a].pb(b);
		con[b].pb(a);
	}

	for(int i = 1; i <= 2*k; i++){
		scanf("%d", &x);
		val[x] = 1;
	}

	dfs1(1, 0);
	int root = get(1, 0, k);
	dfs(root, 0, 0, 1);

	if(val[root]){
		rem[root].insert(root);
	}
	printf("%d\n%d\n", 1, root);
	for(int i = 1; i <= n; i++) st.insert({-rem[i].size(), i});
	for(int i = 1; i <= k; i++){
		auto it = st.begin();
		a = it->second;
		st.erase(it);
		it = st.begin();
		b = it->second;
		st.erase(it);
		int A = *(rem[a].begin()), B = *(rem[b].begin());
		rem[a].erase(A); rem[b].erase(B);
		printf("%d %d %d\n", A, B, root);
		st.insert({-rem[a].size(), a});
		st.insert({-rem[b].size(), b});
	}	
}