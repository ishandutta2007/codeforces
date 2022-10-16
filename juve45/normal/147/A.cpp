#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, x, m;

string s;

bool is_punct(char c) {
	if(c == '.') return 1;
	if(c == '!') return 1;
	if(c == '?') return 1;
	if(c == ',') return 1;
	return 0;
}

string ans;
int main() {
	getline(cin, s);
	for(auto c : s) {
		// dbg(ans);
		if(!is_punct(c) && c != ' ')
			ans.push_back(c);
		else if(c == ' ') {
			if(ans.back() != ' ')
				ans.push_back(c);
		}
		else {
			if(ans.back() == ' ')
				ans[ans.size() - 1] = c;
			else ans.push_back(c);
			ans += ' ';
			dbg(ans);
		}
	}
	cout << ans << '\n';
}