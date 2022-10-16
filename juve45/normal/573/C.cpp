#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n, start, use[N], a, b, gr[N], imp[N];
vector <int> v[N];
queue <int> q;

int dfs2(int node, int ant = -1) {
	int cnt = 0;
	for(auto i : v[node])
		if(i != ant) {
			// dbg(i);
			if(imp[i])
				cnt++;
		}

	// dbg(node, cnt);
	if(cnt > 1) {
		cout << "No\n";
		exit(0);
	}

	for(auto i : v[node])
		if(i != ant && imp[i])
			dfs2(i, node);
}

void dfs(int node, int ant = -1) {

	int ok = 0;
	for(auto i : v[node])
		if(i != ant) {
			dfs(i, node);
			ok |= imp[i];
		}
	if(ok == 0 && imp[node] == 1) start = node;
	ok |= imp[node];
	if(ok) imp[node] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i =1 ; i< n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		gr[a]++;
		gr[b]++;
	}


	for(int i = 1; i<= n; i++)
		if(v[i].size() == 1)
			q.push(i), use[i] = 1;

	while(!q.empty()) {
		int x = q.front(); q.pop();
		// dbg(x);

		if(v[x].size() >= 4)  {
			imp[x] = 1;
			continue;
		}

		int flag = 0;
		if(v[x].size() == 3) flag = 1;

		for(auto i : v[x])
			if(!use[i]) {
				gr[i]--;
				if(flag) imp[i] = 1;
				else if(gr[i] == 1) q.push(i), use[i] = 1;
			}
	}

	// dbg_v(imp, n + 1);

	for(int i = 1; i <= n; i++)
		if(imp[i]) {
			dfs(i);
			break;
		}

	// dbg_v(imp, n + 1);
	// dfs(1);
	// dbg(start);
	dfs2(start);
	cout << "Yes\n";
}