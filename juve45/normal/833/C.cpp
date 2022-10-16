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

const long long K = 19;
long long DBG;
long long n, dp[22][11], l, r, ANS;
long long f[11], p[22], ff[22];
vector <long long> vl, vr;

void put(long long limit, vector <long long> &v) {
	while(limit) {
		v.push_back(limit % 10);
		limit /= 10;
	}
	while(v.size() < K) v.push_back(0);
	reverse(v.begin(), v.end());
}
	

bool ok(long long pos, long long ll, long long rr) {
	if(pos == K) return 1;

	if(ll && rr) {
		for(long long i = vl[pos] + 1;i < vr[pos]; i++)
			if(f[i]) return 1;
		if(vl[pos] == vr[pos]) {
			if(f[vl[pos]]) {
				f[vl[pos]]--;
				if(ok(pos + 1, 1, 1))
					return 1;
				f[vl[pos]]++;	
			}
			return 0;
		}
		else  {
			if(f[vl[pos]]) {
				f[vl[pos]]--;
				if(ok(pos + 1, 1, 0))
					return 1;
				f[vl[pos]]++;
			}
			if(f[vr[pos]]) {
				f[vr[pos]]--;
				if(ok(pos + 1, 0, 1))
					return 1;
				f[vr[pos]]++;
			}

		}
	} else if(ll) {
		for(long long i = vl[pos] + 1;i < 10; i++)
			if(f[i]) return 1;
		if(f[vl[pos]]) {
			f[vl[pos]]--;
			if(ok(pos + 1, 1, 0))
				return 1;
			f[vl[pos]]++;
		}
	} else if(rr) {
		for(long long i = 0;i < vr[pos]; i++)
			if(f[i]) return 1;

		if(f[vr[pos]]) {
			f[vr[pos]]--;
			if(ok(pos + 1, 0, 1))
				return 1;
			f[vr[pos]]++;
		}
	}
	return 0;
}

void bkt(long long pos, long long last) {
	if(pos == K) {
		if(last == 0) return;
		for(long long i = 0; i <= 9; i++)
			f[i] = ff[i];

	if(f[0] && f[1] && f[6] && f[5])
		DBG = 1;
	else DBG = 0;
		if(ok(0, 1,1)) {
			ANS++;
		}
		return;
	}
	for(long long i = last; i < 10; i++) {
		ff[i]++;
		bkt(pos + 1, i);
		ff[i]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
		
	cin >> l >> r;
	put(l, vl);
	put(r, vr);
	// dbg(vl);
	// dbg(vr);
	p[0] = 1;
	for(long long i = 1; i <= K; i++)
		p[i] = p[i - 1] * i;

	bkt(0, 0);

	// for(long long i = 1; i <= 9; i++)
	// 	dp[1][i] = 1;

	// for(long long i = 2;i <= K; i++) {
	// 	for(long long j = 9; j; j--) {
	// 		for(long long k = j; k; k--)
	// 			dp[i][j] += dp[i - 1][k];
	// 	}

	// 	dbg_v(dp[i], 10);
	// }
	cout << ANS << '\n';
}