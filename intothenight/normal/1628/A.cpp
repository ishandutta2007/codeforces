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
		vector<int> a(n), cnt(n + 1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			++ cnt[a[i]];
		}
		int mex = 0;
		while(cnt[mex]){
			++ mex;
		}
		int l = 0;
		vector<int> b;
		vector<int> local_cnt(n + 1);
		while(l < n){
			int r = l;
			int local_mex = 0;
			while(l == r || local_mex < mex){
				++ local_cnt[a[r]];
				while(local_cnt[local_mex]){
					++ local_mex;
				}
				++ r;
			}
			b.push_back(mex);
			for(auto i = l; i < r; ++ i){
				-- cnt[a[i]];
				-- local_cnt[a[i]];
				if(cnt[a[i]] == 0 && a[i] < mex){
					mex = a[i];
				}
			}
			l = r;
		}
		cout << (int)b.size() << "\n";
		ranges::copy(b, ostream_iterator<int>(cout, " "));
		cout << "\n";
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