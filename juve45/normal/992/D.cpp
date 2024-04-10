#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
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

const long long N = 200100;
long long n, kk, m, s[N], a[N], ans;

vector <long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> kk;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];	
		if(a[i] > 1)
			v.push_back(i);
		else if(kk == 1) ans++;
	}

	// dbg(v);

	v.push_back(n + 1);

	for(long long i = 1; i <= n; i++) {
		// calculez cate incep pe poz i
		long long j = lower_bound(v.begin(), v.end(), i) - v.begin();
		// j e primul nenul;
		long long prod = a[v[j]];
		
		// dbg(j);
		// dbg(v[j]);

		for(long long k = 0; k <= 60 && j + k + 1 < v.size(); k++) {
			// calculez cate sunt long longre i/j - 1 si j - din astea cu 1
			// ...
			// dbg(prod);
			if(prod == kk * (s[v[j + k]] - s[i -1]))
				ans++;
			else {
				long long nr1 = v[j + k + 1] - v[j + k] - 1;
				if(prod % kk == 0) {
					long long req = prod / kk - (s[v[j + k]] - s[i -1]);
					if(req > 0 && req <= nr1)
						ans++;
				}
			}

			if(j + k + 2 >= v.size()) break;

			if(prod < 1e18 / a[v[j + k + 1]])
				prod *= a[v[j + k + 1]];
		}
		// dbg(i);
		// dbg(ans);
	}
	cout << ans << '\n';
}