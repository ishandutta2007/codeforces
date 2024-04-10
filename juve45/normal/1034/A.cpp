#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 300100;
const int MAX = 1.5e7 + 100;
int n, k, a[N], g[N], s[MAX], f[MAX];
vector <int> p;

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
	
	for(int i = 2; i <= MAX; i++)
		if(s[i] == 0) {
			p.push_back(i);
			for(int j = 2 * i ; j <= MAX; j += i)
				s[j] = 1;
		}

	cin >> n;
	int gcd = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		gcd = __gcd(a[i], gcd);
	}

	for(int i = 1; i <= n; i++)
		a[i] /= gcd;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < p.size() && p[j] * p[j] <= a[i]; j++)
			if(a[i] % p[j] == 0) {
				f[p[j]]++;
				while(a[i] % p[j] == 0)
					a[i] /= p[j];
			}

		if(a[i] > 1)
			f[a[i]]++;
	}

	int ans = 0;
	for(int i = 1; i < MAX; i++)
		ans = max(ans, f[i]); 

	// dbg_v(f, 30);
	if(ans == 0) ans = n + 1;
	cout << n - ans << '\n';
}