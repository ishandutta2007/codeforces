#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, num, denom;
	string s;
	cin >> n >> num >> denom >> s;
	array<int, 26> cnt{}, l, r;
	l.fill(numeric_limits<int>::max()), r.fill(numeric_limits<int>::min());
	for(auto i = 0; i < n; ++ i){
		++ cnt[s[i] - 'a'];
		ctmin(l[s[i] - 'a'], i), ctmax(r[s[i] - 'a'], i + 1);
	}
	vector<array<int, 4>> a;
	for(auto c = 0; c < 26; ++ c){
		if(cnt[c]){
			a.push_back({l[c], r[c], cnt[c], c});
		}
	}
	sort(a.begin(), a.end());
	n = (int)a.size();
	bitset<1 << 20> dp;
	dp[0] = true;
	for(auto mask = 1; mask < 1 << n; ++ mask){
		int sum = 0, left = numeric_limits<int>::max(), right = numeric_limits<int>::min();
		for(auto i = 0; i < n; ++ i){
			if(mask & 1 << i){
				sum += a[i][2];
				ctmin(left, a[i][0]), ctmax(right, a[i][1]);
			}
		}
		if(1LL * sum * denom >= 1LL * num * (right - left)){
			for(auto i = 0; i < n; ++ i){
				if(mask & 1 << i && dp[mask ^ 1 << i]){
					dp[mask] = true;
					break;
				}
			}
		}
		int lmask = 0, rmask = mask;
		for(auto i = 0; i < n; ++ i){
			if(mask & 1 << i){
				lmask ^= 1 << i, rmask ^= 1 << i;
				if(dp[lmask] && dp[rmask]){
					dp[mask] = true;
					break;
				}
			}
		}
	}
	string res;
	for(auto i = 0; i < n; ++ i){
		if(dp[(1 << n) - 1 ^ 1 << i]){
			res.push_back(a[i][3] + 'a');
		}
	}
	sort(res.begin(), res.end());
	cout << (int)res.size() << " ";
	for(auto c: res){
		cout << c << " ";
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