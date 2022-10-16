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
long long n, f[270];
string p;

long long cnt_front(const string &s) {
	long long nr = 0;
	while(nr < s.size() && s[nr] == s[0])
		nr++;
	return nr;
}
long long cnt_back(const string &s) {
	long long nr = 1;
	while(nr < s.size() && s[s.size() - nr] == s.back()) 
		nr++;
	return nr - 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> p;

	p += "&";
	long long nr = 0;
	for(long long i = 0; i < p.size(); i++) {
		if(i == 0 || p[i] == p[i - 1]) nr++;
		else {
			f[p[i - 1]] = max(f[p[i - 1]], nr);
			nr = 1;
		}
	}

	long long ans = 1;

	for(long long i = 2; i <= n; i++) {
		
		cin >> p;
		
		if(p == string(p.size(), p[0])) {
			f[p[0]] = (f[p[0]] + 1) * p.size() + f[p[0]];
		} else if(p[0] == p.back()) {
			// dbg_ok;
			long long nr1 = cnt_front(p);
			long long nr2 = cnt_back(p);
			// dbg(nr1, nr2);
			if(f[p[0]]) f[p[0]] = nr1 + nr2 + 1;
			else f[p[0]] = max(nr1, nr2);
		} else {
			long long nr1 = cnt_front(p);
			long long nr2 = cnt_back(p);
			// dbg(nr1, nr2);
			// dbg(p[0], f[p[0]]);
			if(f[p[0]]) f[p[0]] = nr1 + 1;
			else f[p[0]] = nr1;

			// dbg(p[0], f[p[0]]);

			if(f[p.back()]) f[p.back()] = nr2 + 1;
			else f[p.back()] = nr2;
		}


		for(long long c= 'a'; c <= 'z'; c++)
			if(c != p[0] && c != p.back())
				f[c] = (f[c] ? 1 : 0);

		p += "&";
		nr = 0;
		for(long long i = 0; i < p.size(); i++) {
			if(i == 0 || p[i] == p[i - 1]) nr++;
			else {
				f[p[i - 1]] = max(f[p[i - 1]], nr);
				nr = 1;
			}
		}
		
		// for(char c = 'a'; c <= 'z'; c++)
		// 	cout << f[c] << ' ';
		// cout << '\n';
	}


	for(char c = 'a'; c <= 'z'; c++)
		ans = max(ans, f[c]);

	cout << ans << '\n';
}