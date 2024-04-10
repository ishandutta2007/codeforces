#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, u;
	cin >> n >> u;
	vector<int> e(n);
	for(auto i = 0; i < n; ++ i){
		cin >> e[i];
	}
	bool any = false;
	double res = 0;
	for(auto i = 0, j = 0; i < n; ++ i){
		while(j < n && e[j] - e[i] <= u){
			++ j;
		}
		if(j - i >= 3){
			any = true;
			ctmax(res, 1.0 * (e[j - 1] - e[i + 1]) / (e[j - 1] - e[i]));
		}
	}
	if(any){
		cout << fixed << setprecision(15);
		cout << res << "\n";
	}
	else{
		cout << "-1\n";
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