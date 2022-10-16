#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 2010;
int n, k, use[N], m;
string s[N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

bool ok(int ind) {
	for(int j = 0 ; j < m; j++) {
		if(use[j] == 1 && s[ind][j] == '1')
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			if(s[i][j] == '1')
				use[j]++;
		}
	}
	// dbg_v(use, m);
	for(int i = 1; i <= n; i++) {
		if(ok(i)) {
			// dbg(i);
			cout << "YES\n";
			return 0;
		}
	}

			cout << "NO\n";
			return 0;
}