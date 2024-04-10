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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
const int B = 30;
int n, a[N], l[N], r[N], rr[N], ll[N], last[B + 14];
long long ans; 

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	a[0] = 1e9 + 100;
	a[n + 1] = 1e9 + 100;

	stack<int> s;
	s.push(0);
	for(int i = 1; i <= n; i++) {
		while(a[s.top()] < a[i]) s.pop();
		l[i] = s.top();
		s.push(i);
		ll[i] = 0;
		for(int j = 0; j < B; j++)
			if((a[i] & (1 << j)) == 0)
				ll[i] = max(ll[i], last[j]);
			else last[j] = i;
	}

	for(int i = 0; i < B; i++)
		last[i] = n + 1;

	while(s.size()) s.pop();
	s.push(n + 1);
	for(int i = n; i; i--) {
		while(a[s.top()] <= a[i]) s.pop();
		r[i] = s.top();
		s.push(i);

		rr[i] = n + 1;
		for(int j = 0; j < B; j++)
			if((a[i] & (1 << j)) == 0)
				rr[i] = min(rr[i], last[j]);
			else last[j] = i;
	}

	// dbg_v(l, n + 1);
	// dbg_v(r, n + 1

	for(int i = 1; i <= n; i++) {

		if(l[i] < ll[i])
			ans += 1LL* (ll[i] - l[i]) * (r[i] - i); 
		if(r[i] > rr[i])
			ans += 1LL* (r[i] - rr[i]) * (i - l[i]);
		if(r[i] > rr[i] && l[i] < ll[i])
			ans -= 1LL * (r[i] - rr[i]) * (ll[i] - l[i]);
	}
	cout << ans << '\n';
}