#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 100100;
const int K = 110;

int n, k, t[N], d[N], a, b, m, s;
int dmin[K][N];

vector <int> v[N], lst[K];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

queue <int> q;

void bfs(int ee) {
	int clr = ee;
	// dbg(k);
	memset(d, 0x3f, sizeof d);

	for(auto i : lst[ee]) {
		q.push(i);
		d[i] = 0;
		dmin[clr][i] = 0;
	}

	while(!q.empty()) {
		int from = q.front();
		q.pop();
		for(auto to : v[from]) {
			if(d[to] <= d[from]) continue;
			
			d[to] = d[from] + 1;
			dmin[clr][to] = min(dmin[clr][to], d[to]);
			q.push(to);	
		}
	}

}

priority_queue<int> pq;
int main() {
	ios_base::sync_with_stdio(false);

	memset(dmin, 0x3f, sizeof dmin);

	cin >> n >> m >> k >> s;
	for(int i = 1; i <= n; i++) {
		cin >> t[i];
		lst[t[i]].push_back(i);
	}

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i = 1; i <= k; i++)
		bfs(i);

	for(int i = 1; i <= n; i++) {
		int ans = 0;
		// dbg_v(dmin[i], k + 1);

		for(int j = 1; j <= k; j++)
			pq.push(-dmin[j][i]);

		for(int i = 1; i <= s; i++)
			ans += -pq.top(), pq.pop();

		for(int i = s + 1; i <= k; i++)
			pq.pop();

		cout << ans << ' ';
	}
	cout << '\n';
}