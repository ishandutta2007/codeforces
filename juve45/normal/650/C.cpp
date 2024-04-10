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

const int N = 1001000;

vector <int> g[N], gt[N], c[N], v[N];
int use[N], a, b, n, m, nrc, cc[N], gr[N], val[N];
stack <int> s;
 
vector <vector <int> > w;

void dfs1(int k) {
    use[k]=1;
    for(auto i : g[k])
        if(!use[i])
            dfs1(i);
    s.push(k);
}
 
void dfs2(int k) {
    use[k]=1;
    for(auto i : gt[k])
        if(!use[i])
            dfs2(i);
    c[nrc].push_back(k);
    cc[k] = nrc;
}
 
void SCC() {
    for(int i=0;i<n * m;i++)
        if(!use[i])
            dfs1(i);
    memset(use, 0, sizeof use);
    
    while(!s.empty()) {
        int a=s.top();
        s.pop();
        if(!use[a])
            nrc++,
            dfs2(a);
    }
}



int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	w = vector <vector <int>> (n, vector<int>(m, 0));

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> w[i][j];

	for(int i = 0; i < n; i++) {
		vector <pair<int, int>> vec;
		for(int j = 0; j < m; j++)
			vec.push_back({w[i][j], j});
		sort(vec.begin(), vec.end());

		for(int h = 1; h < vec.size(); h++) {
			int j2 = vec[h].nd;
			int j1 = vec[h - 1].nd;
			g[i * m + j2].push_back(i * m + j1),
			gt[i * m + j1].push_back(i * m + j2);
			if(vec[h].st == vec[h - 1].st)
				g[i * m + j1].push_back(i * m + j2),
				gt[i * m + j2].push_back(i * m + j1);
		}
	}

	for(int j = 0; j < m; j++) {
		vector <pair<int, int>> vec;
		for(int i = 0; i < n; i++)
			vec.push_back({w[i][j], i});

		sort(vec.begin(), vec.end());

		for(int h = 1; h < vec.size(); h++) {
			int i2 = vec[h].nd;
			int i1 = vec[h - 1].nd;

			g[i2 * m + j].push_back(i1 * m + j),
			gt[i1 * m + j].push_back(i2 * m + j);
			if(vec[h].st == vec[h - 1].st)
				g[i1 * m + j].push_back(i2 * m + j),
				gt[i2 * m + j].push_back(i1 * m + j);
		}
	}

	// dbg(g[0]);
	// dbg(g[1]);
	// dbg(g[2]);
	// dbg(g[3]);
	// dbg(gt[0]);
	// dbg(gt[1]);
	// dbg(gt[2]);
	// dbg(gt[3]);

	SCC();

	// dbg(nrc);
	// dbg(c[1]);
	// dbg(c[2]);
	// dbg(c[3]);
	// dbg(c[4]);

	for(int i = 0; i < n * m; i++)
		for(auto j : g[i])
			if(cc[i] != cc[j])
				v[cc[i]].push_back(cc[j]), gr[cc[j]]++;

	// dbg(v[1]);
	// dbg(v[2]);
	// dbg(v[3]);
	// dbg(v[4]);
	queue <int> q;
	memset(use, 0, sizeof use);
	vector <int> topsort;

	for(int i = 1; i <= nrc; i++)
		if(!use[i] && gr[i] == 0)
			q.push(i);

	while(!q.empty()) {
		auto x = q.front(); q.pop();
		topsort.push_back(x);
		for(auto i : v[x]) {
			gr[i]--;
			if(gr[i] == 0)
				q.push(i);
		}

	}

	for(int i = topsort.size() - 1; i >= 0; i--) {
		for(auto j : v[topsort[i]])
			val[topsort[i]] = max(val[topsort[i]], val[j]);
		val[topsort[i]]++;
		for(auto j : c[topsort[i]])
			w[j / m][j % m] = val[topsort[i]];
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cout << w[i][j] << " \n"[j + 1 == m];

}