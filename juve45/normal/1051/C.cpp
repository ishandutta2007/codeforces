#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 110;
int n, k, a[N];

vector<int>v, f[110], v2;

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
	cin >> n;
	for(int i = 1; i <= n;i++) {
		cin >> a[i];
		f[a[i]].push_back(i);
	}

	for(int i = 1; i <= 100; i++) {
		if(f[i].size() == 1)
			v.push_back(f[i][0]);
		else if(f[i].size() > 2)
			v2.push_back(i);
	}

	string ans = string(n, 'A');

	if(v.size() % 2 == 1) {
		if(v2.size() == 0)
			return cout << "NO\n", 0;
		ans[f[*v2.begin()][0] - 1] = 'B';
	}

	for(int i = 0; i < v.size() / 2; i++)
		ans[v[i] - 1] = 'B';

	cout << "YES\n";
	cout << ans << '\n';
}