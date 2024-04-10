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
	for(auto e : v) out << e << '\n';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << p.st << ' ' << p.nd;  
}

const int N = 5100;
int n, k, m, a, b;
vector <pair<int, int> >  v[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		v[i].push_back({i, i + n * (i - 1)});
	}

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back({a, b + n * (a - 1)});
		v[b].push_back({b, b + n * (a - 1)});	
	}

	for(int i = 1; i <= n; i++)
		cout << v[i];
}