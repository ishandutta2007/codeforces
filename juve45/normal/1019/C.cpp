#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 1000100;
int n, k, m, a, b, use[N];

vector <int> v[N], a1, ans;

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
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	for(int i = 1; i <= n; i++)
		if(!use[i]) {
			a1.push_back(i);
			for(auto j : v[i])
				use[j] = 1;
		}
	
	memset(use, 0, sizeof use);
	for(int i = a1.size() - 1; i >= 0; i--)
		if(!use[a1[i]]) {
			ans.push_back(a1[i]);
			for(auto j : v[a1[i]])
				use[j] = 1;
		}
	cout << ans << '\n';
}