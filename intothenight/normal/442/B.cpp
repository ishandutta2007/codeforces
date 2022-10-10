#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<long double> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	auto calc = [&](const auto &a)->long double{
		vector<long double> suff((int)a.size() + 1, 1);
		for(auto i = (int)a.size() - 1; i >= 0; -- i){
			suff[i] = suff[i + 1] * (1 - a[i]);
		}
		long double pref = 1, res = 0;
		for(auto i = 0; i < (int)a.size(); ++ i){
			res += pref * a[i] * suff[i + 1];
			pref *= 1 - a[i];
		}
		return res;
	};
	long double res = 0;
	for(auto l = 0; l < n; ++ l){
		for(auto r = l + 1; r <= n; ++ r){
			auto cur = vector<long double>{a.begin(), a.begin() + l};
			cur.insert(cur.end(), a.begin() + r, a.end());
			ctmax(res, max(calc(cur), calc(vector<long double>(a.begin() + l, a.begin() + r))));
		}
	}
	cout << fixed << setprecision(15);
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