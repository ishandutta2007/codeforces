#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), cnt(100);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		++ cnt[a[i]];
	}
	int x = max_element(cnt.begin(), cnt.end()) - cnt.begin(), res = 0;
	const int minf = numeric_limits<int>::min() / 2, inf = numeric_limits<int>::max() / 2;
	for(auto y = 0; y < 100; ++ y){
		if(x != y){
			vector<int> pref(n + 1), minpos(2 * n + 1, inf), maxpos(2 * n + 1, minf);
			minpos[n] = maxpos[n] = 0;
			for(auto i = 0; i < n; ++ i){
				pref[i + 1] = pref[i];
				if(a[i] == x){
					++ pref[i + 1];
				}
				else if(a[i] == y){
					-- pref[i + 1];
				}
				ctmin(minpos[pref[i + 1] + n], i + 1);
				ctmax(maxpos[pref[i + 1] + n], i + 1);
			}
			for(auto t = 0; t <= 2 * n; ++ t){
				if(minpos[t] <= maxpos[t]){
					res = max(res, maxpos[t] - minpos[t]);
				}
			}
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