#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const int N = 100100;
int n, k, m, a, b, sz[N], use[N];
set <int> v[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].insert(b);
		v[b].insert(a);
		sz[a]++;
		sz[b]++;
	}

	vector <int> q;

	for(int i = 1; i <= n; i++)
		if(v[i].size() == 1) 
			q.push_back(i), use[i] = 1;

	int ok = 1;
	int level = 1;
	while(ok  && !q.empty()) {

		set <int> qq;
		
		for(auto j : q) {
			// dbg(j);
			int vec = *v[j].begin();
			v[j].clear();
			v[vec].erase(j);
			if(use[vec])
				return cout << "No\n", 0;
			qq.insert(vec);
		}
		// dbg_ok;
		if(qq.size() == 1) {
			// dbg(*qq.begin());
			if(level == k && sz[*qq.begin()] >= 3 && v[*qq.begin()].size() == 0)
				return cout << "Yes\n", 0;
			return cout << "No\n", 0;
		}

		q.clear();
		for(auto i : qq) {
			if(v[i].size() != 1 || sz[i] < 4)
				return cout << "No\n", 0;
			q.push_back(i), use[i] = 1;
		}
		level++;
	}
	cout << "No\n";
	return 0;
}