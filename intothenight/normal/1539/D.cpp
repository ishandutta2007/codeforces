#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<long long, 2>> a(n);
	long long tot_req = 0;
	long long max_disc = 0;
	for(auto &[disc, req]: a){
		cin >> req >> disc;
		tot_req += req;
	}
	for(auto &[disc, req]: a){
		ctmin(disc, tot_req);
	}
	a.push_back({tot_req, 0});
	sort(a.begin(), a.end());
	long long res = tot_req << 1;
	long long prev_disc = 0;
	long long rem = 0;
	for(auto [disc, req]: a){
		long long delta = min(rem, disc - prev_disc);
		res -= delta;
		rem -= delta;
		rem += req;
		prev_disc = disc;
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