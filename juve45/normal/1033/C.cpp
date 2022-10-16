#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
int n, k, use[N], st[N], a[N];
vector <int> v[N];

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
	st[node] = 0;
	for(auto i : v[node]) {
		if(!use[i])
			dfs(i);

		if(!st[i])
			st[node] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++) {
		for(int j = i - a[i]; j > 0; j -= a[i])
			if(a[j] > a[i])
				v[i].push_back(j);
		for(int j = i + a[i]; j <= n; j += a[i])
			if(a[j] > a[i])
				v[i].push_back(j);
	}

	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfs(i);
	for(int i = 1; i <= n; i++)
		if(st[i]) cout << 'A';
		else cout << 'B';
	cout << '\n';
}