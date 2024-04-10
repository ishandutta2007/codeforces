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

const int N = 5010;
int n, k, x,m,e,u,v, d, pff[N];
vector<int> vx[N],vy[N], g[N];
int viz[N], px[N], py[N], p[N], c[N], ans[N];

bool dfs(int n) {
	viz[n]=1;

	for(auto v: vx[n])
		if(py[v]==0 || (!viz[py[v]] && dfs(py[v]))) {
			px[n]=v;
			py[v]=n;
			return true;
		}
	return false;
}

int creste() {
	int ok = 0;
	
	memset(viz,0, sizeof(viz));

	for (int i = 1;i <= n; i++)
		if (viz[i]==0 && !px[i]) {
			ok += dfs(i);
		}
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;

	for(int i = 1; i <= n; i++) cin >> p[i], p[i]++;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	cin >> d;
	vector <int> w;
	for(int i = 1; i <= d; i++) cin >> x, w.push_back(x), pff[x] = 1;
	reverse(w.begin(), w.end());
	
	int last = 0, cuplaj = 0;

	for(int i = 1; i <= n; i++)
		if(!pff[i]) {
			g[p[i]].push_back(c[i]);
		}

	while(cuplaj == last) {
		last++;
		for(auto i : g[last]) {
			vx[last].push_back(i); 
			vy[i].push_back(last);
		}
		cuplaj += creste();
	}	

	for(int i = 0; i < d; i++) {

		if(p[w[i]] > last)
			g[p[w[i]]].push_back(c[w[i]]);
		else {
			vx[p[w[i]]].push_back(c[w[i]]);
			vy[c[w[i]]].push_back(p[w[i]]);
		}


		ans[i] = last - 1;
		cuplaj += creste();

		while(cuplaj == last) {
			last++;
			for(auto i : g[last]) {
				vx[last].push_back(i); 
				vy[i].push_back(last);
			}
			cuplaj += creste();
		}
	}
	for(int i = d - 1; i >= 0; i--)
		cout << ans[i] << '\n';
}