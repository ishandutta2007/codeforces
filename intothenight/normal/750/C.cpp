#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	int delta = 0, low = numeric_limits<int>::min(), high = numeric_limits<int>::max();
	for(auto i = 0; i < n; ++ i){
		int ch, d;
		cin >> ch >> d;
		if(d == 1){
			ctmax(low, 1900 - delta);
		}
		else{
			ctmin(high, 1899 - delta);
		}
		delta += ch;
	}
	if(low > high){
		cout << "Impossible\n";
	}
	else if(high == numeric_limits<int>::max()){
		cout << "Infinity\n";
	}
	else{
		cout << high + delta << "\n";
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