#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, L, R;
		cin >> n >> L >> R;
		vector<int> cnt(n);
		for(auto i = 0; i < L; ++ i){
			int x;
			cin >> x, -- x;
			++ cnt[x];
		}
		for(auto i = 0; i < R; ++ i){
			int x;
			cin >> x, -- x;
			-- cnt[x];
		}
		vector<int> left, right;
		for(auto x = 0; x < n; ++ x){
			if(cnt[x]){
				if(cnt[x] > 0){
					left.push_back(cnt[x]);
				}
				else{
					right.push_back(-cnt[x]);
				}
			}
		}
		if(L < R){
			swap(L, R);
			swap(left, right);
		}
		int i = 0, res = 0;
		for(auto &x: right){
			while(x){
				while(i < (int)left.size() && ~left[i] & 1){
					++ i;
				}
				if(i == (int)left.size()){
					goto DONE;
				}
				-- x;
				-- left[i];
				++ res;
			}
		}
		DONE:;
		i = 0;
		for(auto &x: right){
			while(x){
				while(i < (int)left.size() && !left[i]){
					++ i;
				}
				assert(i < (int)left.size());
				-- x;
				-- left[i];
				++ res;
			}
		}
		for(auto x: left){
			res += x + 1 >> 1;
		}
		cout << res << "\n";
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