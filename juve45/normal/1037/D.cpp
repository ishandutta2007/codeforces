#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

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

const int N = 200100;
int n, k, m, a, b, c[N];

set<int>v[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].insert(b);
		v[b].insert(a);
	}
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	int j = 2;
	if(c[1] != 1) return cout << "No\n", 0;
	 
	for(int i = 1; i <= n; i++) {
		if(j <= i) return cout << "No\n", 0;
		
		while(j <= n && v[c[i]].count(c[j]) > 0) {
			v[c[i]].erase(c[j]);
			v[c[j]].erase(c[i]);
			j++;
		}

		if(v[c[i]].size() != 0)
			return cout << "No\n", 0;
	}
	if(j > n) cout << "Yes\n";
	else cout << "No\n";
}