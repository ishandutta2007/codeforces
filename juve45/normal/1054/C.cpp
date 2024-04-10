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

const int N = 1005;
int n, l[N], r[N], aib[N], ans[N];
vector <int> v[2* N];

int lsb(int k) {return k & (-k); }

void upd(int pos) {
	for(; pos < N; pos += lsb(pos))
		aib[pos]++;
}

int que(int pos) {
	int ret = 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	
	for(int i = 1; i <= n; i++)
		cin >> l[i];
	for(int i = 1; i <= n; i++) 
		cin >> r[i];

	for(int i = 1; i <= n; i++) {
		if(l[i] + r[i] >= n) return cout << "NO\n", 0;
		v[l[i] + r[i]].push_back(i);
	}

	int ant = 0, val = n;
	for(int i = 0; i < n; i++) {
		// dbg(i, ant, v[i]);

		if(v[i].empty()) continue;
		if(ant != i) return cout << "NO\n", 0;
		ant += v[i].size();

		for(auto j : v[i]) 
			if(que(j) != l[j] || que(n) - que(j) != r[j])
				return cout << "NO\n", 0;

		for(auto j : v[i]) {
			ans[j] = val;
			upd(j);
		}

		val--;
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) 
		cout << ans[i] << ' ';
}