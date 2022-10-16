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
long long n, l[N], q, a, h, node;

vector <int> lg[N];
vector <long long> sum[N];
vector <pair<int, int> > v[N];

void dfs(int node) {
	lg[node].push_back(0);
	for(auto i : v[node]) {
		dfs(i.st);
		for(auto j : lg[i.st])
			lg[node].push_back(j + i.nd);
	}
	sort(lg[node].begin(), lg[node].end());
	sum[node].push_back(lg[node][0]);
	for(int i = 1; i < lg[node].size(); i++)
		sum[node].push_back(1LL * lg[node][i] + sum[node].back());
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> q;

	for(int i = 1; i < n; i++) {
		cin >> l[i];
		// dbg(i, (i + 1)/ 2, i + 1);
		v[(i + 1) / 2].push_back({i + 1, l[i]});
	}

	dfs(1);

	for(int i = 1; i <= q; i++) {
		cin >> node >> h;


		int pos = upper_bound(lg[node].begin(), lg[node].end(), h) - lg[node].begin();
		long long ans = 0;
		if(pos) ans += 1LL * h * pos - sum[node][pos - 1];
		int last = node;
		int curr = node / 2;
		long long off = l[node - 1];
		// dbg(ans);
		while(curr != 0) {
			if(off > h) break;
			ans += 1LL * h - off;
			// dbg(ans);
			int vec = 2 * curr + 2 * curr + 1 - last;
			long long add = l[vec - 1];
			// dbg(vec);
			int pos = upper_bound(lg[vec].begin(), lg[vec].end(), h - off - add) - lg[vec].begin();
			// dbg(pos, lg[vec].size(), sum);
			if(pos) ans += 1LL * h * pos - sum[vec][pos - 1] - 1LL * (off + add) * pos;
			last = curr;
			curr /= 2;
			off += l[last - 1];
		}
		cout << ans << '\n';
	}
}