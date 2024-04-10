#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 3300;
long long n, k, p, c, m, t;
vector <long long> v[N];

long long ans = 1e18;

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
	for(long long i = 1; i <= n; i++) {
		cin >> p >> c;
		v[p].push_back(c);
	}

	for(long long i = 2; i <= m; i++)
		sort(v[i].begin(), v[i].end(), greater<long long>());


	for(long long i = 0; i <= n; i++) {
		long long cans = 0;
		long long nr = 0;
		multiset<long long> s;

		for(long long j = 2; j <= m; j++) {
			if((long long)v[j].size() > i) {
				for(long long k = i; k < v[j].size(); k++)
					cans += v[j][k], nr++;

				for(long long k = 0; k < i; k++)
					s.insert(v[j][k]);	
			}
			else
				for(auto k : v[j])
					s.insert(k);
		}

		long long cur = (long long)v[1].size();
		cur += nr;
		long long req = max(0LL, i + 1 - cur);

		if(((long long)s.size()) >= req) {
			while(req > 0) {
				cans += *s.begin();
				s.erase(s.begin());
				req--;
			}
			ans = min(ans, cans);
		}
		
	}
	cout << ans << '\n';
}