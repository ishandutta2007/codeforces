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

const int N = 1010;
long long n, k, m, X, Y;

pair<int, int> a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].st >> a[i].nd;
	
	for(int i = 1; i <= n; i++)
		cin >> b[i].st >> b[i].nd;
 
	for(int i = 1; i <= n; i++) {
		X += a[i].st;
		Y += a[i].nd;

		X += b[i].st;
		Y += b[i].nd;
	}

	X /= n;
	Y /= n;

	cout << X << ' ' << Y << '\n';
}