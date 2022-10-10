#include <bits/stdc++.h>
using namespace std;

// adjacency_oracle(u, v) returns [there's an edge u->v]
// O(n log n * T) where T is time to process adjacency_oracle call
vector<int> find_a_hamiltonian_path_in_tournament(int n, auto adjacency_oracle){
	vector<int> path(n);
	iota(path.begin(), path.end(), 0);
	auto recurse = [&](auto recurse, int l, int r){
		if(r - l == 1) return;
		int m = l + (r - l >> 1);
		recurse(recurse, l, m), recurse(recurse, m, r);
		inplace_merge(path.begin() + l, path.begin() + m, path.begin() + r, [&](int u, int v){ return adjacency_oracle(u, v); });
	};
	recurse(recurse, 0, n);
	return path;
}

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
	int n;
	vector<vector<T>> data;
	Compare cmp;
	T T_id;
	range_minmax_query_solver(){ }
	range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
		for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			data.emplace_back(n - (p << 1) + 1);
			for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
		}
	}
	T query(int l, int r){ // O(1)
		if(l >= r) return T_id;
		int d = __lg(r - l);
		return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		auto q1 = [&](int u, int v){
			assert(u != v);
			cout << "1 " << u << " " << v << endl;
			int resp;
			cin >> resp;
			if(!~resp) exit(0);
			return resp;
		};
		auto q2 = [&](int from, vector<int> to){
			cout << "2 " << from << " " << (int)to.size() << " ";
			for(auto u: to){
				cout << u << " ";
			}
			cout << endl;
			int resp;
			cin >> resp;
			if(!~resp) exit(0);
			return resp;
		};
		auto path = find_a_hamiltonian_path_in_tournament(n, q1);
		vector<int> left(n);
		for(auto i = n - 1, j = n - 1; j >= 0; -- j){
			while(i > 0 && (i > j || q2(path[j], {path.begin(), path.begin() + i}))){
				-- i;
			}
			left[j] = i;
		}
		range_minmax_query_solver rmq(left);
		vector<vector<int>> g;
		for(auto i = n - 1; i >= 0; -- i){
			int j = i;
			while(rmq.query(j, i + 1) < j){
				j = rmq.query(j, i + 1);
			}
			g.push_back({path.begin() + j, path.begin() + i + 1});
			i = j;
		}
		reverse(g.begin(), g.end());
		vector<vector<int>> res(n, vector<int>(n));
		for(auto i = 0; i < (int)g.size(); ++ i){
			for(auto u: g[i]){
				for(auto v: g[i]){
					res[u][v] = true;
				}
			}
			for(auto u: g[i]){
				for(auto j = i + 1; j < (int)g.size(); ++ j){
					for(auto v: g[j]){
						res[u][v] = true;
					}
				}
			}
		}
		cout << "3\n";
		for(auto a: res){
			for(auto x: a){
				cout << x;
			}
			cout << "\n";
		}
		cout << endl;
		int resp;
		cin >> resp;
		if(!~resp) exit(0);
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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