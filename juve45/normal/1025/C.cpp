#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

int n, k, ans;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	s += s;
	for(int i = 0; i < s.size(); i++) {
		int cans = 1;
		while(i + 1 < s.size() && s[i] != s[i + 1]) {
			i++;
			cans++;
		}
		ans = max(ans, cans);
	}
	ans = min(ans, n);
	cout << ans << '\n';
}