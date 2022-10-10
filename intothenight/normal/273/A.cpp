#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	int qn;
	cin >> qn;
	vector<pair<int, long long>> s; // (w, h) w decreasing, h increasing
	for(auto qi = 0; qi < qn; ++ qi){
		int w, h;
		cin >> w >> h;
		long long x = max<long long>(a[w - 1], s.empty() ? 0 : s.back().second);
		cout << x << "\n";
		while(!s.empty() && s.back().first <= w){
			s.pop_back();
		}
		s.push_back({w, h + x});
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