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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	map<pair<int, int>, int> q;
	auto query = [&](int l, int r){ // returns left dif <= right dif
		if(q.count({l, r})){
			return q[{l, r}];
		}
		cout << "1 " << l << " " << r << endl;
		string res;
		cin >> res;
		return q[{l, r}] = res == "TAK";
	};
	auto answer = [&](int x, int y){
		cout << "2 " << x << " " << y;
		exit(0);
	};
	int n, k;
	cin >> n >> k;
	if(n == 2){
		answer(1, 2);
	}
	auto reduce = [&](int low, int high)->vector<int>{
		if(high - low + 1 < 3){
			vector<int> res;
			for(int i = low; i <= high; ++ i){
				res.push_back(i);
			}
			return res;
		}
		while(high - low + 1 > 3){
			int x = high - low + 1;
			if(x % 4 == 2 || x % 4 == 1){
				x = (x + 1) / 2;
			}
			else{
				x = (x + 3) / 2;
			}
			x /= 2;
			int u = low + x, v = high - x;
			query(u, v) ? (low = u - x, high = u + x) : (low = v - x, high = v + x);
		}
		vector<int> res{query(low, low + 1), query(low, low + 2), query(low + 1, low + 2)};
		if(res[0] && res[1]){
			return {low};
		}
		else if(res[2]){
			return {low + 1};
		}
		else{
			return {low + 2};
		}
	};
	int u = reduce(1, n)[0];
	vector<int> cand;
	vector<int> t = reduce(1, u - 1), tt = reduce(u + 1, n);
	for(auto x: t){
		cand.push_back(x);
	}
	for(auto x: tt){
		cand.push_back(x);
	}
	int m = int(cand.size());
	vector<vector<int>> table(m, vector<int>(m));
	for(int i = 0; i < m; ++ i){
		for(int j = i + 1; j < m; ++ j){
			table[i][j] = query(cand[i], cand[j]);
		}
	}
	for(int i = 0; i < m; ++ i){
		bool ok = true;
		for(int j = i + 1; j < m; ++ j){
			if(!table[i][j]){
				ok = false;
				break;
			}
		}
		if(ok){
			answer(min(u, cand[i]), max(u, cand[i]));
		}
	}
	return 0;
}

/*
n = 9, k = 2;
5, 9
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////