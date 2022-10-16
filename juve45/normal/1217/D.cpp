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

const int N = 5500;
int n, use[N];
vector <int> g[N], gt[N], c[N];
int a, b, m, nrc;
pair <int, int> e[N];
stack <int> s;

void dfs(int node, int col = 1) {
	use[node] = col;
	for(auto i : g[node])
		if(!use[i]) 
			dfs(i, 3 - col);
}

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
}
 
void SCC() {
    for(int i=1;i<=n;i++)
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
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		e[i] = {a, b};
		g[a].push_back(b);
		gt[b].push_back(a);
	}

	SCC();

	if(nrc == n) {
		cout << "1\n";
		for(int i = 1; i <= m; i++) cout << 1 << ' ';
		cout << '\n';
		return 0;
	}

	cout << "2\n";
	for(int i = 1; i <= m; i++) {
		if(e[i].st < e[i].nd) cout << "1 ";
		else cout << "2 ";
	}
	cout << '\n';

}