#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, scnt, ecnt, v, qn;
	cin >> n >> m >> scnt >> ecnt >> v;
	vector<int> s(scnt), e(ecnt);
	for(auto i = 0; i < scnt; ++ i){
		cin >> s[i];
	}
	for(auto i = 0; i < ecnt; ++ i){
		cin >> e[i];
	}
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2){
			cout << abs(y1 - y2) << "\n";
		}
		else{
			if(y1 > y2){
				swap(x1, x2), swap(y1, y2);
			}
			auto it = lower_bound(s.begin(), s.end(), y1);
			int res = numeric_limits<int>::max();
			if(it != s.end()){
				ctmin(res, abs(x1 - x2) + abs(*it - y1) + abs(y2 - *it));
			}
			if(it != s.begin()){
				ctmin(res, abs(x1 - x2) + abs(*prev(it) - y1) + abs(y2 - *prev(it)));
			}
			it = lower_bound(e.begin(), e.end(), y1);
			if(it != e.end()){
				ctmin(res, (abs(x1 - x2) + v - 1) / v + abs(*it - y1) + abs(y2 - *it));
			}
			if(it != e.begin()){
				ctmin(res, (abs(x1 - x2) + v - 1) / v + abs(*prev(it) - y1) + abs(y2 - *prev(it)));
			}
			cout << res << "\n";
		}
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