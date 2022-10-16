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

            
struct TwoSat {
    int n;
    vector<vector<int>> graph;
    vector<int> sol, vis, order;
 
    TwoSat(int n) : n(n), graph(2 * n), sol(n, -1), vis(2 * n, 0) {}
    
    void Implies(int a, int b) {
        graph[a].push_back(b);
        graph[b ^ 1].push_back(a ^ 1);
    };

    // poz(a) = 2 * a     - voc
    // neg(a) = 2 * a + 1 - cons
    void Either(int a, int b) { Implies(a ^ 1, b); }
 
    void dfs1(int node) {
        if (vis[node]) return; 
        vis[node] = 1;
        for (auto vec : graph[node]) 
            dfs1(vec);
        order.push_back(node);
    }
    void dfs2(int node) {
        if (sol[node / 2] == node % 2) throw 5;
        sol[node / 2] = !(node % 2);
        if (!vis[node]) return;
        vis[node] = vis[node ^ 1] = 0;
        for (auto vec : graph[node ^ 1]) 
            dfs2(vec ^ 1); 
    }
 
    vector<int> Solve() {
    	//throws int if no solution
        for (int i = 0; i < 2 * n; ++i)
            dfs1(i);
        for (int i = 2 * n - 1; i >= 0; --i)
            if (vis[order[i]])
                dfs2(order[i]);
        return sol;
    };
};
 
const int N = 220;
const int M = 4 * N * N;
int n, l;	
int p1[M], p2[M], m;
char t1[M], t2[M];
string s, sigma;

bool check(string s) {
	if(s == "X") return 0;

	TwoSat sat(s.size());

	for(int i = 1; i <= m; i++) 
		sat.Implies(2 * p1[i] + (t1[i] == 'C'), 2 * p2[i] + (t2[i] == 'C'));

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '*') continue;
		if(sigma[s[i] - 'a'] == 'V')
			sat.Implies(2 * i + 1, 2 * i);	
		else
			sat.Implies(2 * i, 2 * i + 1);	
	}

	// dbg_ok;

	try {
		// dbg(s);
		sat.Solve();
		return 1;
	} catch(int) {
		return 0;
	}

}

string inc(string s) {
	int sz = s.size();
	while(s.size() > 0 && s.back() == ('a' + l - 1))
		s.pop_back();
	if(s.empty()) return "X";
	s[s.size() - 1]++;
	while(s.size() < sz) s += 'a';
	return s;
}

string fwd(string ss) {
	for(auto &i : ss) {
		if(i == '*') {
			int use[] = {0, 0}, ok = 0;
			for(int j = 0; j < l; j++) {
				i = 'a' + j;
				if(use[sigma[i - 'a'] == 'V'] == 0 && check(ss)) {ok = 1; break;}
				use[sigma[i - 'a'] == 'V'] = 1;
			}
			if(!ok) return "-1";
			// assert(false);
		}
	}
	return ss;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> sigma;	l = sigma.size();

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> p1[i] >> t1[i] >> p2[i] >> t2[i];
		p1[i]--;
		p2[i]--;
	}
	cin >> s;
	string ss = s;

	int last = ss.size();

	if(check(ss)) {
		cout << ss << '\n';
		return 0;
	}


	for(int pre = n - 1; pre >= 0; pre--) {
		ss[pre]++;
		// dbg(ss);
		if(ss[pre] < 'a' + l && check(ss))
			return cout << fwd(ss) << '\n', 0;
		ss[pre]++;
		while(ss[pre] < 'a' + l && sigma[ss[pre] - 'a'] == sigma[ss[pre] - 'a' - 1]) ss[pre]++;

		if(ss[pre] < 'a' + l && check(ss))
			return cout << fwd(ss) << '\n', 0;

		ss[pre] = '*';
		// int use[] = {0, 0};
		// while(ss[pre] != 'a' + l && (use[sigma[s[pre] - 'a'] == 'V'] == 1 || !check(ss))) {
		// 	use[sigma[s[pre] - 'a'] == 'V'] = 1;
		// 	ss[pre]++;
		// }
	}

	cout << "-1\n";
	// dbg(ss);
}	

//VVVVCVCVVCVVVVCVCCCCCCCVCC