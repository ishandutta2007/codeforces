#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int k;
	cin >> k;
	if(k == 1){
		cout << "2\nNY\nYN\n";
		return 0;
	}
	int len = __lg(k), n = 2;
	auto new_node = [&]()->int{
		return n ++;
	};
	vector<array<int, 2>> edge;
	auto link = [&](int u, int v)->void{
		edge.push_back({u, v});
	};
	vector<int> path{0};
	for(auto rep = len - 1; rep; -- rep){
		path.push_back(new_node());
	}
	path.push_back(1);
	for(auto i = 0; i < len; ++ i){
		int u = new_node(), v = new_node();
		link(path[i], u);
		link(path[i], v);
		link(u, path[i + 1]);
		link(v, path[i + 1]);
	}
	for(auto bit = 0; bit < len; ++ bit){
		if(k & 1 << bit){
			int l = path[bit], r = path.back();
			vector<int> cpath{l};
			for(auto rep = len - bit - 1; rep; -- rep){
				cpath.push_back(new_node());
			}
			cpath.push_back(r);
			for(auto i = 0; i < (int)cpath.size() - 1; ++ i){
				int u = new_node();
				link(cpath[i], u);
				link(u, cpath[i + 1]);
			}
		}
	}
	vector<string> res(n, string(n, 'N'));
	for(auto [u, v]: edge){
		res[u][v] = res[v][u] = 'Y';
	}
	cout << n << "\n";
	ranges::copy(res, ostream_iterator<string>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////