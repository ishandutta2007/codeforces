#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(auto i = 0; i < n; ++ i){
		string s;
		cin >> s;
		a[i][0] = s[1] - '1';
		if(s[0] == 'R'){
			a[i][1] = 0;
		}
		else if(s[0] == 'G'){
			a[i][1] = 1;
		}
		else if(s[0] == 'B'){
			a[i][1] = 2;
		}
		else if(s[0] == 'Y'){
			a[i][1] = 3;
		}
		else{
			a[i][1] = 4;
		}
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	int res = numeric_limits<int>::max();
	for(auto cmask = 0; cmask < 1 << 5; ++ cmask){
		for(auto xmask = 0; xmask < 1 << 5; ++ xmask){
			int cnt = 0;
			vector cflag(5, vector<bool>(5)), xflag(5, vector<bool>(5));
			for(auto [x, y]: a){
				int type = (xmask >> x & 1) + 2 * (cmask >> y & 1);
				if(type == 0){
					++ cnt;
				}
				else if(type == 1){
					cflag[x][y] = true;
				}
				else if(type == 2){
					xflag[y][x] = true;
				}
			}
			if(cnt <= 1 &&
				all_of(cflag.begin(), cflag.end(), [&](auto &a){ return accumulate(a.begin(), a.end(), 0) <= 1; }) &&
				all_of(xflag.begin(), xflag.end(), [&](auto &a){ return accumulate(a.begin(), a.end(), 0) <= 1; })){
				ctmin(res, __builtin_popcount(cmask) + __builtin_popcount(xmask));
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