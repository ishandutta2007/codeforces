#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int m;
	cin >> m;
	const int th = 1e5;
	long long len = 0;
	vector<int> a;
	vector<tuple<long long, int, int>> update;
	for(auto i = 0; i < m; ++ i){
		int type;
		cin >> type;
		if(type == 1){
			int x;
			cin >> x;
			if(len < th){
				a.push_back(x);
			}
			else{
				update.push_back({len, x, -1});
			}
			++ len;
		}
		else{
			int l, c;
			cin >> l >> c;
			while(len < th && c){
				-- c;
				for(auto i = 0; i < l; ++ i){
					a.push_back(a[i]);
				}
				len = (int)a.size();
			}
			if(c){
				update.push_back({len, l, c});
			}
			len += 1LL * l * c;
		}
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		long long i;
		cin >> i, -- i;
		if(i < (int)a.size()){
			cout << a[i] << " ";
		}
		else{
			auto it = prev(ranges::upper_bound(update, tuple{i + 1, 0, 0}));
			if(~get<2>(*it)){
				cout << a[(i - get<0>(*it)) % get<1>(*it)] << " ";
			}
			else{
				cout << a[get<1>(*it)] << " ";
			}
		}
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