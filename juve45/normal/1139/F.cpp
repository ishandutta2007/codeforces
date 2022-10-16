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

long long n, m;
const long long N = 100100;
const long long MAX = 4e9 + 1000;
const long long OFF = 1e9;

unordered_map <long long, long long> l, r;
long long p[N], s[N], x[N], y[N], b[N], ans[N];
vector <pair<pair<long long, long long>, long long> > events;

long long lsb(long long k){ 
	return k & (-k);
}

void upd(unordered_map<long long, long long> &aib, long long pos, long long val) {
	// dbg(pos, val);
	for(; pos < MAX; pos += lsb(pos))
		aib[pos] += val;
}

long long que(unordered_map<long long, long long> &aib, long long pos) {
	long long ret = 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

long long query(long long x, long long y) {
	// dbg(x + y, OFF + y - x);
	return que(l, x + y) + que(r, OFF + y - x);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
		cin >> p[i];
	for(long long i = 1; i <= n; i++)
		cin >> s[i];
	for(long long i = 1; i <= n; i++)
		cin >> b[i];


	for(long long i = 1; i <= m; i++)
		cin >> x[i];
	for(long long i = 1; i <= m; i++)
		cin >> y[i];

	// {{x, op}, y}

	for(long long i = 1; i <= n; i++) {
		events.push_back({{p[i], 1}, b[i]});
		events.push_back({{s[i], 3}, b[i] + p[i]});
		events.push_back({{s[i], 4}, b[i] - p[i]});
	}

	for(long long i = 1; i <= m; i++) {
		events.push_back({{x[i], 2}, i});
	}

	sort(events.begin(), events.end());

	for(auto i : events) {
		// dbg(i);
		if(i.st.nd == 2) 
			ans[i.nd] = query(x[i.nd], y[i.nd]);
		else if(i.st.nd == 1) {
			upd(l, i.st.st + i.nd, 1);
			upd(r, OFF - i.st.st + i.nd + 1, -1);
		} else if(i.st.nd == 3) {
			upd(l, i.nd, -1);
		} else if(i.st.nd == 4) {
			upd(r, OFF + i.nd + 1, 1);
		}
	}
	for(long long i = 1; i <= m; i++)
		cout << ans[i] << '\n';
}