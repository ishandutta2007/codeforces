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

// const long long N = ;
long long n, a, b;
long long ans, kans;
vector <long long> v;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> a >> b;
	if(a < b) swap(a, b);

	long long d = a - b;

	for(long long i = 1; i * i <= d; i++)
		if(d % i == 0) {
			v.push_back(i);
			if(i * i != d) v.push_back(d / i);
		}
	ans = a * b / __gcd(a, b);
	kans = 0;


	for(auto i : v) {
		long long k = i - a % i;
		long long lcm = (a + k) * (b + k) / __gcd(a + k, b + k);
		if(lcm < ans) ans = lcm, kans = k;
	}
	cout << kans << '\n';

}