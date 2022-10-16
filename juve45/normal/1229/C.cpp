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
 
const int N = 100100;
int n, m, last[N], in[N], out[N], val[N], a, b, q, ch[N], use[N];
long long ans;
const int BKT = 1000;
vector <int> v[N], w[N];
 
void calc() {
	ans = 0;
	for(int i = 1; i <= n; i++) {
		for(auto j : v[i])
			if(val[j] > val[i])
				in[i]++;
			else out[i]++;
		ans += 1LL * in[i] * out[i];
	}
 
}

void apply() {
	memset(last, 0, sizeof last);
	for(int i = 1; i <= n; i++) w[i].clear();
}
 
int main() {
	ios_base::sync_with_stdio(false);
 
	cin >> n >> m;	
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
 
	for(int i = 1; i <= n; i++)
		val[i] = i;
 
	calc();
	cout << ans << '\n';
 
	cin >> q;
 
	for(int i = 1; i <= q; i++)  {
		
		if(i % BKT == 0) apply();

		cin >> ch[i];
		int node = ch[i];
 
		ans -= 1LL * in[node] * out[node];
 
		if(last[node] == 0) {
			// dbg(node, "new");
			for(auto j : v[node]) {
				if(val[j] > val[node]) {
					// dbg(j);
					ans -= 1LL * in[j] * out[j];
					out[j]--;
					in[j]++;
					w[j].push_back(node);
					ans += 1LL * in[j] * out[j];
					// dbg(in[j], out[j]);
				}
			}
			last[node] = i;
			w[node].clear();
		} else {
			// dbg(node);
			for(auto j : w[node]) 
				if(val[j] > val[node] && !use[j]) {
					// dbg(j);
					use[j] = 1;
					ans -= 1LL * in[j] * out[j];
					out[j]--;
					in[j]++;
					w[j].push_back(node);
					ans += 1LL * in[j] * out[j];
				}
			for(auto j : w[node]) 
				if(val[j] > val[node]) 
					use[j] = 0;

			w[node].clear();
		}
 
		val[node] = n + i;
		in[node] = 0;
		out[node] = v[node].size();
		ans +=1LL * in[node] * out[node];
 
		// dbg_v(val, n + 1);
 
		cout << ans << '\n';	
	}
 
}