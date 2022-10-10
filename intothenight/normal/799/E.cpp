#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

// B must be equal or greater than 2
// Partition the sorted elements according to capacity, and track the sum of each blocks
template<class T, class U, class Compare = less<>, class Plus = plus<>, class Minus = minus<>>
struct block_sum_processor{
	int B;
	Plus op;
	Minus inv_op;
	vector<U> sum;
	vector<multiset<T>> data;
	vector<int> capacity;
	block_sum_processor(int B = 2, U init = {}, Compare cmp = less<>(), Plus op = plus<>(), Minus inv_op = minus<>()): B(B), sum(B, init), data(B), capacity(B - 1), op(op), inv_op(inv_op){ }
	// O(B log n)
	void insert(T x){
		sum[0] = op(sum[0], x);
		data[0].insert(x);
		for(auto i = 0; i < B - 1 && (int)data[i].size() > capacity[i]; ++ i){
			sum[i + 1] = op(sum[i + 1], *data[i].rbegin());
			data[i + 1].insert(data[i + 1].begin(), *data[i].rbegin());
			sum[i] = inv_op(sum[i], *data[i].rbegin());
			data[i].erase(prev(data[i].end()));
		}
	}
	// O(B log n)
	void erase(T x){
		int i = 0;
		while(i < B && data[i].find(x) == data[i].end()) ++ i;
		assert(i < B);
		data[i].erase(data[i].find(x));
		sum[i] = inv_op(sum[i], x);
		for(; i < B - 1 && (int)data[i].size() < capacity[i] && !data[i + 1].empty(); ++ i){
			sum[i] = op(sum[i], *data[i + 1].begin());
			data[i].insert(data[i].end(), *data[i + 1].begin());
			sum[i + 1] = inv_op(sum[i + 1], *data[i + 1].begin());
			data[i + 1].erase(data[i + 1].begin());
		}
	}
	// O(B log n)
	void increase_capacity(int i = 0){
		assert(0 <= i && i < B - 1);
		for(++ capacity[i]; i < B - 1 && (int)data[i].size() < capacity[i] && !data[i + 1].empty(); ++ i){
			sum[i] = op(sum[i], *data[i + 1].begin());
			data[i].insert(data[i].end(), *data[i + 1].begin());
			sum[i + 1] = inv_op(sum[i + 1], *data[i + 1].begin());
			data[i + 1].erase(data[i + 1].begin());
		}
	}
	// O(B log n)
	void decrease_capacity(int i = 0){
		assert(0 <= i && i < B - 1 && capacity[i]);
		for(-- capacity[i]; i < B - 1 && (int)data[i].size() > capacity[i]; ++ i){
			sum[i + 1] = op(sum[i + 1], *data[i].rbegin());
			data[i + 1].insert(data[i + 1].begin(), *data[i].rbegin());
			sum[i] = inv_op(sum[i], *data[i].rbegin());
			data[i].erase(prev(data[i].end()));
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> cost(n);
	for(auto i = 0; i < n; ++ i){
		cin >> cost[i];
	}
	vector<int> type(n);
	for(auto bit = 0; bit < 2; ++ bit){
		int cnt;
		cin >> cnt;
		for(auto rep = 0; rep < cnt; ++ rep){
			int i;
			cin >> i, -- i;
			type[i] |= 1 << bit;
		}
	}
	array<vector<int>, 4> a;
	for(auto i = 0; i < n; ++ i){
		a[type[i]].push_back(cost[i]);
	}
	array<vector<long long>, 4> pref{};
	for(auto t = 0; t < 4; ++ t){
		sort(a[t].begin(), a[t].end());
		pref[t].resize((int)a[t].size() + 1);
		for(auto i = 0; i < (int)a[t].size(); ++ i){
			pref[t][i + 1] = pref[t][i] + a[t][i];
		}
	}
	long long res = numeric_limits<long long>::max();
	int low = max({0, 2 * k - m, k - min((int)a[1].size(), (int)a[2].size())});
	int high = min(k, (int)a[3].size());
	if(low <= high){
		block_sum_processor<int, long long> rem;
		for(auto i = 0; i < (int)a[0].size(); ++ i){
			rem.insert(a[0][i]);
		}
		for(auto i = k - low; i < (int)a[1].size(); ++ i){
			rem.insert(a[1][i]);
		}
		for(auto i = k - low; i < (int)a[2].size(); ++ i){
			rem.insert(a[2][i]);
		}
		for(auto i = low; i < (int)a[3].size(); ++ i){
			rem.insert(a[3][i]);
		}
		while(rem.capacity[0] < m - (2 * k - low)){
			rem.increase_capacity();
		}
		ctmin(res, rem.sum[0] + pref[1][k - low] + pref[2][k - low] + pref[3][low]);
		for(auto x = low + 1; x <= high; ++ x){
			rem.insert(a[2][k - (x - 1) - 1]);
			rem.insert(a[1][k - (x - 1) - 1]);
			rem.erase(a[3][x - 1]);
			rem.increase_capacity();
			ctmin(res, rem.sum[0] + pref[1][k - x] + pref[2][k - x] + pref[3][x]);
		}
	}
	res == numeric_limits<long long>::max() ? cout << "-1\n" : cout << res << "\n";
	return 0;
}

/*
6 6 1
10 9 4 1 2 10 
4
1 4 5 6 
2
1 2 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////