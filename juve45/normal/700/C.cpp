#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 1010
#define NMAX 
#define MMAX 

using namespace std;

int n, k, use[DMAX], use_edge[30100], an[4], low[DMAX], sz, h[DMAX], s, t, a, b, w, m;
long long ans = 1000000000000000000LL;
double l, v1, v2;

struct edge {
	int a, b, w;
}e[30100];

struct vert {
	int to, i, w;
};

vector <vert> v[DMAX];
vector <int> bridges, way;

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

bool dfs(int k) {
	use[k] = 1;
	if(k == t)
		return true;
	for(auto i : v[k]) 
		if(!use[i.to])
			if(dfs(i.to)) {
				way.push_back(i.i);
				return true;
			}
	return false;
}

bool dfs2(int k) {
	dbg(k);
	use[k] = 1;
	if(k == t)
		return true;
	for(auto i : v[k]) 
		if(!use[i.to] && !use_edge[i.i])
			if(dfs2(i.to)) {
				use_edge[i.i] = 2;
				return true;
			}
	return false;
}



bool dfs(int k, int d, int final) {
	use[k] = 1;
	h[k] = d;
	low[k] = d;
	bool ok = 0;
	
	if(final == k)
		ok = 1;

	for(auto i : v[k]) {
		if(!use[i.to] && !use_edge[i.i]) {
			
			use_edge[i.i] = 1;
			ok |= dfs(i.to, d + 1, final);
			
			low[k] = min(low[i.to], low[k]);

			if(low[i.to] > h[k])
				bridges.push_back(i.i);
		}
		else if(!use_edge[i.i]) {
			low[k] = min(h[i.to], low[k]);
		}
	}
	return ok;
}

bool compute_bridge(int i) {

	bridges.clear();
	memset(use, 0, sizeof use);
	memset(use_edge, 0, sizeof use_edge);
	// for(auto ii : way) use_edge[ii] = 1;
	use_edge[i] = 1; // pot sa trec inca o data prin muchia asta pe care vreau sa o scot, dar nu si prin celelalte din drum.
	
	return dfs(s, 1, t); // calculez bridges
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s >> t;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		v[a].push_back({b, i, w});
		v[b].push_back({a, i, w});
		e[i].a = a;
		e[i].b = b;
		e[i].w = w;
	}

	if(!dfs(s)) {

		cout << "0\n0\n";
		return 0;
	}
	else {	
		// in way am un drum oarecare de la s la t
		
		for(auto i : way) {
			// pt fiecare muchie din drum, vad cu cine pot sa o elimin.
			dbg(i);

			for(int ii = 1; ii <= n; ii++) low[ii] = n + 100;

			bool ok = compute_bridge(i);

			if(!ok) {
				if(e[i].w < ans) {
					ans = e[i].w;
					sz = 1;
					an[0] = i;
				}
				continue;			
			}

			memset(use, 0, sizeof use);
			memset(use_edge, 0, sizeof use_edge);
			use_edge[i] = 1; // pot sa trec inca o data prin muchia asta pe care vreau sa o scot, dar nu si prin celelalte din drum.

			dfs2(s); //imi da un nou drum intre s si t, marcat cu 2 prin use_eedge

			dbg(bridges);
			dbg_v((use_edge + 1), m);
			dbg_v((low + 1), n);

			for(auto j : bridges) {

				if(use_edge[j] == 2 && e[i].w + e[j].w < ans) {
					ans = e[i].w + e[j].w;
					sz = 2;
					an[0] = i;
					an[1] = j;
				}
			}
			
		}
		if(ans > 1000000000000LL) {
			cout << "-1\n";
			return 0;
		}
		cout << ans << '\n';
		cout << sz << '\n';
		for(int i = 0; i < sz; i++)
			cout << an[i] << ' ';
		cout << '\n';
	}

}