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

const int N = 200100;
int n, k, m, ok[N], ans, a[N], b[N], an[N];

set<int> v[N], good;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	ans = n;

	for(int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		v[a[i]].insert(b[i]);
		v[b[i]].insert(a[i]);
	}

	queue <int> q;

	for(int i = 1; i <= n; i++)
		ok[i] = 1;

	for(int i = 1; i <= n; i++)
		if(v[i].size() < k)
			q.push(i), ok[i] = 0, ans--;

	for(int i = m; i > 0; i--) {

		while(!q.empty()) {

			int x = q.front(); q.pop();
			dbg(x);
			for(auto j : v[x]) {
				v[j].erase(x);
				if(ok[j] && v[j].size() < k)
					q.push(j), ok[j] = 0, ans--;
			}
		}
		an[i] = ans;

		v[a[i]].erase(b[i]);
		v[b[i]].erase(a[i]);

		for(auto j : {a[i], b[i]})
			if(ok[j] && v[j].size() < k)
				q.push(j), ok[j] = 0, ans--;

	}
	for(int i = 1; i <= m; i++)cout << an[i] << '\n';
}