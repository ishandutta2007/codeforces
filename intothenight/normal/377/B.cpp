#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, passes;
	cin >> n >> m >> passes;
	vector<int> bug(m), skill(n), req(n);
	for(auto i = 0; i < m; ++ i){
		cin >> bug[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> skill[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> req[i];
	}
	vector<int> bug_order(m), student_order(n);
	iota(bug_order.begin(), bug_order.end(), 0);
	ranges::sort(bug_order, [&](int i, int j){ return bug[i] < bug[j]; });
	iota(student_order.begin(), student_order.end(), 0);
	ranges::sort(student_order, [&](int i, int j){ return skill[i] < skill[j]; });
	vector<int> res(m);
	auto fail = [&](int th)->bool{
		auto cmp = [&](int i, int j)->bool{
			return i != j ? req[i] > req[j] : i < j;
		};
		priority_queue<int, vector<int>, decltype(cmp)> active(cmp);
		int rem = passes;
		for(auto t1 = m - 1, t2 = n - 1; t1 >= 0; ){
			while(t2 >= 0 && skill[student_order[t2]] >= bug[bug_order[t1]]){
				active.push(student_order[t2]);
				-- t2;
			}
			if(active.empty()){
				return true;
			}
			int i = active.top();
			if(rem < req[i]){
				return true;
			}
			rem -= req[i];
			active.pop();
			for(auto k = 0; k < th && t1 >= 0; ++ k, -- t1){
				res[bug_order[t1]] = i;
			}
		}
		return false;
	};
	int th = *ranges::partition_point(ranges::iota_view(1, m + 1), fail);
	if(th == m + 1){
		cout << "NO\n";
		return 0;
	}
	assert(!fail(th));
	cout << "YES\n";
	for(auto i: res){
		cout << i + 1 << " ";
	}
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