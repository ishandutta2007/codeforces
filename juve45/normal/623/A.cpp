#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

using namespace std;

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 1010;
int n, k, m, w[N][N], use[N], a, b;
char c[N];

void dfs(int node, int val) {
	int vec = 0;
	use[node] = val;

	for(int i = 1; i <= n; i++)
		if(w[node][i]) {
			if(!use[i]) dfs(i, 3 - val);
			else if(use[i] == val) {
				cout << "No\n";
				exit(0);
			}
			vec++;
		}
	if(!vec) use[node] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			w[i][j] = 1;

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		w[a][b] = w[b][a] = 0;
	}

	for(int i = 1; i <= n; i++) 
		w[i][i] = 0;

	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfs(i, 1);

	for(int i = 1; i <= n; i++)
		if(use[i] == 0) c[i] = 'b';
		else if(use[i] == 1) c[i] = 'a';
		else c[i] = 'c';

	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(w[i][j] == 0)
				if(c[i] != c[j] && fabs(c[i] - c[j]) != 1)
					return cout << "No\n", 0;



	cout << "Yes\n";
	for(int i = 1; i <= n; i++) cout << c[i];
	cout << '\n';
}