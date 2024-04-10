#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, th;
	cin >> n >> m;
	vector<int> p(n + 1), q(m + 1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		p[i + 1] = p[i] + x;
	}
	for(auto i = 0; i < m; ++ i){
		int x;
		cin >> x;
		q[i + 1] = q[i] + x;
	}
	cin >> th;
	vector<int> mx(n + 1, numeric_limits<int>::max()), my(m + 1, numeric_limits<int>::max());
	for(auto i = 0; i < n; ++ i){
		for(auto j = i + 1; j <= n; ++ j){
			ctmin(mx[j - i], p[j] - p[i]);
		}
	}
	for(auto i = 0; i < m; ++ i){
		for(auto j = i + 1; j <= m; ++ j){
			ctmin(my[j - i], q[j] - q[i]);
		}
	}
	int res = 0;
	for(auto i = 1; i <= n; ++ i){
		for(auto j = 1; j <= m; ++ j){
			if(1LL * mx[i] * my[j] <= th){
				ctmax(res, i * j);
			}
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