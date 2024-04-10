#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 2010;
long long n, h, a[N];

bool ok(long long mid) {
	vector <long long> v;
	long long hh = 0;

	for(long long i = 1; i <= mid; i++)
		v.push_back(a[i]);
	sort(v.begin(), v.end(), greater<long long>());


	for(long long i = 0; i < v.size(); i+= 2)
		hh += v[i];
	
	return (hh <= h);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> h;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	long long l = 0, r = n;

	while(l != r) {
		long long mid = (l + r + 1) / 2; 
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}

	cout << l << '\n';
}