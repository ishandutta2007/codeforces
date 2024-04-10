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

const int N = 2019;
vector <int> g[N], gt[N], c[N], v[N];
int use[N], a, b, n, m, nrc, w[N], gr[N], res[N], vv[N];
stack <int> s;
string ss[N];
 
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
    w[k] = nrc;
}
 
void SCC() {
    for(int i=0;i<n + m;i++)
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

bool check() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j< m; j++) {
			if(ss[i][j] == '=' && res[i] != res[j + n])
				return 0;
			if(ss[i][j] == '<' && res[i] >= res[j + n])
				return 0;
			if(ss[i][j] == '>' && res[i] <= res[j + n])
				return 0;
		}
	return 1;
}


void assign(int i, int val) {
	for(auto j : c[i])
		res[j] = val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> ss[i];
		for(int j = 0 ;j < m; j++) {
			if(ss[i][j] != '<')
				g[i].push_back(j + n),
				gt[j + n].push_back(i);
			if(ss[i][j] != '>')
				g[j + n].push_back(i),
				gt[i].push_back(j + n);
		}
	}

	// dbg(g[0]);

	SCC();

	for(int i = 0; i < n + m; i++)
		for(auto j : g[i])
			if(w[i] != w[j]) {
				v[w[j]].push_back(w[i]);
				gr[w[i]]++;
			}


	vector <int> ans;
	queue <int> q;

	// dbg(nrc);
	// dbg_v(gr, 8);
	for(int i = 1; i <= nrc; i++)
		if(gr[i] == 0) 
			q.push(i), assign(i, 1), vv[i] = 1;

	while(!q.empty()) {
		auto x = q.front();
		q.pop();
		ans.push_back(x);
		for(auto i : v[x]) {
			gr[i]--;
			if(gr[i] == 0) {
				q.push(i), assign(i, vv[x] + 1), vv[i] = vv[x] + 1;
			}
		}
	}

	if(!check()) return cout << "No\n", 0;

	cout << "Yes\n";
	for(int i = 0; i < n; i++) cout << res[i] << ' ';
	cout << '\n';
	for(int i = n; i < m + n; i++) cout << res[i] << ' ';
}