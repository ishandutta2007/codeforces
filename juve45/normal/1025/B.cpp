#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 150100;
long long n, k, a[N], b[N];

vector <long long> v;

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
	for(long long i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}

	for(long long i = 2; i * i <= a[1]; i++)
		if(a[1] % i == 0) {
			v.push_back(i);
			while(a[1] % i == 0)
				a[1] /= i;
		}
		if(a[1] > 1)
		v.push_back(a[1]);

	for(long long i = 2; i * i <= b[1]; i++)
		if(b[1] % i == 0) {
			v.push_back(i);
			while(b[1] % i == 0)
				b[1] /= i;
		}
	if(b[1] > 1)
	v.push_back(b[1]);
	// sort(v.begin(), v.end());


	for(auto i : v) {
		long long ok = 1;
		for(long long j = 2; j <= n; j++)
			if(a[j] % i != 0 && b[j] % i != 0)
				ok = 0;

		if(ok)
			return cout << i << '\n', 0;
	}
	cout << "-1\n";
}