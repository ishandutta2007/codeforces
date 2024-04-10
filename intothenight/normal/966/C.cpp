#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<long long> a(n);
	const int mx = 60;
	array<vector<int>, mx> pos;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		for(auto bit = 0; bit < mx; ++ bit){
			if(a[i] & 1LL << bit){
				pos[bit].push_back(i);
			}
		}
	}
	vector<int> used(n), cur;
	for(auto bit = mx - 1; bit >= 0; -- bit){
		if(!pos[bit].empty()){
			array<int, 2> cnt{};
			for(auto i: pos[bit]){
				++ cnt[used[i]];
			}
			if(cnt[0] > cnt[1] + 1){
				cout << "No\n";
				return 0;
			}
			reverse(cur.begin(), cur.end());
			vector<int> ncur;
			while(!pos[bit].empty()){
				int i = pos[bit].back(); pos[bit].pop_back();
				if(!used[i]){
					if(!ncur.empty()){
						while(~a[cur.back()] & 1LL << bit){
							ncur.push_back(cur.back()), cur.pop_back();
						}
						ncur.push_back(cur.back()), cur.pop_back();
					}
					ncur.push_back(i);
					used[i] = true;
				}
			}
			while(!cur.empty()){
				ncur.push_back(cur.back()), cur.pop_back();
			}
			swap(cur, ncur);
		}
	}
	cout << "Yes\n";
	for(auto i: cur){
		cout << a[i] << " ";
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