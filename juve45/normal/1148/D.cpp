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

const int N = 300100;
int n, ant1[N], ant2[N], last1, last2, ans1, ans2, a[N], b[N];

void solve(int & ans, int * ant, int & last) {
	set <pair <int, pair<int, int> > > v;

	v.insert({0, {0, 0}});
	for(int i = 1; i <= n; i++) {
		if(a[i] < b[i]) continue;
		dbg(v);
		auto res = v.upper_bound({a[i], {-1, -1}});
		res--;
		int lg = res->nd.st + 1;
		dbg(lg);
		ant[i] = res->nd.nd;

		pair <int, pair<int, int>> add(b[i], {lg, i});
		if(ans < lg) {
			ans = lg;
			last = i;
		}

		v.insert(add);
		auto p = v.find(add); p--;
		if(p->nd.st < add.nd.st) {// to insert
		
			auto p = v.find(add); p++;
			while(p != v.end() && p->nd.st <= add.nd.st) {
				v.erase(p);
				p = v.find(add); p++;
			}

		} else 
			v.erase(add);
	}
}

vector <pair <pair<int, int>, int > > v1, v2;

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		if(a[i] > b[i])
			v1.push_back({{a[i], b[i]}, i});
		else  {
			b[i] = 2 * n + 1 - b[i];
			a[i] = 2 * n + 1 - a[i];
			v2.push_back({{a[i], b[i]}, i});
		}
	}

	cout << max(v1.size(), v2.size()) << '\n';

	if(v1.size() > v2.size()) {
		sort(v1.begin(), v1.end());
		// reverse(v1.begin(), v1.end());
		for(auto i : v1) cout << i.nd << ' ';
	}
	else {
		sort(v2.begin(), v2.end());
		// reverse(v2.begin(), v2.end());
		for(auto i : v2) cout << i.nd << ' ';
	}

}