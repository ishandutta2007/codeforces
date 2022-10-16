#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#ifndef LOCAL
#define cerr if(0)cout
#endif

#define st first
#define nd second

using namespace std;

int n, k;
string s, ans;

bool cons(char c) {
	if(c == 'o')
		return false;
	if(c == 'a')
		return false;
	if(c == 'i')
		return false;
	if(c == 'u')
		return false;
	if(c == 'e')
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	ans += s[0];
	int nrc = cons(s[0]);

	for(int i = 1; i < s.size(); i++) {
		if(cons(s[i])) {
			nrc++;
			if(nrc >= 3 && (ans.back() != s[i] || s[i] != s[i - nrc + 1])) {
				cout << ans << ' ';
				ans.clear();
				nrc = 1;
			}
		}
		else nrc = 0;
		ans += s[i];
	}

	cout << ans << '\n';
}