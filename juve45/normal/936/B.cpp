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
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 100100;
const int MOD = 666013;

int n, k, m, use[N][2], a, in[N], draw, win[N], s;
pair<int, int> ant[N][2];
vector <int> v[N];

void dfs(int node, int pas) {
	in[node]++;
	use[node][pas] = 1;

	for(auto i : v[node]) {
		if(in[i]) 
			draw = 1;
		if(!use[i][1 - pas]) {
			ant[i][1 - pas] = {node, pas};
			dfs(i, 1 - pas);
		}
	}
	in[node]--;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 0; j < k; j++) {
			cin >> a;
			v[i].push_back(a);
		}
		if(k == 0) 
			win[i] = 1;
	}


	cin >> s;
	dfs(s, 0);

	for(int i = 1; i <= n; i++)
		if(win[i] && use[i][1]) {
			cout << "Win\n";
			vector <int> ans;
			int tmp = i, pas = 1;
			while(tmp != s || pas != 0) {
				ans.push_back(tmp);
				tmp = ant[tmp][pas].st;
				pas = 1 - pas;
				if(tmp == 0) break;
			}
			ans.push_back(s);
			reverse(ans.begin(), ans.end());
			cout << ans << '\n';
			return 0;
		}

	if(draw) cout << "Draw\n";
	else cout << "Lose\n";
}