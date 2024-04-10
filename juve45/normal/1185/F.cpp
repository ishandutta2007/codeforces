#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out <<  p.st << ' ' << p.nd ; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, p[N], w[N], v[N], cheap[515], cheap2[525], m, cnt[515], k, x, f[555];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) 
			cin >> x, v[i] |= (1 << (x - 1));
	}

	vector <pair<pair<int, int>, int>> pizzas;
	
	p[0] = 1e9 + 100;
	for(int i = 1; i <= m; i++) {
		cin >> p[i] >> k;
		for(int j = 1; j <= k; j++) 
			cin >> x, w[i] |= (1 << (x - 1));
		pizzas.push_back({{p[i], w[i]}, i});
		// dbg(i, [i]);
	}

	sort(pizzas.begin(), pizzas.end());
	// dbg(pizzas);
	vector<int> need;

 	for(auto i : pizzas)
		if(f[i.st.nd] == 2) continue;
		else {
			f[i.st.nd]++;
			need.push_back(i.nd);
		}

	for(int msk = 0; msk < 512; msk++) {
		for(int i = 1; i <= n; i++)
			if((msk & v[i]) == v[i])
				cnt[msk]++;
		// dbg(msk, cnt[msk]);
	}

	// dbg_v(cnt, 512);
	int cnt_ans = 0;
	pair<int, int> ans;
	int min_cost = 2e9 + 1000;

	// dbg(need);
	for(auto i : need)
		for(auto j : need) {
			if(i == j) continue;
			// dbg(i, j);
			if(cnt[w[i] | w[j]] == cnt_ans && min_cost > p[i] + p[j] || cnt[w[i] | w[j]] > cnt_ans) {
				cnt_ans = cnt[w[i] | w[j]];
				min_cost = p[i] + p[j];
				ans = {i, j};
			}
		}

	// dbg(cnt_ans, min_cost);
	// dbg(w[1], w[2], w[3]);
	// dbg(cnt[w[1] | w[2]]);
	// dbg(cnt[w[2] | w[3]]);
			// cheap2[msk1 | msk2] = min(cheap[msk1] + cheap[msk2], cheap2[msk1 | msk2]);
	cout << ans << '\n';

}