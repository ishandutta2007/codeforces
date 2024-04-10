#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 200100;

int n, k, m, nrcc, use[N], a[N], root, ans, no_root = 1;
vector <int> roots, cc[N], v[N];

void dfs(int node, int comp) {
	use[node] = comp;
	cc[comp].push_back(node);
	// for(auto i : v[node])...
	if(!use[a[node]]) dfs(a[node], comp);
}
void dfs(int node) {
	use[node] = 1;
	for(auto i : v[node])
		if(!use[i])
			dfs(i);
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
	}

	for(int i = 1; i <= n; i++) {
		if(a[i] == i)
			roots.push_back(i);
	}

	// dbg(roots);

	if(roots.size() == 0) {
		no_root = true;
		//gresit
		// root = 1;
		// a[root] = root;
		// ans++;
	} else {
		no_root = false;
		root = roots.back();
		roots.pop_back();

		for(auto i : roots) {
			ans++;
			a[i] = root;
			v[root].push_back(i);
		}
	}

	dfs(root);

	// ar trebui sa am doar cicluri
	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfs(i, ++nrcc);

	for(int i = 1; i <= nrcc; i++) {
		if(use[a[cc[i].back()]] == use[cc[i][0]]) {
			if(no_root) {
				dbg_ok;
				root = cc[i].back();
				no_root = false;
			}
			// dbg(cc[i]);
			ans++;
			a[cc[i].back()] = root;
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}