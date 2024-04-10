#include <bits/stdc++.h>
#define st first
#define nd second
 
using namespace std;
 
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, multiset <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
 
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
 
const long long N = 500100;
long long n, a[N], b, m, k, q, s, use[N];
map <long long, long long> mp, tmp;
vector <long long> res;
 
bool ok(vector <long long> v, long long k) {
	dbg(v);
	tmp.clear();
	for(long long i = 0; i < v.size(); i++) {
		if(i % k == k - 1) {
			bool ok = 1;
			for(auto i : mp)
				if(tmp[i.st] < i.nd) 
					ok = 0;
			if(ok) return 1;
			tmp.clear();
		} else tmp[a[i]]++;
	}
	return 0;
}
 
void sol(long long l, long long r) {
 
	long long f = min((l - 1) / k, n - 1);
	n -= f;
	long long b = min((m - r + 1) / k, n - 1);
	// dbg(f, b);
	n += f;
	// assert(f + b + 1 == n);
	f *= k;
	b *= k;
 
	for(long long i = 1; i < l && f; i++, f--)
		use[i] = 1;
 
	for(long long i = r; i <= m && b; i++, b--)
		use[i] = 1;
 
	// dbg(f, b);
	// assert(!f && !b);
 
	int kk = k;
	for(long long i = l; i < r; i++) {
		if(mp[a[i]] > 0 || r - i <= k)
			use[i] = 1, k--, mp[a[i]]--;
	}
 
	for(int i = 1; i <= m; i++)
		if(use[i] == 0 && k)
			use[i] = 1, k--;
	// dbg(k, kk);
	// assert(k == 0);
 
	vector <long long> ans, check;
	for(long long i = 1; i <= m; i++)
		if(!use[i])
			ans.push_back(i);
		else 
			check.push_back(a[i]);
	
	// if(!ok(check, kk))
	// 	assert(false);
 
	cout << ans << '\n';
}
 
bool can(int i, int j) {
 
	int szl = (i - 1) / k;
	int szr = (m - j + 1) / k;
	int extral = i - 1 - szl * k;
	int extrar = (m - j + 1) - szr * k;
	if(szl + szr >= n - 1 && j - i + extral + extrar >= k)
		return 1;
	return 0;
}
 
int main() {
	ios_base::sync_with_stdio(false);
 
 
	cin >> m >> k >> n >> s;
	for(long long i = 1; i <= m; i++)
		cin >> a[i];
 
	for(long long i = 1; i <= s; i++)
		cin >> b, mp[b]++;
 
	long long sz = mp.size();
	long long nr_fit = 0;
	long long j = 1;
 
	for(long long i = 1; i <= m; i++) {
 
		assert(sz == mp.size());
		assert(nr_fit <= sz);
 
		if(i > 1 && mp.count(a[i - 1])) {
			tmp[a[i - 1]]--;
			if(tmp[a[i - 1]] == mp[a[i - 1]] - 1)
				nr_fit--;
		}
		while(nr_fit != mp.size() && j <= m) {
			if(mp.count(a[j])) {
				tmp[a[j]]++;
				if(tmp[a[j]] == mp[a[j]])
					nr_fit++;
			}
			
			j++;
		}
		// dbg(i, j, nr_fit);
 
		if(nr_fit < mp.size()) break;
		else if(can(i, j)) {
			sol(i, j);
			return 0;
		}
	}
 
	cout << "-1\n";
	return 0;
}