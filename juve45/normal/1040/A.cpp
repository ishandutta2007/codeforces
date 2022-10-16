#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 22;
int n, k, w[N], a, b, m, c[5], ans;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
		cin >> w[i];

	c[0] = a;
	c[1] = b;
	int cmin = 0;
	if(a > b) cmin = 1;

	for(int i = 1; i <= n; i++) {
		if(w[i] == w[n - i + 1] && w[i] == 2) {
			ans += min(a, b);
			if(i != n - i + 1)
				ans += min(a, b);
			w[i] = w[n - i + 1] = cmin;
		} else if(w[i] == 2) {
			ans += c[w[n - i + 1]];
			w[i] = w[n - i + 1];
		}
	}

	for(int i = 1; i <= n; i++)
		if(w[i] != w[n-i+1])
			return cout << "-1\n", 0;
	cout << ans << '\n';
}