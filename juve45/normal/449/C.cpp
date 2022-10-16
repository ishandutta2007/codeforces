#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 100100;
int n, use[N];

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;

	vector <pair<int, int> > sol;
	vector <int> even;

	for(int i = 3; 2 * i <= n; i++) {
		if(use[i]) continue;
		vector <int> v;

		for(int j = i; j <= n; j += i)
			if(use[j] == 0)
				v.push_back(j), use[j] = 1;

		// dbg(v);
		if(v.size() % 2) {
			swap(v[1], v[v.size() - 1]);
			even.push_back(v.back());
			v.pop_back();
		}

		for(int i = 0; i + 1 < v.size(); i += 2)
			sol.push_back({v[i], v[i + 1]});
	}

	for(int i = 2; i <= n; i += 2)
		if(!use[i])
			even.push_back(i);

	// dbg(sol);
	// dbg(even);

	for(int i = 0; i + 1 < even.size(); i += 2)
		sol.push_back({even[i], even[i + 1]});
	cout << sol << '\n';
}