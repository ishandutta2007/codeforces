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
int n, a[N], x[N], p[N], ip[N];

bool cmp(int c, int b) {
	return x[c] < x[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;


	for(int i = 1; i <= n; i++)
		cin >> x[i], p[i] = i;

	sort(p + 1,  p + n + 1, cmp);
		
	if(n <= 3) {
		cout << p[2] << '\n';
		return 0;
	}

	for(int i = 1; i <= n; i++)
		ip[p[i]] = i, a[i] = x[p[i]];

	set <int> difs;
	for(int i = 3; i <= n; i++)
		difs.insert(a[i] - a[i - 1]);

	if(difs.size() == 1)
		return cout << p[1] << "\n", 0;

	difs.clear();
	for(int i = 2; i < n; i++)
		difs.insert(a[i] - a[i - 1]);

	if(difs.size() == 1)
		return cout << p[n] << "\n", 0;

	dbg_ok;

	difs.clear();
	for(int i = 2; i <= n; i++)
		difs.insert(a[i] - a[i - 1]);

	if(difs.size() > 3) return cout << "-1\n", 0;

	// dbg(difs);

	int bad = 0;
	int dif = *prev(difs.end());
	for(int i = 2; i <= n; i++) {
		if(a[i] - a[i - 1] < dif) {
			bad = p[i];
			for(int j = i; j < n; j++)
				a[j] = a[j + 1];
			break;
		}
	}

	// dbg(bad);
	difs.clear();
	for(int i = 2; i < n; i++)
		difs.insert(a[i] - a[i - 1]);
	if(difs.size() == 1)
		cout << bad << '\n';
	else cout << "-1\n";
}