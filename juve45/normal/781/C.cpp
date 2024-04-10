#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 200100;
int n, k, a, b, m, use[N];

vector <int> euler, v[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

void dfs(int node) {
	use[node] = 1;
	euler.push_back(node);
	for(auto i : v[node])
		if(!use[i]) {
			dfs(i);
			euler.push_back(node);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;

	if(n == 1) {
		cout << "1 1\n";
		return 0;
	}

	for(int i= 1; i <= m; i++) {
		cin >> a >> b;
		if(a == b) continue;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	// dbg(euler);
		euler.pop_back();
	int bkt = (2 * n + k - 1) / k;
	for(int i = 0; i < k; i++) {
		cout << bkt << ' ';
		for(int j = 0; j < bkt; j++)
			cout << euler[(i * bkt + j) % euler.size()] << ' ';
		cout << '\n';
	}

}