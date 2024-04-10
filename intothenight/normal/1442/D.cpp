#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


const long long minf = numeric_limits<long long>::min();
struct rollback_knapsack{
	int mxval;
	vector<vector<long long>> dp;
	rollback_knapsack(int mxval): mxval(mxval), dp({vector<long long>(mxval + 1, minf)}){
		dp[0][0] = 0;
	}
	void insert(int w, long long cost){
		int t = time();
		dp.push_back(dp.back());
		for(auto i = mxval - w; i >= 0; -- i){
			if(dp[t - 1][i] != minf){
				ctmax(dp[t][i + w], dp[t - 1][i] + cost);
			}
		}
	}
	int time(){
		return (int)dp.size();
	}
	void reverse_to(int t){
		dp.resize(t);
	}
};

template<class E>
struct querytree{ // for a data structure supporting true O(T(n)) insertion, support deletion in O(T(n)) offline.
	int n; // max query range
	vector<vector<E>> queues;
	querytree(int n): n(n), queues(n << 1){ }
	template<bool First = true>
	void queue_up(E e, int ql, int qr, int u = 0, int l = 0, int r = numeric_limits<int>::max()){
		if(First) r = n;
		if(qr <= l || r <= ql) return;
		if(ql <= l && r <= qr) queues[u].push_back(e);
		else{
			int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
			queue_up<false>(e, ql, qr, v, l, m), queue_up<false>(e, ql, qr, w, m, r);
		}
	}
	template<class T = int>
	void solve(function<void(E)> insert, function<int()> time, function<void(int)> reverse_to, function<void(int)> answer){
		function<void(int, int, int)> dfs = [&](int u, int l, int r){
			int timer = time();
			for(auto e: queues[u]) insert(e);
			if(r - l == 1) answer(l);
			else{
				int m = l + (r - l >> 1), v = u + 1, w = u + (m - l << 1);
				dfs(v, l, m), dfs(w, m, r);
			}
			reverse_to(timer);
		};
		dfs(0, 0, n);
	} // O(q log n) insert calls and O(n) answer calls
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n);
	vector<vector<long long>> pref(n);
	vector<long long> sum(n);
	for(auto i = 0; i < n; ++ i){
		int t;
		cin >> t;
		a[i].resize(t);
		pref[i].resize(t + 1);
		for(auto j = 0; j < t; ++ j){
			cin >> a[i][j];
			sum[i] += a[i][j];
			pref[i][j + 1] = pref[i][j] + a[i][j];
		}
	}
	querytree<pair<int, long long>> qt(n);
	for(auto i = 0; i < n; ++ i){
		qt.queue_up({(int)a[i].size(), sum[i]}, 0, i);
		qt.queue_up({(int)a[i].size(), sum[i]}, i + 1, n);
	}
	long long res = numeric_limits<long long>::min();
	rollback_knapsack ks(k);
	auto insert = [&](pair<int, long long> e){
		ks.insert(e.first, e.second);
	};
	auto time = [&](){
		return ks.time();
	};
	auto reverse_to = [&](int t){
		ks.reverse_to(t);
	};
	auto answer = [&](int i){
		for(auto w = 0; w <= k; ++ w){
			if(ks.dp.back()[w] != minf && k - w < (int)pref[i].size()){
				ctmax(res, ks.dp.back()[w] + pref[i][k - w]);
			}
		}
	};
	qt.solve(insert, time, reverse_to, answer);
	cout << res << "\n";
	return 0;
}
 
/*
 
*/
 
////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////