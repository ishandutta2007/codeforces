#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	const int mx = n + 1 + m + 1 + 1;
	vector<vector<int>> sum(mx), dif(mx);
	set<array<int, 2>> blocked;
	auto insert = [&](int x, int y)->void{
		blocked.insert({x, y});
		tie(x, y) = pair{x + y, m + 1 + x - y};
		sum[x].push_back(y);
		dif[y].push_back(x);
	};
	for(auto i = 0; i < k; ++ i){
		int x, y;
		cin >> x >> y;
		insert(x, y);
	}
	for(auto x = 0; x <= n + 1; ++ x){
		insert(x, 0);
		insert(x, m + 1);
	}
	for(auto y = 1; y <= m; ++ y){
		insert(0, y);
		insert(n + 1, y);
	}
	for(auto x = 0; x < mx; ++ x){
		ranges::sort(sum[x]);
	}
	for(auto y = 0; y < mx; ++ y){
		ranges::sort(dif[y]);
	}
	bool flip = false;
	// dist, nx, ny, ndir
	long long res = 0;
	auto advance = [&](int x, int y, string dir)->tuple<int, int, int, string>{
		tie(x, y) = pair{x + y, m + 1 + x - y};
		if(dir == "NE"){
			int nx = *ranges::lower_bound(dif[y], x);
			int dist = nx - x >> 1;
			tie(x, y) = pair{nx + y - m - 1 >> 1, nx + m + 1 - y >> 1};
			bool left = blocked.contains({x - 1, y});
			bool down = blocked.contains({x, y - 1});
			if(left == down){
				flip = true;
				return {dist, x - 1, y - 1, "SW"};
			}
			else if(left){
				return {dist, x, y - 1, "SE"};
			}
			else if(right){
				return {dist, x - 1, y, "NW"};
			}
			else{
				assert(false);
			}
		}
		else if(dir == "NW"){
			int ny = *prev(ranges::lower_bound(sum[x], y));
			int dist = y - ny >> 1;
			tie(x, y) = pair{x + ny - m - 1 >> 1, x + m + 1 - ny >> 1};
			bool right = blocked.contains({x + 1, y});
			bool down = blocked.contains({x, y - 1});
			if(right == down){
				flip = true;
				return {dist, x + 1, y - 1, "SE"};
			}
			else if(right){
				return {dist, x, y - 1, "SW"};
			}
			else if(down){
				return {dist, x + 1, y, "NE"};
			}
			else{
				assert(false);
			}
		}
		else if(dir == "SE"){
			int ny = *ranges::lower_bound(sum[x], y);
			int dist = ny - y >> 1;
			tie(x, y) = pair{x + ny - m - 1 >> 1, x + m + 1 - ny >> 1};
			bool left = blocked.contains({x - 1, y});
			bool up = blocked.contains({x, y + 1});
			if(left == up){
				flip = true;
				return {dist, x - 1, y + 1, "NW"};
			}
			else if(left){
				return {dist, x, y + 1, "NE"};
			}
			else if(up){
				return {dist, x - 1, y, "SW"};
			}
			else{
				assert(false);
			}
		}
		else if(dir == "SW"){
			int nx = *prev(ranges::lower_bound(dif[y], x));
			int dist = x - nx >> 1;
			tie(x, y) = pair{nx + y - m - 1 >> 1, nx + m + 1 - y >> 1};
			bool right = blocked.contains({x + 1, y});
			bool up = blocked.contains({x, y + 1});
			if(right == up){
				flip = true;
				return {dist, x + 1, y + 1, "NE"};
			}
			else if(right){
				return {dist, x, y + 1, "NW"};
			}
			else if(up){
				return {dist, x + 1, y, "SE"};
			}
			else{
				assert(false);
			}
		}
		else{
			assert(false);
		}
	};
	int init_x, init_y;
	string init_dir;
	cin >> init_x >> init_y >> init_dir;
	if(init_dir == "NE"){
		init_dir = "NW";
	}
	else if(init_dir == "NW"){
		init_dir = "SW";
	}
	else if(init_dir == "SW"){
		init_dir = "SE";
	}
	else{
		init_dir = "NE";
	}
	tie(std::ignore, init_x, init_y, init_dir) = advance(init_x, init_y, init_dir);
	{
		int x = init_x, y = init_y;
		string dir = init_dir;
		do{
			int dist;
			tie(dist, x, y, dir) = advance(x, y, dir);
			res += dist;
		}while(x != init_x || y != init_y || dir != init_dir);
	}
	if(flip){
		assert(~res & 1);
		res >>= 1;
	}
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