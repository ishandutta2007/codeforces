#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		copy_n(istream_iterator<int>(cin), n, b.begin());
		if(a[0] != b[0]){
			cout << "NO\n";
			return 0;
		}
		vector<array<int, 2>> res;
		auto act = [&](int l, int r)->void{
			if(r - l <= 3){
				return;
			}
			res.push_back({l, r});
			ranges::reverse(a | ranges::views::take(r) | ranges::views::drop(l));
		};
		for(auto i = 1; i < n; ++ i){
			if(a[i] == b[i]){
				continue;
			}
			int j = i;
			while(j < n && (min(a[j - 1], a[j]) != min(b[i - 1], b[i]) || max(a[j - 1], a[j]) != max(b[i - 1], b[i]))){
				++ j;
			}
			if(j == n){
				cout << "NO\n";
				return 0;
			}
			if(a[j - 1] == b[i]){
				assert(a[j] == b[i - 1]);
				act(i - 1, j + 1);
			}
			else{
				assert(a[j - 1] == b[i - 1] && a[j] == b[i]);
				for(auto l = i - 1; l < j; ++ l){
					for(auto r = j; r < n; ++ r){
						if(a[l] == a[r]){
							act(l, r + 1);
							act(i - 1, l + (r - j) + 2);
							goto NEXT;
						}
					}
				}
				cout << "NO\n";
				return 0;
				NEXT:;
			}
		}
		assert(a == b);
		cout << "YES\n" << (int)res.size() << "\n";
		for(auto [l, r]: res){
			cout << l + 1 << " " << r << "\n";
		}
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