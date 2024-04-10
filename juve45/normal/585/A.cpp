#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 4010;
long long n, k, v[N], d[N], p[N];
vector <long long> ans;

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
	for(long long i = 1; i <= n; i++)
		cin >> v[i] >> d[i] >> p[i];
	
	for(long long i = 1; i <= n; i++) {
		if(p[i] < 0) continue;
		
		ans.push_back(i);
		for(long long j = i + 1, s = v[i], s2 = 0; j <= n; j++) {
			if(p[j] < 0) 
				continue;

			p[j] -= s, s--;
			s = max(s, 0LL);

			p[j] -= s2;
			if(p[j] < 0)
				s2 += d[j];
		}
	}
	cout << ans << '\n';
}