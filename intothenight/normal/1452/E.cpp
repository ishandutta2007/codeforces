#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 2>> range(m);
	for(auto i = 0; i < m; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> range[i][j];
		}
		-- range[i][0];
		range[i][0] += k, range[i][1] += k;
	}
	n += 2 * k;
	vector<vector<int>> overlap(m, vector<int>(n - k + 1));
	vector<array<int, 2>> inc(m), dec(m);
	for(auto i = 0; i < m; ++ i){
		for(auto left = 0; left <= n - k; ++ left){
			int right = left + k;
			if(range[i][0] < right && left < range[i][1]){
				overlap[i][left] = min(range[i][1], right) - max(range[i][0], left);
			}
		}
		vector<int> d(n - k);
		for(auto j = 0; j < n - k; ++ j){
			d[j] = overlap[i][j + 1] - overlap[i][j];
		}
		int l = 0;
		while(l < n - k && !d[l]){
			++ l;
		}
		int r = l;
		while(r < n - k && d[r] == 1){
			++ r;
		}
		inc[i] = {l, r};
		l = r;
		while(l < n - k && !d[l]){
			++ l;
		}
		r = l;
		while(r < n - k && d[r] == -1){
			++ r;
		}
		dec[i] = {l, r};
	}
	int res = 0;
	for(auto left = 0; left <= n - k; ++ left){ // first author: [left, left + k)
		int init = 0;
		vector<int> d(n - k + 1);
		for(auto i = 0; i < m; ++ i){
			int shrink;
			if(left <= inc[i][0]){
				shrink = 0;
			}
			else if(left <= inc[i][1]){
				shrink = left - inc[i][0];
			}
			else if(left <= dec[i][0]){
				shrink = inc[i][1] - inc[i][0];
			}
			else if(left <= dec[i][1]){
				shrink = dec[i][1] - left;
			}
			else{
				shrink = 0;
			}
			init += overlap[i][left];
			++ d[inc[i][0] + shrink];
			-- d[inc[i][1]];
			-- d[dec[i][0]];
			++ d[dec[i][1] - shrink];
		}
		for(auto i = 0; i < n - k; ++ i){
			init += d[i];
			ctmax(res, init);
			d[i + 1] += d[i];
		}
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