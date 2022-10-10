#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<string> res(n, string(n, '?'));
	vector<array<int, 2>> a(n * n);
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			int x;
			cin >> x, -- x;
			a[x] = {i, j};
		}
	}
	int suml = numeric_limits<int>::min();
	int sumr = numeric_limits<int>::max();
	int difl = numeric_limits<int>::min();
	int difr = numeric_limits<int>::max();
	for(auto x = n * n - 1; x >= 0; -- x){
		auto [i, j] = a[x];
		if(i + j < suml || sumr < i + j || i - j < difl || difr < i - j){
			res[i][j] = 'G';
		}
		else{
			res[i][j] = 'M';
			ctmax(suml, i + j - k);
			ctmin(sumr, i + j + k);
			ctmax(difl, i - j - k);
			ctmin(difr, i - j + k);
		}
	}
	ranges::copy(res, ostream_iterator<string>(cout, "\n"));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////