#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		int n = (int)s.size();
		#ifdef LOCAL
		const int mx = 26;
		#else
		const int mx = 26;
		#endif
		array<int, mx> cnt{};
		for(auto c: s){
			++ cnt[c - 'a'];
		}
		sort(s.begin(), s.end());
		if(count(cnt.begin(), cnt.end(), 0) == mx - 1){
			cout << s << "\n";
			return 0;
		}
		if(any_of(cnt.begin(), cnt.end(), [&](int x){ return x == 1; })){
			if(cnt[s[0] - 'a'] != 1){
				swap(s[0], *find_if(s.begin(), s.end(), [&](char c){ return cnt[c - 'a'] == 1; }));
			}
			sort(s.begin() + 1, s.end());
			cout << s << "\n";
			return 0;
		}
		// more than one character appaers, all occurences >= 2
		if(2 * cnt[s[0] - 'a'] - 2 <= n){ // start with aa
			string t = s;
			reverse(t.begin(), t.end());
			while(t.back() == s.front()){
				t.pop_back();
			}
			string res{s[0], s[0]};
			for(auto rep = cnt[s[0] - 'a'] - 2; rep; -- rep){
				res.push_back(t.back());
				res.push_back(s[0]);
				t.pop_back();
			}
			reverse(t.begin(), t.end());
			res += t;
			cout << res << "\n";
			return 0;
		}
		// now forced to start with a(not a)
		if(count(cnt.begin(), cnt.end(), 0) <= mx - 3){
			int i = find_if(s.begin(), s.end(), [&](char c){ return c != s[0]; }) - s.begin();
			int j = find_if(s.begin(), s.end(), [&](char c){ return c != s[0] && c != s[i]; }) - s.begin();
			swap(s[1], s[i]);
			swap(s[i + 1], s[j]);
			cout << s << "\n";
			return 0;
		}
		// only two characters
		char a = s[0];
		char b = *find_if(s.begin(), s.end(), [&](char c){ return c != a; });
		cout << a << string(cnt[b - 'a'], b) << string(cnt[a - 'a'] - 1, a) << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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