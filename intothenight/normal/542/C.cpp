#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
	}
	int tail = 0;
	long long cycle = 1;
	for(auto i = 0; i < n; ++ i){
		vector<int> cur, pos(n, -1);
		for(auto j = i; !~pos[j]; j = a[j]){
			pos[j] = (int)cur.size();
			cur.push_back(j);
		}
		ctmax(tail, pos[a[cur.back()]]);
		cycle = lcm<long long>(cycle, pos[cur.back()] - pos[a[cur.back()]] + 1);
	}
	cout << (cycle >= 2 ? max((tail + cycle - 1) / cycle, 1LL) * cycle : max(tail, 1)) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////