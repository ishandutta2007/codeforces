#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<int B>
struct Query{
	int l, r, k, ind;
	bool operator<(const Query &otr) const{
		if(l / B != otr.l / B) return pair<int, int>(l, r) < pair<int, int>(otr.l, otr.r);
		return (l / B & 1) ? (r < otr.r) : (r > otr.r);
	}
};
template<typename T, typename Q, typename I, typename D, typename A>
vector<T> answer_query_offline(vector<Q> query, I ins, D del, A ans){
	sort(query.begin(), query.end());
	vector<T> res(query.size());
	int l = 0, r = 0;
	for(auto q: query){
		while(l > q.l) ins(-- l);
		while(r < q.r) ins(r ++);
		while(l < q.l) del(l ++);
		while(r > q.r) del(-- r);
		res[q.ind] = ans(q);
	}
	return res;
}

struct unital_sorter{
	int N, M;
	vector<int> list, pos, cnt;
	vector<pair<int, int>> bound;
	unital_sorter(int N, int M): N(N), M(M), list(N), pos(N), cnt(N), bound(M + 1, {N, N}){
		bound[0] = {0, N};
		iota(list.begin(), list.end(), 0);
		iota(pos.begin(), pos.end(), 0);
	}
	void insert(int x){
		-- bound[cnt[x]].second;
		-- bound[cnt[x] + 1].first;
		int y = list[bound[cnt[x] ++].second];
		swap(pos[x], pos[y]);
		swap(list[pos[x]], list[pos[y]]);
	}
	void erase(int x){
		int y = list[bound[cnt[x] - 1].second];
		swap(pos[x], pos[y]);
		swap(list[pos[x]], list[pos[y]]);
		++ bound[cnt[x]].first;
		++ bound[-- cnt[x]].second;
	}
	void print(int X, int Y){
		cout << "List = ";
		copy(list.end() - X, list.end(), ostream_iterator<int>(cout, " "));
		cout << "\n";
		cout << "Pos = ";
		copy(pos.begin(), pos.begin() + X, ostream_iterator<int>(cout, " "));
		cout << "\n";
		cout << "Count = ";
		copy(cnt.begin(), cnt.begin() + X, ostream_iterator<int>(cout, " "));
		cout << "\n";
		cout << "Bound = ";
		for(int i = 0; i < Y; ++ i){
			cout << "(" << bound[i].first << ", " << bound[i].second << ")";
		}
		cout << endl;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> c(n);
	copy_n(istream_iterator<int>(cin), n, c.begin());
	for(auto &col: c){
		-- col;
	}
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> ett, in(n), out(n);
	function<void(int, int)> dfs = [&](int u, int p){
		in[u] = int(ett.size());
		ett.push_back(u);
		for(auto v: adj[u]){
			if(v != p){
				dfs(v, u);
			}
		}
		out[u] = int(ett.size());
	};
	dfs(0, -1);
	const int sz = 300;
	vector<Query<sz>> query(m);
	for(int i = 0; i < m; ++ i){
		int u, k;
		cin >> u >> k, -- u;
		query[i] = {in[u], out[u], k, i};
	}
	unital_sorter s(100000, 100000);
	auto ins = [&](int i){
		s.insert(c[ett[i]]);
	};
	auto del = [&](int i){
		s.erase(c[ett[i]]);
	};
	auto ans = [&](const auto &q){
		return s.N - s.bound[q.k].first;
	};
	auto res = answer_query_offline<int>(query, ins, del, ans);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////