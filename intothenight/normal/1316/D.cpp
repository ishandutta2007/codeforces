#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n));
	vector<string> res(n, string(n, '?'));
	auto kill = [](){
		cout << "INVALID";
		exit(0);
	};
	vector<pair<int, int>> temp, cycle;
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			auto &[x, y] = a[i][j];
			cin >> x >> y;
			if(x != -1){
				-- x, -- y;
				res[x][y] = 'X';
				temp.emplace_back(x, y);
			}
			else{
				cycle.emplace_back(i, j);
			}
		}
	}
	sort(temp.begin(), temp.end()), temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
	for(auto [x, y]: temp){
		if(a[x][y] != pair<int, int>{x, y}){
			kill();
		}
	}
	auto inrange = [&](int x, int y){
		return 0 <= x && x < n && 0 <= y && y < n;
	};
	vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	string conv("ULDR");
	function<void(pair<int, int>, pair<int, int>)> solve = [&](pair<int, int> cur, pair<int, int> dest){
		for(int i = 0; i < 4; ++ i){
			auto [dx, dy] = dr[i];
			int nx = cur.first + dx, ny = cur.second + dy;
			if(inrange(nx, ny) && res[nx][ny] == '?' && a[nx][ny] == dest){
				res[nx][ny] = conv[i];
				solve({nx, ny}, dest);
			}
		}
	};
	for(auto p: temp){
		solve(p, p);
	}
	for(auto [x, y]: cycle){
		if(res[x][y] == '?'){
			int nx, ny, i;
			bool ok = false;
			for(i = 0; i < 4; ++ i){
				auto [dx, dy] = dr[i];
				nx = x + dx, ny = y + dy;
				if(inrange(nx, ny) && res[nx][ny] == '?' && a[nx][ny] == pair<int, int>{-1, -1}){
					ok = true;
					break;
				}
			}
			if(!ok){
				kill();
			}
			res[nx][ny] = conv[i];
			res[x][y] = conv[(i + 2) % 4];
			solve({x, y}, {-1, -1});
			solve({nx, ny}, {-1, -1});
		}
	}
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < n; ++ j){
			if(res[i][j] == '?'){
				kill();
			}
		}
	}
	cout << "VALID\n";
	for(auto &s: res){
		cout << s << "\n";
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