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
int n, m, a, b, use[3 * N];

vector <pair<int, int> > v[3 * N];
vector <int> match;

void solve() {
	cin >> n >> m;

	match.clear();
	for(int i = 1; i <= 3 * n; i++) {
		v[i].clear();
		use[i] = 1;
	}

	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[a].push_back({b, i});
		v[b].push_back({a, i});
	}

	for(int i = 1; i <= 3 * n; i++) {

		if(use[i] == 0) continue; //it is matched already

		int ok = 0;
		for(auto j : v[i])
			if(use[j.st]) { //if it is not matched
				ok = 1;
				match.push_back(j.nd);
				use[j.st] = 0;
				use[i] = 0;
				break;
			}
		// if(ok == 0)
		// 	use[i] = 0;
	}

	// dbg(match);
	// dbg_v(use, 3 * n + 1);

	if(match.size() >= n) {
		cout << "Matching\n";
		for(int i = 0; i < n; i++)
			cout << match[i] << ' ';
	} else {
		cout << "IndSet\n";
		for(int i = 1, j = 0; i <= 3 * n && j < n; i++)
			if(use[i]) {
				cout << i << ' ';
				j++;
			}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int t; cin >> t;
	while(t --)solve();

}