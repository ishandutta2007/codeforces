#include <bits/stdc++.h>
using namespace std;

template<class E> // Noam's queue trick
struct queryqueue{ // for a commutative data structure supporting true O(T(n)) insertion, support front-deletion in O(T(n) log n) online.
	function<void(E)> insert;
	function<int()> time;
	function<void(int)> reverse_to;
	int zero_cnt = 0;
	vector<int> log;
	vector<pair<bool, E>> s, tmp[2]; // 0: delete state, 1: insert state
	queryqueue(function<void(E)> insert, function<int()> time, function<void(int)> reverse_to): insert(insert), time(time), reverse_to(reverse_to), log({time()}){ }
	void pop(){
		if(!zero_cnt){
			zero_cnt = (int)s.size(), reverse(s.begin(), s.end()), reverse_to(log[0]), log.resize(1);
			for(auto &p: s) p.first = false, insert(p.second), log.push_back(time());
		}
		while(s.back().first) tmp[1].push_back(s.back()), s.pop_back();
		for(auto sz = zero_cnt & -zero_cnt, i = 0; i < sz; ++ i) assert(!s.back().first), tmp[0].push_back(s.back()), s.pop_back();
		reverse_to(log[s.size()]), log.resize(s.size() + 1);
		for(auto z: {1, 0}) for(; !tmp[z].empty(); tmp[z].pop_back()) insert(tmp[z].back().second), log.push_back(time()), s.push_back(tmp[z].back());
		assert(!s.back().first), s.pop_back(), reverse_to(log[s.size()]), log.resize(s.size() + 1), -- zero_cnt;
	}
	void push(const E &e){
		s.push_back({true, e}), insert(e);
	}
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


const int mx = 4000;
const int inf = numeric_limits<int>::max() / 2;
struct knapsack{
	vector<vector<int>> dp;
	knapsack(): dp{vector<int>(mx + 1)}{ }
	void insert(int cost, int happy){
		dp.push_back(dp.back());
		for(auto i = mx; i >= cost; -- i){
			ctmax(dp.back()[i], dp.back()[i - cost] + happy);
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, p;
	cin >> n >> p;
	vector<array<int, 3>> a(n); // l, r, cost, happy
	for(auto i = 0; i < n; ++ i){
		int c, h, t;
		cin >> c >> h >> t;
		a[i] = {t, c, h};
	}
	sort(a.begin(), a.end());
	int qn;
	cin >> qn;
	vector<array<int, 3>> query(qn);
	for(auto qi = 0; qi < qn; ++ qi){
		int t, b;
		cin >> t >> b;
		query[qi] = {t, b, qi};
	}
	sort(query.begin(), query.end());
	knapsack ks;
	auto insert = [&](array<int, 2> e){
		ks.insert(e[0], e[1]);
	};
	auto time = [&](){
		return (int)ks.dp.size();
	};
	auto reverse_to = [&](int t){
		ks.dp.resize(t);
	};
	queryqueue<array<int, 2>> qq(insert, time, reverse_to);
	int i = 0, j = 0;
	vector<int> res(qn);
	for(auto [t, b, qi]: query){ // t - p < x <= t
		while(j < n && a[j][0] <= t){
			qq.push({a[j][1], a[j][2]});
			++ j;
		}
		while(i < n && a[i][0] <= t - p){
			qq.pop();
			++ i;
		}
		res[qi] = ks.dp.back()[b];
	}
	for(auto x: res){
		cout << x << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////