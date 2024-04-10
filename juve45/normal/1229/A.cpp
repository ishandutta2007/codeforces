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

const long long N = 7005;
long long n, a[N], b[N], ans, gr[N], use[N];
// vector <long long> v[N];

bool edge(long long x, long long y) {
	if(x != y && (a[x] | a[y]) > a[y])
		return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	for(long long i = 1; i <= n; i++) cin >> b[i], ans += b[i];



	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= n; j++) {
			if(i != j && (a[i] | a[j]) > a[j]) {
				// dbg(i, j);
				gr[i]++;
			}
		}

	long long nrc = n - 1;
	long long ok = 1;
	while(ok) {
		ok = 0;
		for(long long i = 1; i <= n; i++) {
			if(!use[i] && gr[i] == nrc) {
				// dbg(i);
				use[i] = 1;
				for(int j = 1; j <= n; j++)
					if(edge(j, i))
						gr[j]--;
				ok = 1;
				ans -= b[i];
				nrc--;
				break;
			}
		}
	}

	// queue <long long> q;
	// for(long long i = 1; i <= n; i++)
	// 	if(gr[i] == 0)
	// 		q.push(i);


	// while(!q.empty()) {
	// 	long long x = q.front(); q.pop();
	// 	ans -= b[x];

	// 	for(auto i : v[x]) {
	// 		gr[i]--;
	// 		if(gr[i] == 0) q.push(i);
	// 	}
	// }
	cout << ans << '\n';
}