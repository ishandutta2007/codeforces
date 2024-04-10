#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	if(k == 0){
		cout << n << "\n";
		ranges::copy(ranges::iota_view(1, n + 1), ostream_iterator<int>(cout, " "));
		cout << "\n";
		return 0;
	}
	const int width = __lg(k) + 1;
	vector<int> a(n);
	map<int, vector<int>> mp;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		mp[a[i] >> width].push_back(i);
		a[i] &= (1 << width) - 1;
	}
	vector<int> res;
	for(auto [ignore, g]: mp){
		auto cmp = [&](int i, int j)->bool{
			return a[i] < a[j];
		};
		ranges::sort(g, cmp);
		int pivot = ranges::partition_point(g, [&](int i){ return ~a[i] & 1 << width - 1; }) - g.begin();
		for(auto t = pivot; t < (int)g.size(); ++ t){
			int i = g[t], l = 0, r = pivot, mx_xor = 1 << width - 1;
			for(auto bit = width - 2; bit >= 0; -- bit){
				int m = ranges::partition_point(g | ranges::views::take(r) | ranges::views::drop(l), [&](int i){ return ~a[i] & 1 << bit; }) - g.begin();
				if(a[i] & 1 << bit){
					if(l < m){
						r = m;
						mx_xor |= 1 << bit;
					}
				}
				else{
					if(m < r){
						l = m;
						mx_xor |= 1 << bit;
					}
				}
			}
			if(l < r && mx_xor >= k){
				res.insert(res.end(), {g[l], i});
				goto NEXT_FLAG;
			}
		}
		res.push_back(g[0]);
		NEXT_FLAG:;
	}
	if((int)res.size() < 2){
		cout << "-1\n";
		return 0;
	}
	cout << (int)res.size() << "\n";
	ranges::copy(res | ranges::views::transform([&](int x){ return x + 1; }), ostream_iterator<int>(cout, " "));
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////