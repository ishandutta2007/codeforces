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
	int n, m, initx, inity, lim_l, lim_r;
	cin >> n >> m >> initx >> inity >> lim_l >> lim_r, -- initx, -- inity;
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	typedef tuple<int, int, int> tpl; // len, x, y;
	priority_queue<tpl, vector<tpl>, greater<tpl>> q;
	q.push({0, initx, inity});
	vector<vector<int>> opt(n, vector<int>(m, 2e9));
	opt[initx][inity] = 0;
	vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	auto inrange = [&](int x, int y){
		return 0 <= x && x < n && 0 <= y && y < m;
	};
	int res = 0;
	while(!q.empty()){
		auto [len, x, y] = q.top();
		q.pop();
		if(len == opt[x][y]){ // l + r = len, r - l = x - initx
			int right = len + y - inity >> 1;
			int left = len - right;
			if(left <= lim_l && right <= lim_r){
				++ res;
				for(int i = 0; i < 4; ++ i){
					auto [dx, dy] = dr[i];
					int nx = x + dx, ny = y + dy;
					if(inrange(nx, ny) && a[nx][ny] == '.' && opt[nx][ny] > opt[x][y] + i % 2){
						opt[nx][ny] = opt[x][y] + i % 2;
						q.push({opt[nx][ny], nx, ny});
					}
				}
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////