#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, deque <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, mx = 0, mn = 1e9, a[3 * N], ans[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}

	if(mx <= 2 * mn) {
		for(int i = 1; i <= n; i++) cout << "-1 ";
		return 0;
	}

	for(int i = 1; i <= 2 * n; i++) a[i + n] = a[i];

	deque <int> dq;
	
	int j = 1;
	for(int i = 1; i <= n; i++) {

		if(i > 1 && dq.front() < i) dq.pop_front();

		// while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();


		while(dq.empty() || 2 * a[j] >= a[dq.front()]) {
			while(!dq.empty() && a[dq.back()] <= a[j]) dq.pop_back();			
			// dbg(i, a[j]);
			dq.push_back(j);
			j++;
		}
		// dbg(i, j);
		// dbg(dq);
		ans[i] = j - i;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}