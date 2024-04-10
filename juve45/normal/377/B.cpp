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

const int N = 100100;
int n, m, a[N], b[N], c[N], s, sol[N];
vector <pair<int, int> > p, v;


int ok(int t) {
	// dbg(t);
	long long cost = 0;
	priority_queue <pair<int, int> > pq;

	int j = 0;
	// dbg(p);
	// dbg(v);

	for(int i = 0; i < m; i += t) {
		// dbg(i);
		while(j < p.size() && v[i].st <= p[j].st) {
			pq.push({-c[p[j].nd], p[j].nd});
			j++;
		}
		// dbg(i, j);
	
		if(pq.empty()) return 0;
		// dbg(pq.top().nd);
		cost -= pq.top().st;
		for(int k = 0; k < t && i + k < v.size(); k++)
			sol[v[i + k].nd] = pq.top().nd;
		pq.pop();
		// dbg(i, t, m, (t + m - 1) / t);
	}
	return (cost <= 1LL * s);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++) cin >> a[i], v.push_back({a[i], i});
	sort(v.begin(), v.end(), greater<pair<int, int> > ());
	
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++) p.push_back({b[i], i});

	sort(p.begin(), p.end(), greater<pair<int, int> > ());

	int l = 0, r = n + 1;
	while(l != r) {
		int mid = (l + r) / 2;	
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	dbg(l);
	if(ok(l))  {
		cout << "YES\n";
		for(int i = 1; i <= m; i++)
			cout << sol[i] << ' ';
	} else 
		cout << "NO\n";

}