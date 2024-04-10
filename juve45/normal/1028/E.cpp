#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// #ifndef LOCAL
// #define cerr if(0)cout
// #endif

#define st first
#define nd second

using namespace std;

const long long N = 200100;
long long n, k, a[N], b[N];

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
	for(long long i = 0; i < n; i++) {
		cin >> b[i];
	}

	long long pos = -1;
	for(long long i = 0; i < n; i++) 
		if(b[i] < b[(i + 1) % n]) {
			a[(i + 1) % n] = b[(i + 1) % n];
			pos = (i + 1) % n;
			break;
		}
	if(pos == -1) {
		if(b[0] == 0) {
			cout << "YES\n";
			for(int i= 0; i < n; i++)
				cout << 1 << ' ';
			cout << '\n';
			return 0;
		}
		return cout << "NO\n", 0;
	}
	dbg(pos);
	long long pos1 = pos - 1;
	if(pos1 == -1) pos1 += n;
	a[pos1] = 187126 * a[pos] + b[pos1];
	pos = pos1;

	for(long long i = 2; i < n; i++) {
		long long pos1 = pos - 1;
		if(pos1 == -1) pos1 += n;
		a[pos1] = a[pos] + b[pos1];
		pos = pos1;
	}
	cout << "YES\n";
	for(long long i =0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}