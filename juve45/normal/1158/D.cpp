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

const long long N = 2019;
long long n, use[N];
string s;

struct point {
	long long x, y;
} p[2345];

long long area(point a, point b, point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	long long start = 1;
	for(long long i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		if(p[i].x < p[start].x || (p[i].x == p[start].x && p[i].y < p[start].y))
			start = i; 
	}
	cin >> s;
	use[start] = 1;
	vector <long long> v;
	v.push_back(start);

	for(long long i = 2; i <= n; i++) {
		
		long long cand = -1, sgn = 1;
		if(s[i - 2] == 'R') sgn *= -1;

		for(long long j = 1; j <= n; j++) {
			if(use[j]) continue;

			if(cand == -1 || area(p[v.back()], p[cand], p[j]) * sgn < 0)
				cand = j;
		}
		use[cand] = 1;
		v.push_back(cand);
	}

	for(long long j = 1; j <= n; j++)
		if(!use[j])
			v.push_back(j);

	for(auto i : v) cout << i << ' ';
}