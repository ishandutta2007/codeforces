#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, d, m;
	cin >> n >> d >> m;
	vector<int> small, large;
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		if(x <= m){
			small.push_back(x);
		}
		else{
			large.push_back(x);
		}
	}
	sort(small.rbegin(), small.rend()), sort(large.rbegin(), large.rend());
	vector<long long> prefs(int(small.size()) + 1), prefl(int(large.size()) + 1);
	for(auto i = 0; i < int(small.size()); ++ i){
		prefs[i + 1] = prefs[i] + small[i];
	}
	for(auto i = 0; i < int(large.size()); ++ i){
		prefl[i + 1] = prefl[i] + large[i];
	}
	long long res = 0;
	for(auto i = 0; i <= int(large.size()) && (!i || (i - 1) * (d + 1) + 1 <= n); ++ i){ // number of large picked
		if(!i || int(large.size()) >= (i - 1) * (d + 1) + 1){
			ctmax(res, prefl[i] + prefs.back());
		}
		else{
			ctmax(res, prefl[i] + prefs[int(small.size()) - (1 + (i - 1) * (d + 1) - int(large.size()))]);
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