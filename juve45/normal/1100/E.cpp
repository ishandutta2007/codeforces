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
int n, k, m, use[N], st[N], a, b, c, dmax, lim, pos[N], gr[N];
vector <pair<int, pair<int,int> > > v[N], rem;
vector <int> ans;
queue <int> q;

bool dfs(int node, int val) {
	use[node] = 1;
	st[node] = 1;
	int ret = 0;

	for(auto i : v[node]) {
		if(i.nd.st <= val) continue;
		if(!use[i.st]) ret |= dfs(i.st, val);
		else if(st[i.st]) return 1;
	}
	st[node] = 0;
	return ret;
}

bool ok(int val) {
	memset(use, 0, sizeof use);
	for(int i = 1; i <= n; i++)
		if(!use[i])
			if(dfs(i, val))
				return 0;
	return 1;
}

void topsort(int lim) {
	memset(use, 0, sizeof use);
	int last = 1;

	for(int i = 1; i <= n; i++)
		for(auto j : v[i]) {
			if(j.nd.st > lim)
				gr[j.st]++;
			else
				rem.push_back({j.nd.nd, {i, j.st}}); 
		}

	// dbg(rem);
	// dbg_v(gr, n + 1);

	for(int i = 1; i <= n; i++)
		if(gr[i] == 0) {
			use[i] = 1;
			q.push(i);
		}

	while(!q.empty()) {
		int x = q.front(); q.pop();
		pos[x] = last++;
	
		for(auto i : v[x]) {
			if(i.nd.st <= lim) continue;
			gr[i.st]--;
			if(gr[i.st] == 0 && !use[i.st])
				use[i.st] = 1, q.push(i.st);
		}
	}

	// dbg_v(pos, n + 1);

	for(int i = 1; i <= n; i++)
		if(!pos[i])
			pos[i] = last++;

	// dbg_v(pos, n + 1);

	for(auto i : rem) {
		if(pos[i.nd.st] > pos[i.nd.nd]) {
			ans.push_back(i.st);
			// cerr << i.nd.nd << ' ' << i.nd.st << '\n'; 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({b, {c, i}});
	}

	int l = 0, r = 1e9;
	while(l != r) {
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}

	topsort(l);

	cout << l << ' ' << ans << '\n';
}