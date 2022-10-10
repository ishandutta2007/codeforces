#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	string s;
	cin >> n >> qn >> s;
	vector<array<int, 3>> cnt1(n + 1), cnt2(n + 1);
	for(auto i = 0; i < n; ++ i){
		int x = (s[i] - 'a' + i) % 3, y = (s[i] - 'a' - i % 3 + 3) % 3;
		cnt1[i + 1] = cnt1[i], cnt2[i + 1] = cnt2[i];
		++ cnt1[i + 1][x], ++ cnt2[i + 1][y];
	}
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l;
		int res = numeric_limits<int>::max();
		for(auto rep = 2; rep; -- rep){
			for(auto c = 0; c < 3; ++ c){
				ctmin(res, r - l - (cnt1[r][c] - cnt1[l][c]));
			}
			swap(cnt1, cnt2);
		}
		cout << res << "\n";
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