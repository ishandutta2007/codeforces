#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	vector<vector<int>> next(n, vector<int>(26, n));
	next[n - 1][s[n - 1] - 'a'] = n - 1;
	for(auto i = n - 2; i >= 0; -- i){
		for(auto c = 0; c < 26; ++ c){
			next[i][c] = s[i] - 'a' == c ? i : next[i + 1][c];
		}
	}
	vector<vector<int>> prev(n, vector<int>(26, -1));
	prev[0][s[0] - 'a'] = 0;
	for(auto i = 1; i < n; ++ i){
		for(auto c = 0; c < 26; ++ c){
			prev[i][c] = s[i] - 'a' == c ? i : prev[i - 1][c];
		}
	}
	vector<int> lpos(m + 1), rpos(m + 1);
	for(auto len = 1, i = 0, j = n - 1; len <= m; ++ len){
		i = next[i][t[len - 1] - 'a'];
		lpos[len] = i;
		++ i;
		j = prev[j][t[m - 1 - (len - 1)] - 'a'];
		rpos[len] = j;
		-- j;
	}
	int res = numeric_limits<int>::min();
	for(auto len = 1; len < m; ++ len){
		ctmax(res, rpos[m - len] - lpos[len]);
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