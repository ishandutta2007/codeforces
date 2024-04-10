#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n * k);
	for(auto i = 0; i < n * k; ++ i){
		cin >> a[i], -- a[i];
	}
	int th = (n + k - 2) / (k - 1);
	vector<array<int, 2>> res(n, {-1, -1});
	vector<int> last(n, -1), cnt(n * k);
	for(auto i = 0; i < n * k; ++ i){
		if(!~res[a[i]][0]){
			if(~last[a[i]]){
				for(auto j = last[a[i]]; j <= i; ++ j){
					if(cnt[j] == th){
						last[a[i]] = i;
						goto FAIL;
					}
					++ cnt[j];
				}
				res[a[i]] = {last[a[i]], i};
				FAIL:;
			}
			else{
				last[a[i]] = i;
			}
		}
	}
	for(auto [i, j]: res){
		assert(~i && ~j);
		cout << i + 1 << " " << j + 1 << "\n";
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