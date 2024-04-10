#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	auto query = [&](vector<int> w){
		cout << (int)w.size() << "\n";
		for(auto j: w){
			cout << j + 1 << " ";
		}
		cout << endl;
		vector<int> res(n);
		for(auto i = 0; i < n; ++ i){
			cin >> res[i];
		}
		return res;
	};
	int mx = __lg(n - 1) + 1;
	vector<array<vector<int>, 2>> q(mx);
	for(auto bit = 0; bit < mx; ++ bit){
		for(auto state = 0; state < 2; ++ state){
			vector<int> w;
			for(auto j = 0; j < n; ++ j){
				if((j >> bit & 1) == state){
					w.push_back(j);
				}
			}
			assert(!w.empty());
			q[bit][state] = query(w);
		}
	}
	cout << "-1\n";
	for(auto i = 0; i < n; ++ i){
		int res = numeric_limits<int>::max();
		for(auto bit = 0; bit < mx; ++ bit){
			ctmin(res, q[bit][!(i >> bit & 1)][i]);
		}
		cout << res << " ";
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