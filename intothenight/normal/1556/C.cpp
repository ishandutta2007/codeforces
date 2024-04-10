#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 1; i < n; i += 2){
		a[i] = -a[i];
	}
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + a[i];
	}
	long long res = 0;
	for(auto i = 0; i < n; i += 2){
		long long req = 0;
		for(auto j = i + 1; j < n; j += 2){
			long long balance = pref[j] - pref[i + 1];
			if(i + 1 < j){
				ctmax(req, pref[i + 1] - pref[j - 1]);
			}
			int l = a[i], r = -a[j];
			if(l < req){
				continue;
			}
			l -= req;
			balance += req;
			if(balance >= 0){
				if(r < balance){
					continue;
				}
				r -= balance;
			}
			else{
				if(l < -balance){
					continue;
				}
				l += balance;
			}
			res += min(l, r) + (j - i != 1);
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