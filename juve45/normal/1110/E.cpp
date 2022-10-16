#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T> ostream& print(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return print(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return print(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 100100;
int n, k, m, a[N], b[N];
vector <int> v, g;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i < n ;i++) v.push_back(a[i + 1] - a[i]);
	for(int i = 1; i < n ;i++) g.push_back(b[i + 1] - b[i]);

	sort(v.begin(), v.end());
	sort(g.begin(), g.end());

	if(a[1] != b[1] || b[n] != a[n]) return cout << "No\n", 0;

	for(int i = 0; i < v.size(); i++)
		if(v[i] != g[i])
			return cout << "No\n", 0;
	cout << "Yes\n";			
	return 0;
}