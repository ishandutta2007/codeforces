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

const long long N = 1000100;
long long n, sc[N], sl[N], a, m, k, p, ans;
priority_queue <long long> pq;
vector <long long> lin, col;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k >> p;
	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= m; j++) {
			cin >> a;
			sl[i] += a;
			sc[j] += a;
		}

	for(long long i = 1; i <= n; i++)
		pq.push(sl[i]);
	
	while(lin.size() < k) {
		long long x = pq.top(); pq.pop();
		lin.push_back(x);
		pq.push(x - p * m);
	}

	while(!pq.empty()) pq.pop();

	for(long long i = 1; i <= m; i++)
		pq.push(sc[i]);
	
	while(col.size() < k) {
		long long x = pq.top(); pq.pop();
		col.push_back(x);
		pq.push(x - p * n);
	}

	sort(lin.begin(), lin.end(), greater<long long>());
	sort(col.begin(), col.end(), greater<long long>());

	// dbg(lin);
	// dbg(col);
	sl[0] = lin[0];
	sc[0] = col[0];

	for(long long i = 1; i < k; i++) {
		sl[i] = sl[i - 1] + lin[i];
		sc[i] = sc[i - 1] + col[i];
	}
	ans = max(sl[k - 1], sc[k - 1]);
	// dbg(ans);
	for(long long nrl = 1; nrl < k; nrl++) {
		long long nrc = k - nrl;
		int must = min(nrl, nrc);
		long long tmp = -p * nrl * nrc;
		// long long tmp = -p * must * min(n, m);
		// dbg(nrl, tmp);
		tmp += sl[nrl - 1] + sc[nrc - 1];
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
}