#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> h(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> h[i], -- h[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<pair<int, long long>> s{{0, b[0]}};
	multiset<long long, greater<>> ms{b[0]};
	for(auto i = 1; i < n; ++ i){
		long long next = *ms.begin() + b[i];
		while(!s.empty() && h[s.back().first] > h[i]){
			ctmax(next, s.back().second - b[s.back().first] + b[i]);
			ms.erase(ms.find(s.back().second));
			s.pop_back();
		}
		s.push_back({i, next});
		ms.insert(next);
	}
	cout << *ms.begin() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////