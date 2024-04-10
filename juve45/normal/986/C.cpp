 #include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 4201000;
int n, k, one, m, use[3][N], has[N], a[N], ans;

inline int no(int k) {
	return (one ^ k);
}

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void dfs(int node, int type) {
	// dbg(node);
	use[type][node] = 1;
	if(type == 1) {
		if(!use[2][node])
			dfs(node, 2);
	} else {
		for(int i = 0; i < n; i++)
			if(((1 << i) & node) == 0 && !use[2][node + (1 << i)])
				dfs(node + (1 << i), 2);

		int to = no(node);
		if(has[to] && !use[1][to])
			dfs(to, 1);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	one = (1 << n) - 1;

	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		has[a[i]] = 1;
	}

	for(int i = 1; i <= m; i++) {
		if(!use[1][a[i]])
			dfs(a[i], 1), ans++;
	}

	cout << ans << '\n';

}