#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<long long> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long sum = accumulate(a.begin(), a.end(), 0LL);
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		long long def, att;
		cin >> def >> att;
		int i = lower_bound(a.begin(), a.end(), def) - a.begin();
		long long res = numeric_limits<long long>::max();
		if(i != n){ // current player attack
			ctmin(res, max(0LL, att - (sum - a[i])));
		}
		if(i){ // prev player attack
			ctmin(res, max(0LL, att - (sum - a[i - 1])) + def - a[i - 1]);
		}
		cout << res << "\n";
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