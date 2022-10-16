#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << '\n'; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, deque <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out  << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
int n, d[N];

vector <pair<int, int> > ans, v;

void add(int x, int y) {
	ans.push_back({x, y});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)  {
		cin >> d[i];
		v.push_back({d[i], 2 * i - 1});
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());


	deque <int> chain;
	for(auto i : v) {
		if(!chain.empty()) add(chain.back(), i.nd);
		chain.push_back(i.nd);
	}

	// dbg(chain);

	for(auto i : v) {
		int dist = i.st;
		add(i.nd + 1, chain[dist - 1]);
		if(dist == chain.size())
			chain.push_back(i.nd + 1);
		chain.pop_front();
	}
	cout << ans << '\n';
}