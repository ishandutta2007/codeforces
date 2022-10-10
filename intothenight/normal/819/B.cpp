#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class T>
struct arithmetic_sequence_updater{
	int n;
	vector<T> data;
	arithmetic_sequence_updater(int n): n(n), data(n + 2){}
	void update(int l, int r, T start, T step){
		assert(0 <= l && l <= r && r <= n);
		data[l] += start;
		data[l + 1] -= start - step;
		data[r] -= start + (r - l) * step;
		data[r + 1] += start + (r - l - 1) * step;
	}
	// must only be called once
	vector<T> solve() const{
		vector<T> res(data.begin(), data.end() - 2);
		for(auto i = 1; i < n; ++ i) res[i] += res[i - 1];
		for(auto i = 1; i < n; ++ i) res[i] += res[i - 1];
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	arithmetic_sequence_updater<long long> updater(n);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x, -- x;
		if(x < i){
			updater.update(0, n - i, i - x, 1);
			updater.update(n - i, n - i + x, x, -1);
			updater.update(n - i + x, n, 0, 1);
		}
		else{
			updater.update(0, x - i, x - i, -1);
			updater.update(x - i, n - i, 0, 1);
			updater.update(n - i, n, x, -1);
		}
	}
	auto state = updater.solve();
	pair<long long, int> res{numeric_limits<long long>::max(), -1};
	for(auto i = 0; i < n; ++ i){
		ctmin(res, pair{state[i], i});
	}
	cout << res.first << " " << res.second << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////