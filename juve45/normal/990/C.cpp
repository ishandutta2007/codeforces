#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 300100;
int n, k, f[N], f2[N];
long long ans;
string s[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

int getsum(string &s) {
	int ans = 0;
	for(auto i : s) {
		if(i == '(')
			ans++;
		else ans--;
	}
	return ans;
}

int getmn(string &s) {
	int ans = 0, mn = 10000000;
	for(auto i : s) {
		if(i == '(')
			ans++;
		else ans--;
		mn = min(ans, mn);
	}
	return mn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		int ss = getsum(s[i]);
		// dbg(ss);
		if(ss > 0) {
			if(getmn(s[i]) >= 0)
				f[ss]++;
		} else if(ss < 0) {

			if(getmn(s[i]) >= ss)
				f2[-ss]++;
		} else if(getmn(s[i]) >= 0) ans++;
	}
	ans *= ans;
	// dbg(ans);
	
	for(int i = 1; i <= N; i++)
		ans += 1LL * f[i] * f2[i];
	
	cout << ans << '\n';
}