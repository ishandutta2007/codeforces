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

const long long N = 9;
long long n, a[N][5], b[N][5];

long long dist(long long * a, long long * b) {
	long long x[] = {0, 0, 0};
	for(long long i = 0; i < 3; i++) {
		x[i] = (a[i] - b[i]);
		x[i] *= x[i];
	}
	return x[0] + x[1] + x[2];
}

map <long long, long long> m;

bool valid() {
	// dbg(m);
	if(m.begin()->nd == 12 && next(m.begin())->nd == 12 && next(next(m.begin()))->nd == 4)
		return 1;
	return 0;
}

void bkt(long long pos) {
	// dbg(pos);
	if(pos > 8) {
		if(valid()) {
			cout << "YES\n";
			for(long long i = 1; i <= 8; i++) 
				cout << b[i][0] << ' ' << b[i][1] << ' ' << b[i][2] << '\n'; 
			exit(0);
		} 
	} else {
		long long p[] = {0, 1, 2};
		do {
			b[pos][0] = a[pos][p[0]];
			b[pos][1] = a[pos][p[1]];
			b[pos][2] = a[pos][p[2]];
			for(long long j = 1; j < pos; j++) m[dist(b[j], b[pos])]++;
			if(m.empty() || m.size() <= 3 && m.begin()->st > 0) 
				bkt(pos + 1);
			// dbg(pos, m);
			for(long long j = 1; j < pos; j++) {
				long long g = dist(b[j], b[pos]);
				m[g]--;
				if(m[g] == 0) m.erase(g);
			}
			// dbg(m);
		} while(next_permutation(p, p + 3));
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	for(long long i = 1; i <= 8 ; i++) 
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	bkt(1);
	cout << "NO\n";
	return 0;
}