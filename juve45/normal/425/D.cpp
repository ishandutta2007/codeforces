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

const long long N = 100100;
const long long BKT = 300;
const long long MUL = 100000000LL;
long long n, x, y, ans;
unordered_set <long long> s;
vector <long long> v[N], big, small;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		s.insert(x * MUL + y);
	}

	for(long long i = 0; i < N; i++) {

		sort(v[i].begin(), v[i].end());
		
		if(v[i].size() > BKT)
			big.push_back(i);
		else if(v[i].size() > 0)
			small.push_back(i);
	}

	for(auto l : small) {
		// dbg(v[l]);
		for(long long i = 0; i < v[l].size(); i++)
			for(long long j = i + 1; j < v[l].size(); j++) {
				long long sz = v[l][j] - v[l][i];
				if(s.count((l + sz) * MUL + v[l][i]) && s.count((l + sz) * MUL + v[l][j]))
					ans++;
				if(l-sz > 0 && v[l - sz].size() > BKT)
					if(s.count((l - sz) * MUL + v[l][i]) && s.count((l - sz) * MUL + v[l][j]))
						ans++;
			}
	}

	for(long long i = 0; i < big.size(); i++)
		for(long long j = i + 1; j < big.size(); j++) {
			long long sz = big[j] - big[i];
			for(auto k : v[big[i]])
				if(s.count(big[j] * MUL + k) && s.count(big[j] * MUL + k + sz) && s.count(big[i] * MUL + k + sz))
					ans++;
		}

	cout << ans << '\n';
}